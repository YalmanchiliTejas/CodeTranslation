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
const int MOD = 1000000007;
const int MAX = 510000;

int main(){
  ll a,b,c,x,y;cin>>a>>b>>c>>x>>y;
  ll ans=a*x+b*y;
  while(x>0||y>0){
    ll tmp;
    if(x>0&&y>0)tmp=ans-(a+b)+c*2;
    else{
      if(x>0)tmp=ans-a+c*2;
      if(y>0)tmp=ans-b+c*2;
    }
    x--;y--;
    ans=min(ans,tmp);
  }
  cout<<ans<<endl;
}

