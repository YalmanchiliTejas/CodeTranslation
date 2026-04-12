#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

int main() {
  ll n;
  cin>>n;
  vector<ll> s(n);
  rep(i,n){
    cin>>s[i];
  }
  ll ans=0;
  ll l,r,t;
  //直接飛ぶとき０
  for(ll c=1;c<n;c++){
    l=0;r=n-1;t=0;
    if(r%c==0){
      while(l<r){
        t+=s[l]+s[r];
        ans=max(ans,t);
        l+=c;r-=c;
      }
    }
    else{
      while(r>c){
        t+=s[l]+s[r];
        ans=max(ans,t);
        l+=c;r-=c;
      }
    }
  }
    cout<<ans;

}
