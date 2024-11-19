#include "bits.h"
#include <stdint.h>

struct bits8 {
  struct bit b0; // Least significant bit
  struct bit b1;
  struct bit b2;
  struct bit b3;
  struct bit b4;
  struct bit b5;
  struct bit b6;
  struct bit b7;
};

// helper functions:

// returns bit i from int x. E.g. get_bit(2,1) == 1, get_bit(2,0) == 0.
// use right-shifting (>>) ad masking (&1)
unsigned int get_bit(unsigned int x, int i) { return (x >> i) & 1; }

// returns x but with the bit at position i set to 1. E.G. set_bit(2,0) == 3,
// set_bit(2,1) == 2. using left-shifting (<<) and bitwise-or (|)
unsigned int set_bit(unsigned int x, int i) { return x | (1 << i); }

struct bits8 bits8_from_int(unsigned int x) {
  struct bits8 b;
  b.b0 = bit_from_int(get_bit(x, 0));
  b.b1 = bit_from_int(get_bit(x, 1));
  b.b2 = bit_from_int(get_bit(x, 2));
  b.b3 = bit_from_int(get_bit(x, 3));
  b.b4 = bit_from_int(get_bit(x, 4));
  b.b5 = bit_from_int(get_bit(x, 5));
  b.b6 = bit_from_int(get_bit(x, 6));
  b.b7 = bit_from_int(get_bit(x, 7));
  return b;
}

unsigned int bits8_to_int(struct bits8 x) {
  unsigned int result = 0;
  result              = set_bit(result, 0) * bit_to_int(x.b0);
  result              = set_bit(result, 1) * bit_to_int(x.b1);
  result              = set_bit(result, 2) * bit_to_int(x.b2);
  result              = set_bit(result, 3) * bit_to_int(x.b3);
  result              = set_bit(result, 4) * bit_to_int(x.b4);
  result              = set_bit(result, 5) * bit_to_int(x.b5);
  result              = set_bit(result, 6) * bit_to_int(x.b6);
  result              = set_bit(result, 7) * bit_to_int(x.b7);
  return result;
}

void bits8_print(struct bits8 v) {
  printf("%d%d%d%d%d%d%d%d", v.b7, v.b6, v.b5, v.b4, v.b3, v.b2, v.b1, v.b0);
}

struct bits8 bits8_add(struct bits8 x, struct bits8 y) {}

struct bits8 bits8_negate(struct bits8 x);
struct bits8 bits8_mul(struct bits8 x, struct bits8 y);
