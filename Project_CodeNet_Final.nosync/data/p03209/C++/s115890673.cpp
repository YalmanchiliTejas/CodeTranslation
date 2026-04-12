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
ll roundd(ll x,ll n){
  if(x>n){return x%n;}
  else if(x<0){return x%n+n;}
  else return x;
}
vll kosuu(55,1);
ll dfs(ll n,ll x){
  if(n==0&&x==1){return 1;}
  if(x<=1){return 0;}
  else if(x==kosuu[n+1]-1){return kosuu[n];}
  else if(x==kosuu[n+2]-3){return kosuu[n+1]-1;}
  else{
    if(1<x&&x<kosuu[n+1]-1){
      return dfs(n-1,x-1);
    }
    else return dfs(n-1,x-kosuu[n+1]+1)+kosuu[n];
  }
}
int main(){
  ll n,x;cin>>n>>x;
  rep(i,1,55){
    kosuu[i]=kosuu[i-1]*2;
  }
  ll ans=dfs(n,x);
  cout<<ans<<endl;
}

