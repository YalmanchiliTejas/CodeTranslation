#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second
 
#define bit(n,k) ((n>>k)&1) //*n no k bit me 1 or 0*/

const int mx=100010;
const ll mod=1e9+7;

vector<vector<vector<ll>>> dp(110, vector<vector<ll>>(2,vector<ll>(5,0)));
//ll dp[10010][2][110];//dp[i][j][k]:uekara i keta j=ok? k= used not0
string s;
int d;

int main(){
  cin >> s >> d;
  int sz=s.size();
  dp[0][0][0]=1;
  dp[1][0][0]=1;						//0
  dp[1][0][1]=(int)(s[0]-'0')-1;		//1~max-1
  dp[1][1][1]=1;						//max
  for(int idx=1; idx<sz; idx++)rep(k,d+1){				//i==0 ok i==1 ??
      dp[idx+1][0][k+1] += dp[idx][0][k]*9;		//use 1~9
      dp[idx+1][0][k] += dp[idx][0][k];			//use 0
      int maxi=(int)(s[idx]-'0');
      if(maxi!=0){ dp[idx+1][0][k+1] += dp[idx][1][k]*(maxi-1); } //use 1~max-1 to safe
      if(maxi!=0){ dp[idx+1][1][k+1] += dp[idx][1][k];}			//use max      
      else{ dp[idx+1][1][k] += dp[idx][1][k];}
      if(maxi!=0){ dp[idx+1][0][k] += dp[idx][1][k]; }			//use 0      
  }
  ll ans = dp[sz][0][d]+dp[sz][1][d];  
  cout << ans << endl;
  return 0;
}