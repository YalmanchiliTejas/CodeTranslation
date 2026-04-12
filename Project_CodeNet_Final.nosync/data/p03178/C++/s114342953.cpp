#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b)-1; i >= (a); --i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fst first
#define snd second

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<pii> vii;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  string k;
  int d;
  cin >> k >> d;
  int n = sz(k);

  const ll mod = 1e9+7;
  vector<vvl> dp(n+1, vvl(d, vl(2, 0)));
  dp[0][0][0] = 1;

  rep(i,0,n) {
    rep(j,0,d) {
      rep(o,0,2) {
        rep(l,0,10) {
          if (not o and l > k[i]-'0') break;
          int s = o;
          if (l < k[i]-'0') s=1;
          dp[i+1][(j+l)%d][s] += dp[i][j][o];
          dp[i+1][(j+l)%d][s] %= mod;
        }
      }
    }
  }

  cout << (accumulate(all(dp[n][0]), 0LL)-1+mod)%mod << '\n';
}