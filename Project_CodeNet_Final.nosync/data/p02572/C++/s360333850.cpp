#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n;
    cin >> n;
    vector<ll>a(n),sum(n+1,0);
    for(ll i=0;i<n;i++){
        cin >> a[i];
    }
    for(ll i=n;i>0;i--){
        sum[i-1]+=sum[i]+a[i-1];
        sum[i]%=MOD;
    }
    ll ans=0;
    for(ll i=0;i<n-1;i++){
        ans+=((a[i]*sum[i+1])%MOD);
        ans%=MOD;
    }
    cout << ans << endl;
}