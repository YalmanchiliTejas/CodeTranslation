#include <bits/stdc++.h>
#include <cstdint>
#include <sys/time.h>

typedef std::int_fast32_t  s32;
typedef std::uint_fast32_t u32;
typedef std::int_fast64_t  s64;
typedef std::uint_fast64_t u64;

int main(void) {

  for(;;) {
    int N, A, B, C, X;
    std::cin >> N >> A >> B >> C >> X;
    if( N == 0 and A == 0 and B == 0 and C == 0 and X == 0 ) break;

    int Y[128];
    for(int i = 0; i < N; ++i) {
      std::cin >> Y[i];
    }

    int R[16384];
    R[0] = X;
    for(int i = 1; i < 10010; ++i) {
      R[i] = (A * R[i - 1] + B) % C;
    }

    int i;
    int p = 0;
    for(i = 0; i < N; ++i) {
      for(; p <= 10100; ++p) {
        if( Y[i] == R[p] ) {
          p += 1;
          break;
        }
      }
    }
    p -= 1;
    std::cout << (p <= 10000 ? p : -1) << std::endl;
  }
  
  return 0;
}