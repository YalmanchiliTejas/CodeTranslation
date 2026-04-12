#include<bits/stdc++.h>
#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define print(x) cout << (x) << endl;
#define printa(x, n) for(ll i = 0; i < n; i++) {cout << (x[i]) << " ";} cout << endl;
using namespace std;
using ll = long long;

int main(void) {
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep (i, n) cin >> a[i];

    sort(a.rbegin(), a.rend());


    ll ans1 = 0;
    ll ans2 = 0;
    if (n % 2 == 0) {
        for (int i = 0; i < n / 2 - 1; i++) {
            ans1 += a[i] * 2LL;
        }
        for (int i = 0; i < n / 2 - 1; i++) {
            ans1 -= a[n - 1 - i] * 2LL;
        }
        ans1 += a[n / 2 - 1];
        ans1 -= a[n / 2];
        cout << ans1 << endl;
    }
    else {
        for (int i = 0; i < n / 2; i++) {
            ans1 -= a[n - 1 - i] * 2LL;
        }
        for (int i = 0; i < n / 2 - 1; i++) {
            ans1 += a[i] * 2LL;
        }
        ans1 += a[n / 2 - 1];
        ans1 += a[n / 2];

        for (int i = 0; i < n / 2; i++) {
            ans2 += a[i] * 2LL;
        }
        for (int i = 0; i < n / 2 - 1; i++) {
            ans2 -= a[n - 1 - i] * 2LL;
        }
        ans2 -= a[n / 2 + 1];
        ans2 -= a[n / 2];
        cout << max(ans1, ans2) << endl;
    }
    
    return 0;
}