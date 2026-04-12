#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define ll long long
#define pb push_back
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007
#define pb push_back
ll pwr(ll a, ll b){
    if(b == 0)
        return 1 ;
    ll c = pwr(a, b/2) ;
    c = c * c;
    if(b % 2)
        return c*a;
    return c ;
}
ll pwr(ll a, ll b, ll m){
    if(b == 0)
        return 1;
    ll c = pwr(a, b/2, m) % m ;
    c = (c * c) % m;    
    if(b % 2)
        return (c * a%m) % m;
    return c ;
}

int main(){
    #ifndef ONLINE_JUDGE    
    freopen("../../input", "r", stdin);
    freopen("../../output", "w", stdout);
    #else
    // online submission
    #endif

    boost
    int tt = 1;
    // cout << 0 << endl;
    // cin >> tt;
    while(tt--){
        ll n;
        cin >> n;
        ll a[n];
        for(int i = 0; i < n; i++) cin >> a[i];
        // in(a, n);
        ll ans = 0;
        ll sum[n] = {0};
        for(int i = n - 2; i >= 0; i--){
            sum[i] = (sum[i + 1] + a[i + 1]) % MOD;
            sum[i] %= MOD;
            ans += (sum[i] * a[i]) % MOD;
            ans %= MOD;
        }
        cout << ans;
    }
}
