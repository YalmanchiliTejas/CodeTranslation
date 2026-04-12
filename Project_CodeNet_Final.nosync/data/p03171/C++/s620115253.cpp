#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(int i = a; i >= (b); --i)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()
#define int long long
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int N; cin >> N; vi v(N);
  for(int& i: v) cin >> i;
  vector<vi> dp(N, vi(N));
  rrep(l,N-1,0){
    rep(r,l,N){
      int d = N-l+r;
      if(d%2)
        dp[l][r] = max((l+1 > r ? 0 : dp[l+1][r]) + v[l], (r-1 < l ? 0 : dp[l][r-1]) + v[r]);
      else
        dp[l][r] = min((l+1 > r ? 0 : dp[l+1][r]) - v[l], (r-1 < l ? 0 : dp[l][r-1]) - v[r]);
    }
  }
  cout << dp[0][N-1];
  return 0;
}
