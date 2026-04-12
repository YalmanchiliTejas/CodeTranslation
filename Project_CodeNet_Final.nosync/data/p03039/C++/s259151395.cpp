#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppiii;

const int MOD = 1000000007;

ll fact[1000000];
ll ifact[1000000];

ll choose(int n, int k) {
  ll ret = fact[n];
  ret *= ifact[k];
  ret %= MOD;
  ret *= ifact[n-k];
  ret %= MOD;
  return ret;
}

ll modpow(ll b, ll e, ll m) {
  ll r = 1;
  while(e) {
    if(e%2) {
      r*=b;
      r%=m;
    }
    b*=b;
    b%=m;
    e/=2;
  }
  return r;
}
ll inv(ll b, ll m) {
  return modpow(b, m-2, m);
}

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  fact[0] = 1;
  for(int i = 1; i <= n*m; i++) {
    fact[i] = i * fact[i-1];
    fact[i] %= MOD;
  }
  ifact[n*m] = inv(fact[n*m], MOD);
  for(int i = n*m-1; i >= 0; i--) {
    ifact[i] = (i+1) * ifact[i+1];
    ifact[i] %= MOD;
  }
  ll ret = 0;
  for(int d = 1; d < n; d++) {
    ll inc = m;
    inc *= m;
    inc %= MOD;
    inc *= n-d;
    inc %= MOD;
    inc *= choose(n*m-2, k-2);
    inc %= MOD;
    inc *= d;
    inc %= MOD;
    ret += inc;
    ret %= MOD;
  }
  for(int d = 1; d < m; d++) {
    ll inc = n;
    inc *= n;
    inc %= MOD;
    inc *= m-d;
    inc %= MOD;
    inc *= choose(n*m-2, k-2);
    inc %= MOD;
    inc *= d;
    inc %= MOD;
    ret += inc;
    ret %= MOD;
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  /*
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  */
  solve();
}
