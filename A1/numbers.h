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
  printf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d", v.b7, v.b6, v.b5, v.b4, v.b3, v.b2,
         v.b1, v.b0);
}

struct bits8 bits8_add(struct bits8 x, struct bits8 y) {
  // store result
  struct bits8 result;

  // initizalize carry
  struct bit carry = bit_from_int(0);

  result.b0 = bit_xor(bit_xor(x.b0, y.b0), carry);
  carry     = bit_or(bit_and(x.b0, y.b0), bit_and(carry, bit_xor(x.b0, y.b0)));
  result.b1 = bit_xor(bit_xor(x.b1, y.b1), carry);
  carry     = bit_or(bit_and(x.b1, y.b1), bit_and(carry, bit_xor(x.b1, y.b1)));
  result.b2 = bit_xor(bit_xor(x.b2, y.b2), carry);
  carry     = bit_or(bit_and(x.b2, y.b2), bit_and(carry, bit_xor(x.b2, y.b2)));
  result.b3 = bit_xor(bit_xor(x.b3, y.b3), carry);
  carry     = bit_or(bit_and(x.b3, y.b3), bit_and(carry, bit_xor(x.b3, y.b3)));
  result.b4 = bit_xor(bit_xor(x.b4, y.b4), carry);
  carry     = bit_or(bit_and(x.b4, y.b4), bit_and(carry, bit_xor(x.b4, y.b4)));
  result.b5 = bit_xor(bit_xor(x.b5, y.b5), carry);
  carry     = bit_or(bit_and(x.b5, y.b5), bit_and(carry, bit_xor(x.b5, y.b5)));
  result.b6 = bit_xor(bit_xor(x.b6, y.b6), carry);
  carry     = bit_or(bit_and(x.b6, y.b6), bit_and(carry, bit_xor(x.b6, y.b6)));
  result.b7 = bit_xor(bit_xor(x.b7, y.b7), carry);
  carry     = bit_or(bit_and(x.b7, y.b7), bit_and(carry, bit_xor(x.b7, y.b7)));

  // return x and y sum
  return result;
}

struct bits8 bits8_negate(struct bits8 x) {
  struct bits8 result;
  result.b0 = bit_not(x.b0);
  result.b1 = bit_not(x.b1);
  result.b2 = bit_not(x.b2);
  result.b3 = bit_not(x.b3);
  result.b4 = bit_not(x.b4);
  result.b5 = bit_not(x.b5);
  result.b6 = bit_not(x.b6);
  result.b7 = bit_not(x.b7);
  return bits8_add(result, bits8_from_int(1));
}

struct bits8 bits8_mul(struct bits8 x, struct bits8 y);
