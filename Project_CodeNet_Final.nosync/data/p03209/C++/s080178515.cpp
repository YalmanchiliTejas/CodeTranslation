#include <cmath>
#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, long long> height;
unordered_map<int, long long> pate;

long long f(int N, long long X) {
  if (N == 0) {
    if (X <= 0)
      return 0;
    else
      return 1;
  } else if (X <= 1 + height[N - 1]) {
    return f(N - 1, X - 1);
  } else
    return pate[N - 1] + 1 + f(N - 1, X - 2 - height[N - 1]);
}

int main() {
  int N;
  long long X;
  cin >> N >> X;
  height[0] = 1LL;
  pate[0] = 1LL;
  for (int level = 1; level <= N; ++level) {
    height[level] = height[level - 1] * 2 + 3;
    pate[level] = pate[level - 1] * 2 + 1;
  }
  cout << f(N, X) << endl;
  return 0;
}
