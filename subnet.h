#ifndef SUBNET_H
#define SUBNET_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Lit "172.16.10.2/24". Retourne 1 si valide, 0 sinon. */
int parse_cidr(const char *text, uint32_t *ip, int *prefix);

/* Convertit un prefixe (ex: 24) en masque (255.255.255.0). */
uint32_t prefix_to_mask(int prefix);

/* Ecrit l'adresse sous forme "a.b.c.d" (buffer >= 16 octets). */
void ip_to_string(uint32_t ip, char *buffer);

/* Nombre d'hotes utilisables pour un prefixe donne. */
uint32_t usable_hosts(int prefix);

#ifdef __cplusplus
}
#endif

#endif