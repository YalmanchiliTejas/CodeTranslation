#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const ll Mod = 998244353;
const int MAX = 510000;
const double PI = 3.14159265358979;
const vector<int> dx = {1, 0};
const vector<int> dy = {0, 1};

// 負の数にも対応した%演算
ll mod(ll val, ll m) {
  ll res = val%m;
  if (res<0) res += m;
  return res;
}

int main() {
  int N;
  cin >> N;
  vector<ll> A(N);
  for (int i=0; i<N; i++) cin >> A[i];
  // (A[0]+A[1]+...+A[N-1])%MOD
  ll sum = 0;
  for (int i=0; i<N; i++) {
    sum += A[i];
    sum %= MOD;
  }
  ll res = 0;
  for (int i=0; i<N-1; i++) {
    sum = mod(sum%MOD-A[i]%MOD, MOD);
    res += A[i]*sum%MOD;
    res %= MOD;
  }
  cout << res%MOD << endl;
  return 0;
}