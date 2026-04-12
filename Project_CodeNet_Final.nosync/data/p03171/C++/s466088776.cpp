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
constexpr char ln =  '\n';

const int mx=100010;
const ll mod=1e9+7;

vector<ll> a(3010,0);
vector<vector<ll>> dp(3010, vector<ll>(3010,-longinf));
int n;

ll rec(int l, int r){
  if(dp[l][r]!=-longinf) return dp[l][r];
  if(l==r) return dp[l][r] = a[l]*(n%2==1?1:-1);
  int t = n-(r-l+1); //0:taro 1:ziro
  ll tmp = longinf*(t%2==1?1:-1);
  if(t%2==0){
    tmp = max(tmp, a[l]+rec(l+1,r));
    tmp = max(tmp, a[r]+rec(l,r-1));
  } else {
    tmp = min(tmp, -a[l]+rec(l+1,r));
    tmp = min(tmp, -a[r]+rec(l,r-1));
  }
  return dp[l][r] = tmp;
}


int main(){
  
  cin >> n;
  rep(i,n){
    cin>>a[i];
  }
  ll ans = rec(0,n-1);

  cout << ans << ln;
  return 0;
}