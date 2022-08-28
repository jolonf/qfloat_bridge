
typedef struct {
  long long a;
  long long b;
} QFloat;

typedef struct {
  QFloat real;
  QFloat imag;
} QComplex;


// Conversions

extern QFloat to_qfloati(int n);
extern QFloat to_qfloatl(long long n);
extern QFloat to_qfloatf(float n);
extern QFloat to_qfloatd(double n);
extern int to_int(QFloat q);
extern float to_float(QFloat q);
extern double to_double(QFloat q);

// Arithmetic

extern QFloat addqf(QFloat a, QFloat b);
extern QFloat subqf(QFloat a, QFloat b);
extern QFloat mulqf(QFloat a, QFloat b);
extern QFloat divqf(QFloat a, QFloat b);
extern QFloat negqf(QFloat n);

// Comparisons

int ltqf(QFloat a, QFloat b);
int gtqf(QFloat a, QFloat b);

// libquadmath

extern QFloat acosqf (QFloat);
extern QFloat acoshqf (QFloat);
extern QFloat asinqf (QFloat);
extern QFloat asinhqf (QFloat);
extern QFloat atanqf (QFloat);
extern QFloat atanhqf (QFloat);
extern QFloat atan2qf (QFloat, QFloat);
extern QFloat cbrtqf (QFloat);
extern QFloat ceilqf (QFloat);
extern QFloat copysignqf (QFloat, QFloat);
extern QFloat coshqf (QFloat);
extern QFloat cosqf (QFloat);
extern QFloat erfqf (QFloat);
extern QFloat erfcqf (QFloat);
extern QFloat exp2qf (QFloat);
extern QFloat expqf (QFloat);
extern QFloat expm1qf (QFloat);
extern QFloat fabsqf (QFloat);
extern QFloat fdimqf (QFloat, QFloat);
extern int finiteqf (QFloat);
extern QFloat floorqf (QFloat);
extern QFloat fmaqf (QFloat, QFloat, QFloat);
extern QFloat fmaxqf (QFloat, QFloat);
extern QFloat fminqf (QFloat, QFloat);
extern QFloat fmodqf (QFloat, QFloat);
//extern QFloat frexpqf (QFloat, int *);
extern QFloat hypotqf (QFloat, QFloat);
extern int isinfqf (QFloat);
extern int ilogbqf (QFloat);
extern int isnanqf (QFloat);
extern int issignalingqf (QFloat);
extern QFloat j0qf (QFloat);
extern QFloat j1qf (QFloat);
//extern QFloat jnqf (int, QFloat);
//extern QFloat ldexpqf (QFloat, int);
extern QFloat lgammaqf (QFloat);
extern long long int llrintqf (QFloat);
extern long long int llroundqf (QFloat);
extern QFloat logbqf (QFloat);
extern QFloat logqf (QFloat);
extern QFloat log10qf (QFloat);
extern QFloat log2qf (QFloat);
extern QFloat log1pqf (QFloat);
extern long int lrintqf (QFloat);
extern long int lroundqf (QFloat);
extern QFloat modfqf (QFloat, QFloat *);
//extern QFloat nanqf (const char *);
extern QFloat nearbyintqf (QFloat);
extern QFloat nextafterqf (QFloat, QFloat);
extern QFloat powqf (QFloat, QFloat);
extern QFloat remainderqf (QFloat, QFloat);
//extern QFloat remquoqf (QFloat, QFloat, int *);
extern QFloat rintqf (QFloat);
extern QFloat roundqf (QFloat);
//extern QFloat scalblnqf (QFloat, long int);
//extern QFloat scalbnqf (QFloat, int);
extern int signbitqf (QFloat);
//extern void sincosqf (QFloat, QFloat *, QFloat *);
extern QFloat sinhqf (QFloat);
extern QFloat sinqf (QFloat);
extern QFloat sqrtqf (QFloat);
extern QFloat tanqf (QFloat);
extern QFloat tanhqf (QFloat);
extern QFloat tgammaqf (QFloat);
extern QFloat truncqf (QFloat);
extern QFloat y0qf (QFloat);
extern QFloat y1qf (QFloat);
//extern QFloat ynqf (int, QFloat);

/* Prototypes for string <-> __float128 conversion functions */
extern QFloat strtoqfloat (const char *s);
extern int quadmath_snprintf (char *str, /*size_t*/ unsigned long size,
			      const char *format, ...);
