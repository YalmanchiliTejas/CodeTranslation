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

vector<vector<vector<ll>>> dp(10010, vector<vector<ll>>(2,vector<ll>(110,-1)));
//ll dp[10010][2][110];//dp[i][j][k]:uekara i keta j=ok? k= ketawa mod d
string s;
int d;

ll rec(int idx, int f, int x){
  if(dp[idx][f][x]!=-1){ return dp[idx][f][x]; }
  if(idx==s.size()){ return x==0; }
  ll ret=0;
  if(f){
    rep(i,10){ ret+=rec(idx+1, f, (x+i)%d); }
  } else {
    int m=s[idx]-'0';
    rep(i,m){ ret+=rec(idx+1, 1, (x+i)%d); }
    ret+=rec(idx+1, 0, (x+m)%d);
  }
  return dp[idx][f][x]=ret%mod;
}

int main(){
  cin >> s >> d;
  ll ans = (rec(0,0,0)+mod-1)%mod;  //-1 : including 0
  cout << ans << endl;
  return 0;
}