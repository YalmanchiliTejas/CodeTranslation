#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const ll mod = 1e9+7;

int n;

void solve(){
    cin >> n;
    ll s=0,ans=0;
    for(int i=0;i<n;++i) {
        ll t;
        cin >> t;
        ans += (t * s)%mod , ans%=mod;
        s += t%mod , s%=mod;
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    while(t--)
        solve();
    return  0;
}
