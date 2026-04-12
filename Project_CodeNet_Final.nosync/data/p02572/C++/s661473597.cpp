#include<bits/stdc++.h>

using namespace std;
using ll = long long int;
using lc = complex<double>;

int main(void) {
    constexpr ll MOD = 1e9 + 7;
    constexpr double PI = acos(-1);
    cout << fixed << setprecision(32);
    cin.tie(0); ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    vector<ll> a(n);
    for(auto &e: a) cin >> e;
    vector<ll> b = a;

    for(ll i=1; i<n; i++)
        b[i] = (b[i-1] + a[i]) % MOD;

    ll res = 0;
    for(ll i=1; i<n; i++)
        (res += (b[i-1] * a[i]) % MOD) %= MOD;
    cout << res << endl;
}