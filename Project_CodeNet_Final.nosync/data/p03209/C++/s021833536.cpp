#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int N;
ll X;
ll len[51];
ll p[51];

ll P(int L, ll X) {
  if (L == 1) {
    if (X <= 4)
      return X - 1;
    else
      return 3;
  }
  if (X == 1) return 0;

  if (X <= len[L - 1] + 1) {
    return P(L - 1, X - 1);
  } else if (X > len[L - 1] + 2) {
    return P(L - 1, X - (len[L - 1] + 2)) + 1 + p[L - 1];
  } else if (X == len[L - 1] + 2) {
    return P(L - 1, X - 2) + 1;
  } else {
    // if (X == len[L])
    return len[L - 1] * 2 + 1;
  }
  return 0;
}

int main() {
  int N;
  cin >> N >> X;

  len[0] = 1, len[1] = 5;
  p[0] = 1, p[1] = 3;
  for (int i = 1; i <= 50; i++) {
    len[i] = len[i - 1] * 2 + 3;
    p[i] = 2 * p[i - 1] + 1;
  }

  cout << P(N, X) << endl;
  return 0;
}