#include<iostream>
#include<vector>

using namespace std;
using ll = long long ;

int main(){
    ll n,k;
    cin>>n>>k;
    ll ans =0;
    for (ll i=k+1;i<=n;i++){
        ans +=((n-k)/i +1) * (i-k);
        if(n%i>=k){
            ans -= (i-1-n%i);
        }
    }
    if (k==0) ans -= n;
    cout<<ans<<endl;
}