# qfloat_bridge

Float128 quadmath support for clang on macOS ARM using the GCC quadmath library.

# Overview

The motivation for this library is the lack of extended precision (`double double` or `float80`) support on macOS ARM using clang (and Swift). GCC provides Float128 support on macOS ARM since GCC11. This library defines it's own `QFloat` type which is mapped in this library to GCC's `__float128` type and hence provides access to GCC's quadmath functions (as well as basic functionality like arithmetic and comparisons). Currently this library only supports ARM and not Intel. Most but not all of the functions in quadmath are supported. Complex numbers are not supported. This library has not been extensively tested and it shouldn't be assumed that results from this library are accurate.

# Build

To build the library you must install Homebrew's `gcc@12`:

```
brew install gcc@12
```

The `Makefile` will specifically call `gcc-12` (as the default `gcc` command will call clang instead).

The `Makefile` also uses an absolute path to Homebrew's `gcc@12` library folder to access the `libquadmath.a` and `libgcc.a` libraries which are statically linked into the final static library using `libtool`.

Build the library run `make` on the command line in the project's root directory:

```
make
```

This produces a `libqfloat_bridge.a` static library which can be linked into your application, the header file `qfloat_bridge.h` is the corresponding header file.

# Usage

See the `clang_test` subdirectory for an example project which uses the `libqfloat_bridge.a` static library.

The static library is completely self contained and contains both GCC's quadmath library and libgcc. There is no requirement for projects which use the built static library to have access to GCC or its quadmath library.

See the `qfloat_bridge.h` header file for function names as the QFloat variants have slightly different names to the `__float128` variants.

Example usage:

```c
#include <stdio.h>

#include "qfloat_bridge.h"

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
```
