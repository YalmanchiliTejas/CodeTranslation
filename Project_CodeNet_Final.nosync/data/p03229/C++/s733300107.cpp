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
const ll MOD = 1000000007;


int main(){
  ll n;cin>>n;
  vll a(n);
  rep(i,0,n){
    cin>>a[i];
  }
  sort(a.begin(),a.end());
  reverse(a.begin(),a.end());
  if(n%2){
    ll ans=0,ans2=0;
    rep(i,0,n/2){
      ans+=a[i]*2;
    }
    ans-=(a[n/2]+a[n/2+1]);
    rep(i,n/2+2,n){
      ans-=(a[i]*2);
    }
    rep(i,0,n/2-1){
      ans2+=a[i]*2;
    }
    ans2+=a[n/2-1]+a[n/2];
    rep(i,n/2+1,n){ans2-=a[i]*2;}
    cout<<max(ans,ans2)<<endl;
  }
  else{
    ll ans=0;
    rep(i,0,n/2-1){
      ans+=a[i]*2;
    }
    ans+=a[n/2-1];
    ans-=a[n/2];
    rep(i,n/2+1,n){
      ans-=a[i]*2;
    }
    cout<<ans<<endl;
  }
}

