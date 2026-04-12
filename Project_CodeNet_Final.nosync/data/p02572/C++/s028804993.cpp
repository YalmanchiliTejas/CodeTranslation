#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
const ll mod = 1e9+7;

int main(void)
{
    ll n, ans=0, sum=0;
    cin >> n;
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
        sum += a[i];
    }
    rep(i,n){
        sum -= a[i];
        ans += sum%mod*a[i];
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}