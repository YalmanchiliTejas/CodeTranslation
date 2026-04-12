#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define pi 3.141592653589793
using namespace std;

ll comb(ll n, ll r) {
    ll num = 1, den = 1;
    for (ll i = 0; i < r; i++) {
        num *= (n - i);
        num %= mod;
        den *= (r - i);
        den %= mod;
    }

    ll power = mod - 2, x = den;
    ll ans = 1;
    while (power) {
        if (power % 2) {
            ans *= x;
            ans %= mod;
        }

        power /= 2;
        x = (x * x) % mod;
    }

    return (num * ans) % mod;

}


int main() {
//    cout << setprecision(30);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, m, k;
    cin >> n >> m >> k;
    ll ans = 0;
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            ans += ((i * (i - 1) / 2) * m) % mod;
            ans += ((j * (j - 1) / 2) * n) % mod;
            ans %= mod;
        }
    }

    cout << (ans * comb(n * m - 2, k - 2)) % mod;


}

