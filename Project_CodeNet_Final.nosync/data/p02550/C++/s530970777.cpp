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
#define SIZE(a) ll((a).size())
#define out(a) cout<<(a)<<endl;
const int inf=INT_MAX;
const int MAX = 510000;
const ll MOD = 998244353;

int main(){
  ll n,m,x,ans=0;cin>>n>>x>>m;
  vll o(m,-1),v(0),syu(0);
  rep(i,0,n){
    if(o[x]!=-1){
      rep(j,o[x],i){syu.push_back(v[j]);}
      break;
    }
    o[x]=i;
    v.push_back(x);
    ans+=x;
    x=(x*x)%m;
  }
  n-=v.size();
  if(n==0){out(ans);return 0;}
  ll a=n%syu.size(),b=n/syu.size(),cnt=0;
  rep(i,0,syu.size()){
    cnt+=syu[i];
  }
  ans+=cnt*b;
  rep(i,0,a){ans+=syu[i];}
  out(ans);
}





