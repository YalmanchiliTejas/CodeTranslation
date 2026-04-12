#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
typedef long long ll;
typedef long double lb;
#define int long long
#define double long double
typedef pair<int,int> P;
const int MOD = 1000000007;
const ll INF = 1e16;
const double EPS = 1e-10;
const double PI = 3.141592653589793;
template<class T> inline bool chmin(T& a, T b){if(a>b){a = b;return 1;}return 0;}
template<class T> inline bool chmax(T& a, T b){if(a<b){a = b;return 1;}return 0;}
const pair<int,int> fd[] = {make_pair(1,0),make_pair(-1,0),make_pair(0,1),make_pair(0,-1)}; 


////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////
string ss;int d, n;vector<int> s;
int dp[11000][2][100];
signed main(){
  cin>>ss>>d;n = ss.length();s.resize(n);
  rep(i,n)s[i] = (int)(ss[i] - '0');
  dp[0][1][s[0]%d] = 1;
  rep(i,10)if(i < s[0])dp[0][0][i%d] += 1;
  repd(i,1,n){
    rep(j,d){
      rep(k,10){
        dp[i][0][j] = (dp[i][0][j] + dp[i-1][0][(j+d*10-k)%d])%MOD;
        if(k < s[i])dp[i][0][j] = (dp[i][0][j] + dp[i-1][1][(j+d*10-k)%d])%MOD;
        if(k == s[i])dp[i][1][j] = (dp[i][1][j] + dp[i-1][1][(j+d*10-k)%d])%MOD;
      }
    }
  }
  cout << ((dp[n-1][0][0] + dp[n-1][1][0])%MOD + MOD -1)%MOD << endl;
}
