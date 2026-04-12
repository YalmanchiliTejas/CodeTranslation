#include "bits/stdc++.h"
#include "math.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
typedef vector<pair<ll,ll> > vp;
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
const int INF=1e9+7;

int main(){
  ll n,k,ans=0;cin>>n>>k;
  rep(i,k+1,n+1){//b
    ll tmp1=n/i,tmp2=n%i;
    ans+=(i-k)*tmp1;
    if(tmp2>=k){
      ans+=tmp2-k+1;
    }
    if(k==0){ans--;}
  }
  cout<<ans<<endl;
}
