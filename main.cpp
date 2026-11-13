#include <iostream>
#include <string>
#include "subnet.h"

using namespace std;

// Classe C++ : stocke et affiche les resultats.
// Les calculs de base sont faits par les fonctions C (subnet.c).
class Subnet {
private:
    uint32_t ip;
    int prefix;
    uint32_t mask;
    uint32_t network;
    uint32_t broadcast;

public:
    Subnet(uint32_t ipAddress, int prefixLength)
        : ip(ipAddress), prefix(prefixLength)
    {
        mask = prefix_to_mask(prefix);
        network = ip & mask;
        broadcast = network | ~mask;
    }

    void display() const
    {
        char buf[16];
        uint32_t first = network + 1;
        uint32_t last = broadcast - 1;

        if (prefix == 31) { first = network; last = broadcast; }
        if (prefix == 32) { first = ip; last = ip; }

        cout << "\n--- Resultat ---\n";
        ip_to_string(ip, buf);        cout << "Adresse IP      : " << buf << "/" << prefix << "\n";
        ip_to_string(mask, buf);      cout << "Masque          : " << buf << "\n";
        ip_to_string(network, buf);   cout << "Adresse reseau  : " << buf << "\n";
        ip_to_string(broadcast, buf); cout << "Broadcast       : " << buf << "\n";
        ip_to_string(first, buf);     cout << "Premier hote    : " << buf << "\n";
        ip_to_string(last, buf);      cout << "Dernier hote    : " << buf << "\n";
        cout << "Hotes utilisables : " << usable_hosts(prefix) << "\n\n";
    }
};

int main()
{
    cout << "=== Calculatrice de sous-reseaux (C / C++) ===\n";
    cout << "Format : 172.16.10.2/24   (q pour quitter)\n";

    string line;
    while (true) {
        cout << "> ";
        if (!getline(cin, line) || line == "q")
            break;

        uint32_t ip;
        int prefix;
        if (!parse_cidr(line.c_str(), &ip, &prefix)) {
            cout << "Entree invalide. Exemple : 192.168.1.10/24\n";
            continue;
        }

        Subnet s(ip, prefix);
        s.display();
    }
    return 0;
}