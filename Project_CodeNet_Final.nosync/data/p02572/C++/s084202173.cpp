#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int inf = 1000000000;

int main(){
    ll n;
    cin >> n;
    ll a[n];
    ll sum = 0;
    ll ans = 0;
    rep(i,n){
        cin >> a[i];
        sum += a[i];
    }
    rep(i,n){
        ll b = a[i]%ll(1e9+7);
        sum -= a[i];
        ll c = sum%ll(1e9+7);
        ans += (b*c)%ll(1e9+7);
        ans %= ll(1e9+7);
    }
    cout << ans << endl;
}