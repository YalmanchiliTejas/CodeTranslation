#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const double eps = 1e-10;
const int MOD = 1000000007;
const int INF = 1000000000;
const ll LINF = 1ll<<50;

template<typename T>
void printv(const vector<T>& s) {
  for(int i=0;i<(int)(s.size());++i) {
    cout 
    << s[i];
    if(i == (int)(s.size())-1) cout << endl;
    else cout << " ";
  }
}

const int CMBMAX = 510000;
ll fac[CMBMAX], finv[CMBMAX], inv[CMBMAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(int i=2;i<CMBMAX;++i) {
        fac[i] = fac[i-1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD;
        finv[i] = finv[i-1] * inv[i] % MOD;
    }
}

ll COM(int n, int k) {
    if(n < k) return 0;
    if(n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n-k] % MOD) % MOD;
}

int main() {
    cin.tie(0);
    cout << fixed << setprecision(10);


    ll n, m, k; cin >> n >> m >> k;
    COMinit();

    ll sumx = 0;
    for(int i=1;i<n;++i) {
      ll tmp = m * m % MOD;
      tmp *= n - i;
      tmp %= MOD;
      sumx += i * tmp;
      sumx %= MOD;
    }
    sumx *= COM(n * m - 2, k - 2);

    ll sumy = 0;
    for(int i=1;i<m;++i) {
      ll tmp = n * n % MOD;
      tmp *= m - i;
      tmp %= MOD;
      sumy += i * tmp;
      sumy %= MOD;
    }
    sumy *= COM(n * m - 2, k - 2);

    cout << (sumx + sumy) % MOD << endl;
}