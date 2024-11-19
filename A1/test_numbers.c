#include "numbers.h"
#include <stdlib.h>

int main() {
  // bits8_from_int(2) should produce a value with b1 set to 1 and everything
  // else to 0.
  struct bits8 b = bits8_from_int(2);
  if (b.b0.v || !b.b1.v || b.b2.v || b.b3.v || b.b4.v || b.b5.v || b.b6.v ||
      b.b7.v) {
    exit(1);
  }

  // bits8_to_int(bits8_from_int(x)) == x for values of x that fit in 8 bits.
  unsigned int x;
  for (x = 0; x < 256; x++) {
    if (bits8_to_int(bits8_from_int(x)) != x) {
      exit(1);
    }
  }

  // bits_8print() to help debugging.
  bits8_print(bits8_from_int(0));
  bits8_print(bits8_from_int(1));
  bits8_print(bits8_from_int(2));

  // bits8_print(bits8_from_int(123)) should print 01111011.
  bits8_print(bits8_from_int(123));

  // edge cases
  bits8_print(bits8_from_int(255));
  bits8_print(bits8_from_int(0));
}
