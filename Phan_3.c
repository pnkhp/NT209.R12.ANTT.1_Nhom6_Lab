#include <stdio.h>

unsigned float_negate(unsigned uf) {
    unsigned exp  = (uf >> 23) & 0xFF;
    unsigned frac = uf & 0x7FFFFF;
    if (exp == 0xFF && frac != 0)
        return uf;
    return uf ^ 0x80000000;
}

unsigned float_absval(unsigned uf) {
    unsigned exp  = (uf >> 23) & 0xFF;
    unsigned frac = uf & 0x7FFFFF;
    if (exp == 0xFF && frac != 0)
        return uf;
    return uf & 0x7FFFFFFF;
}

unsigned float_twice(unsigned uf) {
    unsigned sign = uf & 0x80000000;
    unsigned exp  = (uf >> 23) & 0xFF;

    if (exp == 0xFF)
        return uf;

    if (exp == 0)
        return sign | ((uf & 0x7FFFFFFF) << 1);

    exp = exp + 1;
    if (exp == 0xFF)
        return sign | 0x7F800000;
    return sign | (exp << 23) | (uf & 0x7FFFFF);
}
