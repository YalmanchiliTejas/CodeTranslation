#include <bits/stdc++.h>
#define pb push_back
#define pll pair <ll, ll>
#define mp make_pair
#define pyshnapyshnakaa ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define x first
#define y second
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
#define plll pair <pair <ll, ll>, ll>
#define pllll pair <pair <ll, ll>, pair <ll, ll> >
#define psl pair <string, ll>
#define all(a) a.begin(), a.end()

typedef long long ll;

typedef long double ld;

using namespace std;

const ll maxn = 1e7;
const ll mod = 998244353;

ll n, m, k, t;

ll st2[maxn];

ll F[maxn];

ll RF[maxn];

inline ll step(ll a, ll x) {
    if (x == 0) {
        return 1;
    }
    if (x % 2 == 1) {
        return step(a, x - 1) * a % mod;
    }
    ll t = step(a, x / 2);
    return t * t % mod;
}

inline ll del(ll a, ll b) {
    return a * step(b, mod - 2) % mod;  
}

inline ll getc(ll n, ll k) {
    return F[n] * RF[k] % mod * RF[n - k] % mod;
}

inline ll wrong(ll a1) {
    // ll mul = st2[n / 2 - a1];
    ll goal = n / 2 - a1 + 1;
    // cout << "GOAL " << goal << endl;
    ll sum = getc(n / 2, goal) * st2[n / 2 - goal] % mod;
    // cout << "SUM " << " " << sum << endl;
    ll ans = sum;
    // cout << "WRONG " << a1 << " " << ans << endl << endl;;
    return ans;
}

int main() {
    pyshnapyshnakaa;
    ll q, w, e, a, b, c;
    F[0] = RF[0] = 1;
    for (q = 1; q < maxn; q++) {
        F[q] = F[q - 1] * q % mod;
    }
    RF[maxn - 1] = del(1, F[maxn - 1]);
    for (q = maxn - 2; q >= 0; q--) {
        RF[q] = RF[q + 1] * (q + 1) % mod;
    }
    cin >> n;
    st2[0] = 1;
    for (q = 1; q < maxn; q++) {
          st2[q] = st2[q - 1] * 2 % mod;
    }
    ll ans = step(3, n);
    ll dans = 0;
    ll cursum = 0;
    for (q = 1; q <= n / 2; q++) {
        ll ddans = wrong(q);
        ll mul = st2[n / 2 - q] * getc(n / 2, q) % mod;
        cursum += ddans;
        cursum %= mod;
        dans += cursum * mul % mod;
        // cout << "CURSUM mul " << cursum << " " << mul << endl << endl;; 
        dans %= mod;
    }
    // cout << dans << " DANS" << endl;
    ans = (ans - 2 * dans + mod * 4) % mod;
    cout << ans;
    return 0;
}