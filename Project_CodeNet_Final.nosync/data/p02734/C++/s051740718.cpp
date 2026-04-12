#include <bits/stdc++.h>
using namespace std;

// region template
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define trav(a, x) for (auto &a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll gcd(ll a, ll b) { return __gcd(a, b); }

ll euclid(ll a, ll b, ll &x, ll &y) {
    if (b) { ll d = euclid(b, a % b, y, x);
        return y -= a/b * x, d; }
    return x = 1, y = 0, a;
}

typedef unsigned long long ull;
typedef long double ld;
ull mod_mul(ull a, ull b, ull M) {
    ll ret = a * b - M * ull(ld(a) * ld(b) / ld(M));
    return ret + M * (ret < 0) - M * (ret >= (ll)M);
}
ull mod_pow(ull b, ull e, ull mod) {
    ull ans = 1;
    for (; e; b = mod_mul(b, b, mod), e /= 2)
        if (e & 1) ans = mod_mul(ans, b, mod);
    return ans;
}

const ll mod = 998244353;
struct Mod {
    ll x;
    Mod(ll xx) : x(xx) {}
    Mod operator+(Mod b) { return Mod((x + b.x) % mod); }
    Mod operator-(Mod b) { return Mod((x - b.x) % mod); }
    Mod operator*(Mod b) { return Mod((x * b.x) % mod); }
    Mod operator/(Mod b) { return *this * invert(b); }
    Mod invert(Mod a) {
        ll x, y, g = euclid(a.x, mod, x, y);
        assert(g == 1); return Mod((x + mod) % mod);
    }
    Mod operator^(ll e) {
        if (!e) return Mod(1);
        Mod r = *this ^ (e / 2); r = r * r;
        return e & 1 ? *this * r : r;
    }
};
// endregion

int n, s;
vector<int> v;

int dpl[1505][3005], dpr[1505][3005];

ll dc(int l, int r) {
    if (l == r) {
        return v[l] == s;
    }

    int m = l + r >> 1;

    // dp left, dp right
    vector<int> vl, vr;
    vl.push_back(0);
    vr.push_back(0);
    for (int i = m; i >= l; i--) vl.push_back(v[i]);
    for (int i = m + 1; i <= r; i++) vr.push_back(v[i]);

    int sl = vl.size() - 1, sr = vr.size() - 1;

    rep(i, 0, max(vl.size(), vr.size()) + 1) rep(j, 0, 3005) dpl[i][j] = dpr[i][j] = 0;
    dpl[0][0] = dpr[0][0] = 1;

    rep(i, 1, vl.size()) {
        for (int j = s; j >= 0; j--) {
            dpl[i][j] = dpl[i - 1][j];
            if (j >= vl[i]) (dpl[i][j] += dpl[i - 1][j - vl[i]]) %= mod;
        }
    }
    rep(i, 1, vr.size()) {
        for (int j = s; j >= 0; j--) {
            dpr[i][j] = dpr[i - 1][j];
            if (j >= vr[i]) (dpr[i][j] += dpr[i - 1][j - vr[i]]) %= mod;
        }
    }

    vector<ll> wsl(s + 1), wsr(s + 1);

    wsl[0] += sl, wsr[0] += sr;

    for (int i = 1; i <= sl; i++) {
        for (int j = 0; j <= s; j++) {
            (wsl[j] += 1ll * (sl - i + 1) * (dpl[i][j] - dpl[i - 1][j] + mod)) %= mod;
        }
    }
    for (int i = 1; i <= sr; i++) {
        for (int j = 0; j <= s; j++) {
            (wsr[j] += 1ll * (sr - i + 1) * (dpr[i][j] - dpr[i - 1][j] + mod)) %= mod;
        }
    }

    ll ans = 0;
    for (int i = 0; i <= s; i++) {
        ans = (ans + 1ll * wsl[i] * wsr[s - i]) % mod;
    }

    return ((ans + dc(l, m) + dc(m + 1, r)) % mod + mod) % mod;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0); cin.exceptions(cin.failbit);

    cin >> n >> s;
    v.resize(n + 1);
    rep(i, 1, n + 1) cin >> v[i];
    cout << dc(1, n) << endl;
}