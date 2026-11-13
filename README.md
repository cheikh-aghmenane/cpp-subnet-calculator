Calculatrice de sous-réseaux (C / C++)

Programme en ligne de commande qui calcule les informations d'un sous-réseau IPv4 à partir d'une adresse au format CIDR (ex. 172.16.10.2/24).

Fonctionnalités

	•	Adresse réseau et adresse de broadcast
	•	Masque de sous-réseau
	•	Premier et dernier hôte utilisables
	•	Nombre d'hôtes utilisables
	•	Gestion des cas particuliers /31 (lien point à point) et /32 (hôte unique)
	•	Vérification de la validité de l'entrée

Répartition des langages

Fichier	Langage	Rôle
subnet.h	C / C++	Déclaration des fonctions (compatible C++ via extern "C")
subnet.c	C	Calculs bas niveau : analyse de l'adresse, masque, opérations sur les bits
main.cpp	C++	Classe Subnet, affichage et interaction avec l'utilisateur

Compilation

Avec GCC (MinGW sous Windows) :

gcc -c subnet.c -o subnet.o
g++ main.cpp subnet.o -o subnet

Exécution :

./subnet        (Linux / macOS)
subnet.exe      (Windows)

Exemple

> 172.16.10.2/24

--- Resultat ---
Adresse IP      : 172.16.10.2/24
Masque          : 255.255.255.0
Adresse reseau  : 172.16.10.0
Broadcast       : 172.16.10.255
Premier hote    : 172.16.10.1
Dernier hote    : 172.16.10.254
Hotes utilisables : 254

Principe de calcul

	•	Masque = les n premiers bits à 1 (0xFFFFFFFF << (32 - n))
	•	Adresse réseau = IP & masque
	•	Broadcast = réseau | ~masque
	•	Hôtes utilisables = 2^(32 - n) - 2

Compétences mises en œuvre

	•	Programmation en C et en C++
	•	Opérations bit à bit
	•	Programmation orientée objet (classe Subnet)
	•	Interopérabilité C / C++ (extern "C")
	•	Compilation séparée
	•	Notions de réseaux IPv4 et de subnetting

Pistes d'amélioration

	•	Découpage d'un réseau en plusieurs sous-réseaux (VLSM)
	•	Saisie du masque au format 255.255.255.0
	•	Affichage binaire des adresses
## Captures d'ecran
## 1. Resultat de l'execution
![Resultat de l'execution](./execution-result.png)
## 2. Code principal
![Main Code](./main-code.png)
