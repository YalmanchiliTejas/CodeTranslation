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
 
const int mx=200010;
const ll mod=1e9+7;

vector<vector<vector<ll>>> dp(3030, vector<vector<ll>>(3030, vector<ll>(2,longinf)));
vector<ll> a(3030);
int n;

ld rec(int x, int y, int idx){
  if(dp[x][y][idx]!=longinf){ return dp[x][y][idx]; }
  if(x==y){ if(idx){return a[x];}else{ return -a[x];}}
  if(idx){ return dp[x][y][idx] = max(a[x]+rec(x+1,y,1-idx), a[y]+rec(x,y-1,1-idx)); }
    else { return dp[x][y][idx] = min(-a[x]+rec(x+1,y,1-idx), -a[y]+rec(x,y-1,1-idx)); }
}

int main(){  
  cin >> n;
  rep(i,n){ cin >> a[i]; }

  ll ans=rec(0,n-1,1);
  cout << ans << endl;
  return 0;
}