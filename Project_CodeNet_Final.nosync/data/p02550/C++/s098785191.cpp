#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;
#define rep(i,n) for(ll i=0;i<(ll)n;++i)

signed main(){

  ll n,x,m;
  cin>>n>>x>>m;

  ll ans = 0;
  set<ll> st;
  for(ll i=0;i<n;++i){
    st.emplace(x);
    ans += x;
    x = x*x%m;

    if(st.find(x)!=st.end()){
      ll val = x;
      ll looplen = 0;
      ll loopgain = 0;
      do{
        loopgain += val;
        val = val*val%m;
        looplen++;
      }while(val!=x);
      ans += (n-i-1)/(looplen)*loopgain;
      ll len = (n-i-1)%looplen;
      rep(j,len){
        ans += x;
        x = x*x%m;
      }
      break;
    }
  }
  cout<<(ans)<<endl;

}