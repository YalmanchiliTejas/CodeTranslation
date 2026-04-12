#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
typedef long long ll;
typedef long double lb;
typedef pair<int,int> P;
const int MOD = 1000000007;
const ll INF = 1e16;
const double EPS = 1e-10;
const double PI = 3.141592653589793;
template<class T> inline bool chmin(T& a, T b){if(a>b){a = b;return 1;}return 0;}
template<class T> inline bool chmax(T& a, T b){if(a<b){a = b;return 1;}return 0;}
const pair<int,int> fd[] = {make_pair(1,0),make_pair(-1,0),make_pair(0,1),make_pair(0,-1)}; 
#define int long long
#define double long double

////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////

int n,k,m[110];
int dp[110][5][2];
signed main(){
  string s;cin>>s;int k;cin>>k;
  rep(i,s.length()){
    m[i] = (int)(s[i] - '0');
  }
  n = s.length();
  rep(i,110)rep(j,5)rep(l,2)dp[i][j][l] = 0;
  dp[0][0][0] = 1;
  rep(i,n+1){
    rep(j,k+1){
      dp[i+1][j][0] += dp[i][j][0]*(int)(m[i] == 0);
      dp[i+1][j+1][0] += dp[i][j][0]*(m[i] != 0);
      
      dp[i+1][j][1] += dp[i][j][0]*(m[i] > 0);
      dp[i+1][j+1][1] += dp[i][j][0]*max(0LL,(m[i]-1));
      dp[i+1][j][1] += dp[i][j][1];
      dp[i+1][j+1][1] += dp[i][j][1] * 9;      
    }
  }

  cout << dp[n][k][0] + dp[n][k][1] << endl;
}


