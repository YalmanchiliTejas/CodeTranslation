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

int main() {
  string K;
  int D;
  cin >> K >> D;
  int N = K.size();
  ll dp[N + 10][D][2];
  rep(i, N + 1)rep(j, D)rep(k, 2) dp[i][j][k] = 0;
  dp[0][0][1] = 1;
  rep(i, N) {
    int now = K[i] - '0';
    rep(j, D) {
      // 1 to 1
      dp[i + 1][(j + now) % D][1] += dp[i][j][1];
      dp[i + 1][(j + now) % D][1] %= MOD;

      // 1 to 0
      if(now != 0) {
	rep(k, now) {
	  dp[i + 1][(j + k) % D][0] += dp[i][j][1];
	  dp[i + 1][(j + k) % D][0] %= MOD;
	}
      }

      // 0 to 0
      rep(k, 10) {
	dp[i + 1][(j + k) % D][0] += dp[i][j][0];
	dp[i + 1][(j + k) % D][0] %= MOD;
      } 
    }
  }
  cout << (dp[N][0][0] + dp[N][0][1] - 1  + MOD) % MOD << endl;
}