#include <iostream>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <vector>

#define rep(i, s, N) for(int i = s; i < N; i++)
#define YesNo(result) do {if (result) std::cout << "Yes" << '\n'; else std::cout << "No" << '\n';} while(0)
#define resetarr(arr, val) for(int i = 0; i < sizeof(arr) / 4; i++){ arr[i] = val; }

int main(int argc, char const *argv[]) {
  int A,B,C,X,Y;
  std::cin >> A >> B >> C >> X >> Y;
  long long int each = 0;
  each = A * X + B * Y;
  long long int aa = C * X * 2 + ((Y-X) > 0 ? (Y-X):0) * B;
  long long int bb = C * Y * 2 + ((X-Y) > 0 ? (X-Y):0) * A;
  std::cout << std::min(each, std::min(aa, bb)) << '\n';
  return 0;
}
