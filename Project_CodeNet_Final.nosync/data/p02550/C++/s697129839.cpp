#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0;i < (int)(n);i++)

int main() {
  long long x, m, ls = 0, k = 0, j = 1, s, rest, n, S = 0;
  bool c = false;
  cin >> n >> x >> m;
  vector<int> A(m+5), f(m, 1);
  A[0] = x;
  x = x*x % m;
  while(f[x]) {
    A[j] = x;
    f[x] = 0;
    x = x*x % m;
    j++;
  }
  rep(i, j) {
    if(A[i] == x) {
      c = true;
      s = i;
    }
    if(c) {
      ls += A[i];
      k++;
    }
  }
  if(n <= s) {
    rep(i, n) S += A[i];
  } else {
    rep(i, s) S += A[i];
    S += ls * ((n-s) / k);
    rest = n - s - ((n-s) / k) * k;
    rep(i, rest) S += A[s+i];
  }
  cout << S << endl;
}