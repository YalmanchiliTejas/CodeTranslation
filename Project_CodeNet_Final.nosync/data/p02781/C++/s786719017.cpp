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

ll dp[110][5][2];

int main(){
  string S;cin>>S;
  int K;cin>>K;
  int N = (int)S.size();
  dp[0][0][0] = 1;
  rep(i,N) {
    rep(j,5) {
      int now = S[i] - '0';
      // 0 to 0
      if(now == 0) {
	dp[i+1][j][0] += dp[i][j][0];
      } else {
	dp[i+1][min(j+1,4)][0] += dp[i][j][0];
      }

      // 0 to 1
      if(now > 0) {
	dp[i+1][j][1] += dp[i][j][0];
	dp[i+1][min(j+1,4)][1] += (now - 1) * dp[i][j][0];
      }

      // 1 to 1
      dp[i+1][min(j+1,4)][1] += 9 * dp[i][j][1];
      dp[i+1][j][1] += dp[i][j][1];
    }
  }
  cout<<dp[N][K][0] + dp[N][K][1]<<endl;
}