#include <stdio.h>

#include "../qfloat_bridge.h"

int main() {
  printf("clang_test\n");

  QFloat a = to_qfloatf(1.0);
  QFloat b = to_qfloatf(3.0);
  QFloat c = divqf(a, b);

  char s[255];

  quadmath_snprintf(s, 255, "%.60Qe", c);

  printf("q = %s\n", s);

  double d = to_double(c);

  printf("to double: %lf\n", d);
}