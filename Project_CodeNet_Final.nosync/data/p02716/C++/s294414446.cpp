#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b)-1; i >= (a); --i)
#define trav(a, x) for(auto& a : x)
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

  int n;
  cin >> n;
  const ll inf = 1e18;
  vvl dp(n+5, vl(2, -inf));
  vl a(n+5, -inf);
  rep(i,0,n) cin >> a[i];
  dp[0][0] = a[0];
  dp[1][0] = a[1];
  dp[1][1] = a[1];
  dp[2][1] = a[2];
  rep(i,0,n) {
    rep(j,0,2) {
      if (j and (n%2==0)) break;
      if (dp[i][j] == -inf) continue;
      ckmax(dp[i+2][j], dp[i][j]+a[i+2]);
      if (((i%2)^(j))==0) ckmax(dp[i+3][j], dp[i][j]+a[i+3]);
      if (j==0 and n%2==1) ckmax(dp[i+1][1], dp[i][j]);
    }
  }

  cout << max(*max_element(all(dp[n-2])), *max_element(all(dp[n-1]))) << '\n';
}