#include "bits/stdc++.h"
#include "math.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
typedef pair<ll,ll> P;
typedef vector<P> vp;
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define drep(i,a,b) for(ll i=(a);i>=(b);--i)
#define SIZE(a) int((a).size())
#define out(a) cout<<(a)<<endl;
const int INF=INT_MAX;
const int MAX = 510000;
const ll MOD = 1000000007;
ll fac[MAX], finv[MAX], inv[MAX];

int main(){
  string n;ll k;cin>>n>>k;
  ll m=n.size();
  vvll dp0(m,vll(k+1,0)),dp1(m,vll(k+1,0));
  dp0[0][1]=n[0]-'0'-1;dp1[0][1]=1;
  dp0[0][0]=1;
  rep(i,1,m){
    dp0[i][0]=dp0[i-1][0];
    if(n[i]!='0'){
      rep(j,1,k+1){
        dp0[i][j]=9*dp0[i-1][j-1]+dp0[i-1][j]+dp1[i-1][j]+dp1[i-1][j-1]*(n[i]-'0'-1);
        dp1[i][j]=dp1[i-1][j-1];
      }
    }
    else {
      rep(j,1,k+1){
        dp0[i][j]=9*dp0[i-1][j-1]+dp0[i-1][j];
        dp1[i][j]=dp1[i-1][j];
      }
    }
  }
  cout<<dp0[m-1][k]+dp1[m-1][k]<<endl;
}
