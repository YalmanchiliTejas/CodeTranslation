#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0;i < n;i++){
        cin >> a[i];
    }
    ll sum = 0;
    for (ll i = 0; i < n; i++){
        sum += a[i];
        sum %= 1000000007LL;
    }
    ll ans = 0;
    for (ll i = 0; i < n; i++){
        sum -= a[i];
        if (sum < 0){
            sum += 1000000007LL;
        }
        ans += a[i]*sum;
        ans %= 1000000007LL;
    }

    cout << ans << endl;
}