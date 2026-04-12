#include<bits/stdc++.h>
using namespace std;
# define ll long long 
#define for(a,b) for(auto i=(a);i<(b);i++) 
int main(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    ll sum =0,modo = 1e9 + 7;
    for(0,n){
        cin>>a[i];
        sum += a[i];
        sum %= modo;
    }
    ll ans =0;
    for(0,n){
        sum -= a[i];
        if(sum < 0){
            sum += modo;
        }
        ans += a[i]*sum;
        ans %= modo;
    }
    cout<<ans;
    return 0;
}