/* be name khoda */

#define long_enable
#include <iostream>
#include <algorithm>
#include <cstring>
#include <numeric>
#include <vector>
#include <fstream>
#include <set>
#include <map>
using namespace std;

#ifdef long_enable
typedef long long int ll;
#else
typedef int ll;
#endif

typedef pair<ll, ll> pii;
typedef pair<pii, ll> ppi;
typedef pair<ll, pii> pip;
typedef vector<ll> vi;
typedef vector<pii> vpii;

#define forifrom(i, s, n) for (ll i = s; i < n; ++i)
#define forirto(i, n, e) for (ll i = (n) - 1; i >= e; --i)
#define fori(i, n) forifrom (i, 0, n)
#define forir(i, n) forirto (i, n, 0)

#define F first
#define S second
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define smin(a, b) a = min(a, (b))
#define smax(a, b) a = max(a, (b))

#define debug(x) cout << #x << " -> " << (x) << endl
#define debug2(x, y) cout << #x << ' ' << #y << " -> " << (x) << ' ' << (y) << endl
#define debug3(x, y, z) cout << #x << ' ' << #y << ' ' << #z << " -> " << (x) << ' ' << (y) << ' ' << (z) << endl
#define debug4(x, y, z, t) cout << #x << ' ' << #y << ' ' << #z << ' ' << #t << " -> " << (x) << ' ' << (y) << ' ' << (z) << ' ' << (t) << endl
#define debuga(x, n) cout << #x << " -> "; fori (i1_da, n) { cout << (x)[i1_da] << ' '; } cout << endl
#define debugaa(x, n, m) cout << #x << " ->\n"; fori (i1_daa, n) { fori (i2_daa, m) { cout << (x)[i1_daa][i2_daa] << ' '; } cout << '\n'; } cout << endl

const ll MOD = 998244353;
const ll INF = 2000000000;
const long long BIG = 1446803456761533460LL;

#define XL (x << 1)
#define XR (XL | 1)
#define MD ((l + r) >> 1)
#define Add(a, b) a = ((a) + (b)) % MOD
#define Mul(a, b) a = (1LL * (a) * (b)) % MOD

// -----------------------------------------------------------------------

const ll maxn = 10000010;

ll n, pow2[maxn], fact[maxn], ifact[maxn];

/*
    change A and B in odd indices (now each A need an other letter for remove and the same for B)
    Condition: 
    Ca <= Cb + Cc (Ca <= n / 2)
    Cb <= Ca + Cc (Cb <= n / 2)
   */

ll poww(ll a, ll b) {
    ll r = 1;
    while (b) {
        if (b & 1) Mul(r, a);
        Mul(a, a);
        b >>= 1;
    }
    return r;
}

ll ent(ll a, ll b) {
    return fact[b] * ifact[a] % MOD * ifact[b - a] % MOD;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    // ifstream cin(".in");

    fact[0] = 1;
    fori (i, maxn - 1) fact[i + 1] = fact[i] * (i + 1) % MOD;
    ifact[maxn - 1] = poww(fact[maxn - 1], MOD - 2);
    forir (i, maxn - 1) ifact[i] = ifact[i + 1] * (i + 1) % MOD;
    pow2[0] = 1;
    fori (i, maxn - 1) pow2[i + 1] = pow2[i] * 2 % MOD;

    cin >> n;
    ll bad = 0;
    fori (i, n / 2) {
        Add(bad, ent(i, n) * pow2[i]);
    }
    ll ans = (poww(3, n) + (MOD - bad) * 2) % MOD;
    cout << ans << '\n';

}
