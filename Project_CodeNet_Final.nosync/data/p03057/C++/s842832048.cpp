#include <bits/stdc++.h>
#define pb push_back
#define pll pair <ll, ll>
#define mp make_pair
#define pyshnapyshnakaa ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define x first
#define y second
#pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
#define plll pair <pair <ll, ll>, ll>
#define pllll pair <pair <ll, ll>, pair <ll, ll> >
#define psl pair <string, ll>
#define pld pair <ld, ld>
#define all(a) a.begin(), a.end()
#define vvl vector <vector <ll> >
#define cld complex <double>

typedef long long ll;

typedef long double ld;

using namespace std;

const ll maxn = 3e5;
const ll mod = 1e9 + 7;

ll n, m, k, t;

string s;

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

ll simple() {
    vector <ll> D(n + 1);
    D[0] = 1;
    ll q;
    for (q = 1; q < n; q++) {
        D[q] += D[q - 1];
        if (q >= 2) {
            D[q] += D[q - 2];
            D[q] %= mod;
        }
    }
    return (D[n - 2] * 2 + D[n - 1]) % mod;
    // if (n % 2 == 1) {
    //     return 
    // }
    // return step(2, n / 2 + 1);
}

int main() {
    pyshnapyshnakaa
    ll q, w, e, a, b, c;
    cin >> n >> m;
    cin >> s;
    if (s[0] == 'B') {
        for (q = 0; q < s.length(); q++) {
            if (s[q] == 'R') {
                s[q] = 'B';
            }
            else {
                s[q] = 'R';
            }
        }
    }
    vector <pll> A;
    A.pb(mp(1, s[0]));
    for (q = 1; q < s.length(); q++) {
        if (s[q] == A.back().second) {
            A.back().first++;
        }
        else {
            A.pb(mp(1, s[q]));
        }
    }
    // cout << "FALL" << endl;
    bool blue = 0; /*kill = 0;*/
    ll mx = maxn;
    // cout << ""
    for (q = 0; q < A.size(); q++) {
        if (A[q].second == 'B') {
            blue = 1;
        }
        else {
            if ((q == 0 || A[q].first % 2 == 1) && q != A.size() - 1) {
                // cout << q << endl;
                mx = min(mx, A[q].first + 1 - A[q].first % 2);
            }
        }
    }
    // cout << mx;
    // return 0;
    // cout << "MX " << mx << endl;
    // if (fail) {
    //     cout << 0;
    //     return 0;
    // }
    if (!blue) {
        cout << simple();
        return 0;
    }
    // ll mx = maxn, cur = 0;
    // for (q = 0; q < s.length(); q++) {
    //     if (s[q] == 'B') {
    //         if (cur % 2 == 1) {
    //             mx = min(mx, cur);
    //         }
    //         else {
    //             mx = min(mx, cur + 1);
    //         }
    //         cur = 0;
    //     }
    //     else {
    //         cur++;
    //     }
    // }
    vector <ll> S(2);
    vector <ll> D(n + 1);
    D[0] = 1;
    S[0] = 1;
    for (q = 1; q < n; q++) {
        D[q] = S[q % 2];
        S[q % 2] = (S[q % 2] + D[q]) % mod;
        ll deli = q - mx - 1;
        if (deli >= 0) {
            // cout << "DELETING " << q << endl;
            S[deli % 2] = (S[deli % 2] - D[deli] + mod) % mod;
        }
        // cout << q << " " << D[q] << endl;
    }
    // cout << "mx " << mx << endl;
    ll ans = 0;
    for (q = 0; q < n; q++) {
        ll len = n - q - 1;
        if (len % 2 == 0 || len > mx) {
            continue;
        }
        ans += D[q] * (len + 1) % mod;
        ans %= mod;
    }
    cout << ans;
    return 0;
}