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
const ld eps = 1e-9;
const ll MOD = 998244353;
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

  ll n, s; cin >> n >> s;
  vll a(n);
  for(int i=0;i<n;++i) {
    cin >> a[i];
  }

  vll dp(s+1);
  ll ans = 0;
  for(int i=0;i<n;++i) {
    for(int j=s;j-a[i]>=0;--j) {
      dp[j] += dp[j-a[i]];
      dp[j] %= MOD;
    }
    if(a[i] <= s) dp[a[i]] += i+1;
    dp[a[i]] %= MOD;
    ans += dp[s];
    ans %= MOD;
  }
  cout << ans << endl;

}
