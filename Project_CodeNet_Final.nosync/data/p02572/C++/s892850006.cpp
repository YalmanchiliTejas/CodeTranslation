#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll MOD = (ll)1e9+7;
int n;

int main(){
    cin >> n;
    ll a[n]; for(int i=0; i<n; i++) cin >> a[i];
    ll ans = 0LL;
    for(int i=0; i<n; i++){
        ans += a[i];
        ans %= MOD;
    }
    ans *= ans; ans %= MOD;
    for(int i=0; i<n; i++){
        ans -= (a[i]*a[i])%MOD;
        ans %= MOD; ans += MOD; ans %= MOD;
    }
    if(ans%2==0) ans/=2;
    else ans = (ans+MOD)/2;
    ans %= MOD;
    cout << ans << endl;
}
