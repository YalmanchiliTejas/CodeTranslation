#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<ll,ll,ll> T;
const long long INF = 1LL<<60;
const int MOD = 1000000000+7;
#define rev(s) (string((s).rbegin(), (s).rend()))
template < typename T > inline string toString( const T &a ) { ostringstream oss; oss << a; return oss.str(); };
// cout << fixed << setprecision(10) << ans << endl;
// *min_element(c + l, c + r) *max_element(c + l, c + r)
// int dx[8]={1,1,0,-1,-1,-1,0,1};
// int dy[8]={0,1,1,1,0,-1,-1,-1};
// int dx[4]={1,0,-1,0};
// int dy[4]={0,1,0,-1};
// struct Edge {
//   int to, id;
//   Edge(int to, int id): to(to), id(id) {}
// };

vector<ll> a;

ll dp[3010][3010][2];

ll rec(int l, int r, int ord) {
  if(dp[l][r][ord] != -1) return dp[l][r][ord];
  if(ord == 0) {
    if(l == r) return dp[l][r][ord] = a[l];
    return dp[l][r][ord] = max(a[l] + rec(l + 1, r, 1), a[r] + rec(l, r - 1, 1));
  } else {
    if(l == r) return dp[l][r][ord] = -a[l];
    return dp[l][r][ord] = min(rec(l + 1, r, 0) - a[l], rec(l, r - 1, 0) - a[r]);
  }
}

int main() {
  int N; cin >> N;
  a = vector<ll>(N);
  rep(i, N) cin >> a[i];
  rep(i, N + 1) {
    rep(j, N + 1) {
      rep(k, 2) dp[i][j][k] = -1;
    } 
  }
  ll ans = rec(0, N - 1, 0);
  cout << ans << endl;
}