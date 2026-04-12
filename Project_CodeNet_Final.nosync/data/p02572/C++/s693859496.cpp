#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;
const int mod = 1e9+7;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> s(n);
    s = a;
    ll ans = 0;
    for(int i = 1; i < n; ++i){
        s[i] += s[i-1];
        s[i]%=mod;
    }

    rep(i,n-1) {
        int j = s[n-1]-s[i];
        if(j<0) j+=mod;
        ll x = a[i]*j%mod;
        ans+=x;
        ans%=mod;
    }
    cout << ans << endl;
    return 0;
}