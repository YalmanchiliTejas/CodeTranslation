#include <bits/stdc++.h>

using namespace std;

#define SZ(x) (int)(x.size())

using ll = long long;
using ld = long double;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
const double eps = 1e-10;
const ll MOD = 1000000007;
const int INF = 1000000000;
const ll LINF = 1ll<<50;

template<typename T>
void printv(const vector<T>& s) {
  for(int i=0;i<(int)(s.size());++i) {
    cout << s[i];
    if(i == (int)(s.size())-1) cout << endl;
    else cout << " ";
  }
}

template<typename T1, typename T2>
ostream& operator<<(ostream &os, const pair<T1, T2> p) {
  os << p.first << ":" << p.second;
  return os;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  string k; cin >> k;
  int d; cin >> d;
  int sz = SZ(k);
  
  if(d == 1) {
    reverse(k.begin(), k.end());
    ll ans = 0;
    ll mul = 1;
    for(int i=0;i<sz;++i) {
      ans += mul * (k[i] - '0') % MOD;
      ans %= MOD;
      mul *= 10;
      mul %= MOD;
    }
    cout << ans << endl;
    return 0;
  }

  vvll dp(sz+1, vll(d, 0));
  for(int i=0;i<=9;++i) {
    dp[sz][i%d] += 1;
  }
  for(int i=sz-1;i>=0;--i) {
    for(int j=0;j<d;++j) {
      for(int k=0;k<=9;++k) {
        dp[i][(j+k)%d] += dp[i+1][j];
        dp[i][(j+k)%d] %= MOD;
      }
    }
  }

  vvll dp2(sz+1, vll(d, 0));
  for(int i=0;i<=k[sz-1]-'0';++i) {
    dp2[sz][i%d] += 1;
  }
  for(int i=sz-1;i>=1;--i) {
    int now = k[i-1] - '0';
    for(int j=0;j<now;++j) {
      for(int k=0;k<d;++k) {
        dp2[i][(j+k)%d] += dp[i+1][k];
        dp2[i][(j+k)%d] %= MOD;
      }
    }
    for(int k=0;k<d;++k) {
      dp2[i][(now+k)%d] += dp2[i+1][k];
      dp2[i][(now+k)%d] %= MOD;
    }
  }
  


  cout << (dp2[1][0] + MOD - 1) % MOD << endl;

}
