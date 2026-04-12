#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; ++i)
const ll INF = LLONG_MAX;
const ll MOD = 1e9 + 7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<ll> x(n),a(n);
    rep(i, n)
    {
        cin >> x[i];
        a[i] = x[i];
    }
    sort(a.begin(), a.end());
    rep(i, n){
        if (x[i] <= a[n/2-1]) {
            cout << a[n / 2] << endl;
        } else {
            cout << a[n / 2 - 1] << endl;
            ;
        }
    }
    return 0;
}