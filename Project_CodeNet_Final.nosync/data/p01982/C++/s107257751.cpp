#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ll n,l,r;
    while(cin>>n>>l>>r and n>0 and l>0 and r>0){
        ll ans=0;
        vector<ll> A(n);
        for(auto &&e:A)
            cin>>e;
        for(ll x=l; x<=r; ++x){
            ll i;
            for(i=0; i<n; ++i){
                if(x%A[i]==0){
                    if((i+1)%2==1){
                        ++ans;
                    }
                    break;
                }
            }
            if(i==n){
                if(n%2==0){
                    ++ans;
                }
            }
        }
        cout<<ans<<endl;
    }
}
