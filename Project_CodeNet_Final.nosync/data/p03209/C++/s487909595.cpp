#include <bits/stdc++.h>
using namespace std;

long count(long n, long x, vector<long>& NL, vector<long>& M) {
  if (x <= 0) return 0;
  if (n == 0) return 1;
  if (M[n] != 0 && x == NL[n]) {
    return M[n];
  }

  long ans = 0, Lm1 = NL[n-1];
  if (x == 1) return 0; x--;
  if (Lm1 < x) {
    ans += count(n-1, Lm1, NL, M);
    x -= Lm1;
    M[n-1] = ans;
    ans++; x--;
    if (x == 0) return ans;
    x = min(x, Lm1);
    ans += count(n-1, x, NL, M);
  } else {
    ans += count(n-1, x, NL, M);
  }
  return ans;
}

int main() {
  long N, X;
  cin >> N >> X;
  vector<long> NL(51);
  NL[0] = 1;
  for (int i = 1; i <= 50; i++) {
    NL[i] = 3 + 2 * NL[i-1];
  }
  vector<long> M(51, 0);
  cout << count(N, X, NL, M) << endl;
}