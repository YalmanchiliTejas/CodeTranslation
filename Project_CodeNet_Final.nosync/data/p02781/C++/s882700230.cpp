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
//ll dp[10010][2][110];//dp[i][j][k]:uekara i keta j:1=ok k= used not0
string s;
int d;

int main(){
  cin >> s >> d;
  int sz=s.size();
  dp[0][0][0]=1;
  for(int idx=0; idx<sz; idx++)rep(k,d+1)rep(j,2){	//j==1 ok j==0 ??
    int maxi=(int)(s[idx]-'0');
    rep(l,10){						//next number
      if(j==0&&maxi<l){ continue; }
      dp[idx+1][j|(l<maxi)][k+(l>0)] += dp[idx][j][k];
    }
  }
  ll ans = dp[sz][0][d]+dp[sz][1][d];  
  cout << ans << endl;
  return 0;
}