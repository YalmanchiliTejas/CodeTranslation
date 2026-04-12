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

ll dp[200010][4];

int main() {
  int N;cin>>N;
  vector<ll> a(N);
  rep(i,N) {
    cin>>a[i];
  }
  int extra = 1 + (N % 2);
  rep(i,N+1) rep(j,extra+1) dp[i][j] = -INF;
  dp[0][0] = 0;
  rep(i,N) {
    rep(j,extra+1) {
      chmax(dp[i+1][j+1],dp[i][j]);
      ll now = dp[i][j];
      if((i+j)%2==0) now += a[i];
      chmax(dp[i+1][j],now);
    }
  }
  cout << dp[N][extra] << endl;
} 