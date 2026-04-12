#include <bits/stdc++.h>
#define mod 1000000007
using ll = long long;
using namespace std; 

int main(){
    ll n; cin >> n;
    vector<ll> A(n);
    ll ans=0;
    ll sum=0;
    for (ll i=0;i<n;i++){
        cin >> A[i];
        sum+=A[i];
        sum=sum%mod;
    }
    for (ll i=0;i<n-1;i++){
        sum=sum-A[i];
        if (sum<0){
            sum=mod+sum;
        }
        ans+=A[i]*sum;
        ans=ans%mod;
    }
    cout << ans%mod << "\n";
}














