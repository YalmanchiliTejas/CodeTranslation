#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
    ll n;
    cin >> n;
    ll a[n];
    for(ll i=0;i<n;i++) cin >> a[i];
    ll mod=1e9+7;
    ll b[n];
    b[0]=1;
    b[n-1]=a[n-1];
    for(ll i=n-2;i>0;i--){
        b[i]=b[i+1]+a[i];
        b[i]%=mod;
    }
    ll res=0;
    for(ll i=0;i<n-1;i++){
        res+=(a[i]*b[i+1])%mod;
        res%=mod;
    }
    cout << res << endl;
}  
