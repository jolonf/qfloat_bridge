
#include "qfloat_bridge.h"
#include <quadmath.h>

#define FROM_Q(q) (*((__float128 *) &(q)))
#define TO_Q(f) (*((QFloat *) &(f)))

// Conversions

QFloat to_qfloati(int n) {
  __float128 result = (__float128) n;

  return TO_Q(result);
}

QFloat to_qfloatl(long long n) {
  __float128 result = (__float128) n;

  return TO_Q(result);
}

QFloat to_qfloatf(float n) {
  __float128 result = (__float128) n;

  return TO_Q(result);
}

QFloat to_qfloatd(double n) {
  __float128 result = (__float128) n;

  return TO_Q(result);
}

int to_int(QFloat q) {
  __float128 n = FROM_Q(q);
  return (int) n;
}

float to_float(QFloat q) {
  __float128 n = FROM_Q(q);
  return (float) n;
}

double to_double(QFloat q) {
  __float128 n = FROM_Q(q);
  return (double) n;
}


// Arithmetic

QFloat addqf(QFloat a, QFloat b) {
  __float128 result = FROM_Q(a) + FROM_Q(b);
  return TO_Q(result);
}

QFloat subqf(QFloat a, QFloat b) {
  __float128 result = FROM_Q(a) - FROM_Q(b);
  return TO_Q(result);
}

QFloat mulqf(QFloat a, QFloat b) {
  __float128 result = FROM_Q(a) * FROM_Q(b);
  return TO_Q(result);
}

QFloat divqf(QFloat a, QFloat b) {
  __float128 result = FROM_Q(a) / FROM_Q(b);
  return TO_Q(result);
}

QFloat negqf(QFloat n) {
  __float128 result = -FROM_Q(n);
  return TO_Q(result);
}

// Comparisons

int ltqf(QFloat a, QFloat b) {
  return FROM_Q(a) < FROM_Q(b);
}

int gtqf(QFloat a, QFloat b) {
  return FROM_Q(a) > FROM_Q(b);
}

// libquadmath functions

#define QFUNCTION1(fname) \
QFloat fname##f (QFloat q) { \
  __float128 result = fname(FROM_Q(q)); \
  return TO_Q(result); \
}

#define QFUNCTION2(fname) \
QFloat fname##f (QFloat a, QFloat b) { \
  __float128 result = fname(FROM_Q(a), FROM_Q(b)); \
  return TO_Q(result); \
}

#define QFUNCTION3(fname) \
QFloat fname##f (QFloat a, QFloat b, QFloat c) { \
  __float128 result = fname(FROM_Q(a), FROM_Q(b), FROM_Q(c)); \
  return TO_Q(result); \
}

#define QFUNCTION_INT(fname) \
int fname##f (QFloat q) { \
  return fname(FROM_Q(q)); \
}

#define QFUNCTION_LONG_INT(fname) \
long int fname##f (QFloat q) { \
  return fname(FROM_Q(q)); \
}

#define QFUNCTION_LONG_LONG(fname) \
long long fname##f (QFloat q) { \
  return fname(FROM_Q(q)); \
}

// libquadmath

QFUNCTION1(acosq)
QFUNCTION1(acoshq)
QFUNCTION1(asinq)
QFUNCTION1(asinhq)
QFUNCTION1(atanq)
QFUNCTION1(atanhq)
QFUNCTION2(atan2q)
QFUNCTION1(cbrtq)
QFUNCTION1(ceilq)
QFUNCTION2(copysignq)
QFUNCTION1(coshq)
QFUNCTION1(cosq)
QFUNCTION1(erfq)
QFUNCTION1(erfcq)
QFUNCTION1(exp2q)
QFUNCTION1(expq)
QFUNCTION1(expm1q)
QFUNCTION1(fabsq)
QFUNCTION2(fdimq)
QFUNCTION_INT(finiteq)
QFUNCTION1(floorq)
QFUNCTION3(fmaq)
QFUNCTION2(fmaxq)
QFUNCTION2(fminq)
QFUNCTION2(fmodq)
//extern __float128 frexpq (__float128, int *) __quadmath_throw;
QFUNCTION2(hypotq)
QFUNCTION_INT(isinfq)
QFUNCTION_INT(ilogbq)
QFUNCTION_INT(isnanq)
QFUNCTION_INT(issignalingq)
QFUNCTION1(j0q)
QFUNCTION1(j1q)
//extern __float128 jnq (int, __float128) __quadmath_throw;
//extern __float128 ldexpq (__float128, int) __quadmath_throw;
QFUNCTION1(lgammaq)
QFUNCTION_LONG_LONG(llrintq)
QFUNCTION_LONG_LONG(llroundq)
QFUNCTION1(logbq)
QFUNCTION1(logq)
QFUNCTION1(log10q)
QFUNCTION1(log2q)
QFUNCTION1(log1pq)
QFUNCTION_LONG_INT(lrintq)
QFUNCTION_LONG_INT(lroundq)
//extern __float128 modfq (__float128, __float128 *) __quadmath_throw;
//extern __float128 nanq (const char *) __quadmath_throw;
QFUNCTION1(nearbyintq)
QFUNCTION2(nextafterq)
QFUNCTION2(powq)
QFUNCTION2(remainderq)
//extern __float128 remquoq (__float128, __float128, int *) __quadmath_throw;
QFUNCTION1(rintq)
QFUNCTION1(roundq)
//extern __float128 scalblnq (__float128, long int) __quadmath_throw;
//extern __float128 scalbnq (__float128, int) __quadmath_throw;
QFUNCTION_INT(signbitq)
//extern void sincosq (__float128, __float128 *, __float128 *) __quadmath_throw;
QFUNCTION1(sinhq)
QFUNCTION1(sinq)
QFUNCTION1(sqrtq)
QFUNCTION1(tanq)
QFUNCTION1(tanhq)
QFUNCTION1(tgammaq)
QFUNCTION1(truncq)
QFUNCTION1(y0q)
QFUNCTION1(y1q)
//extern __float128 ynq (int, __float128) __quadmath_throw;

/* Prototypes for string <-> __float128 conversion functions */
QFloat strtoqfloat (const char *s) {
  __float128 n = strtoflt128(s, NULL);

  return TO_Q(n);
}

