#define ll long long
#include <bits/stdc++.h>
using namespace std;
const ll m = 1e9 + 7;

ll iloczyn(ll a, ll b) {
    a %= m;
    b %= m;
    return (ll)((a * b) % m);
}
ll suma(ll a, ll b) {
    a %= m;
    b %= m;
    return (ll)((a + b) % m);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int  n;
    cin >> n;

    vector<int> a(n);

    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    ll ans = 0;
    ll prev = 0;
    for (int i = 0; i < n; i++) {
        ans = suma(ans, iloczyn(a[i], sum - a[i]));
        sum -= a[i];
    }
    cout << ans << "\n";

}

