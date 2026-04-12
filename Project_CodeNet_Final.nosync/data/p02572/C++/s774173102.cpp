#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
int main() {
    int n;
    cin>>n;
    ll a[n];
    for (int i=0;i<n;i++) {
        cin>>a[i];
    }
    
    
    ll b[n+1]{};
    for (int i=0;i<n;i++) {
        b[i+1]=(b[i]+a[i])%mod;
    }
    ll ans=0;
    for (int i = 0; i < n - 1; i++) {
        ans+=a[i]*(b[n]-b[i+1]+mod);
        ans%=mod;
    }
    cout<<ans<<"\n";
    return 0;
}