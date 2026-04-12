#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(k,i,n) for(ll i=k;i<n;++i)
int main(void){
    ll n;
    cin>>n;
    ll max0=0,h,ans=0;
    rep(0,i,n){
        cin>>h;
        max0=max(h,max0);
        if(max0==h)++ans;
    }
    cout<<ans<<endl;
}