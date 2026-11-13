#include <stdio.h>
#include "subnet.h"

int parse_cidr(const char *text, uint32_t *ip, int *prefix)
{
    unsigned int a, b, c, d;
    int p;

    if (sscanf(text, "%u.%u.%u.%u/%d", &a, &b, &c, &d, &p) != 5)
        return 0;
    if (a > 255 || b > 255 || c > 255 || d > 255)
        return 0;
    if (p < 0 || p > 32)
        return 0;

    *ip = (a << 24) | (b << 16) | (c << 8) | d;
    *prefix = p;
    return 1;
}

uint32_t prefix_to_mask(int prefix)
{
    if (prefix == 0)
        return 0;
    return 0xFFFFFFFFu << (32 - prefix);
}

void ip_to_string(uint32_t ip, char *buffer)
{
    sprintf(buffer, "%u.%u.%u.%u",
            (ip >> 24) & 0xFF, (ip >> 16) & 0xFF,
            (ip >> 8) & 0xFF, ip & 0xFF);
}

uint32_t usable_hosts(int prefix)
{
    if (prefix == 32)
        return 1;
    if (prefix == 31)
        return 2;
    return (uint32_t)((1ULL << (32 - prefix)) - 2);
}