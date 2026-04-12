#include <bits/stdc++.h>

using namespace std;

using ll = long long;
vector<ll> A;
vector<ll> P;

ll dfs(int n, ll x) {
  if (n == 0) return x;
  ll res = 0;
  if (x == 0) return res;
  x--;
  if (x <= A[n-1]) return res + dfs(n-1, x);
  res += P[n-1] + 1; x -= A[n-1] + 1;
  if (x <= A[n-1]) return res + dfs(n-1, x);
  return P[n];
}

int main() {
  int N;
  ll X;
  cin >> N >> X;
  A.resize(N+1, 1);
  P.resize(N+1, 1);
  for (int i = 1; i < N+1; i++) {
    A[i] = A[i-1] * 2 + 3;
    P[i] = P[i-1] * 2 + 1;
  }
  cout << dfs(N, X) << endl;
}
