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

const ll mod = 1000000007;
struct Mod {
    ll x;
    Mod(): x(0) {}
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

vector<ll> v;
ll dp[200005][3];
ll ninf = -0x3f3f3f3f3f3f3f3fll;

int main() {
    // cin.sync_with_stdio(0); cin.tie(0); cin.exceptions(cin.failbit);

    int n; cin >> n;
    v = vector<ll>(n);

    rep(i, 0, n) cin >> v[i];
    
    rep(i, 0, n) rep(j, 0, 3) dp[i][j] = ninf;

    if (n % 2 == 0) {
        dp[0][0] = ninf;
        dp[0][1] = v[0];
        dp[1][0] = v[1];
        dp[1][1] = ninf;

        rep(i, 2, n) {
            dp[i][0] = v[i] + max(dp[i - 2][0], i - 3 >= 0 ? dp[i - 3][1] : ninf);
            dp[i][1] = v[i] + dp[i - 2][1];
        }
    
        cout << max(dp[n - 1][0], dp[n - 2][1]) << endl;
    } else if (n % 2 == 1) {
        dp[0][0] = dp[0][1] = ninf; dp[0][2] = v[0];
        dp[1][0] = dp[1][2] = ninf; dp[1][1] = v[1];
        dp[2][1] = ninf; dp[2][2] = v[0] + v[2]; dp[2][0] = v[2];

        rep(i, 3, n) {
            dp[i][0] = v[i] + max(dp[i - 2][0], max(
                i - 3 >= 0 ? dp[i - 3][1] : ninf, i - 4 >= 0 ? dp[i - 4][2] : ninf));
            dp[i][1] = v[i] + max(dp[i - 2][1], i - 3 >= 0 ? dp[i - 3][2] : ninf);
            dp[i][2] = v[i] + dp[i - 2][2];
        }

        // printf("%4c%23lld%23lld%23lld\n", ' ', 0ll, 1ll, 2ll);

        // rep(i, 0, n) {
        //     printf("%3d:%23lld%23lld%23lld\n", i, dp[i][0], dp[i][1], dp[i][2]);
        // }

        cout << max(dp[n - 1][0], max(dp[n - 2][1], dp[n - 3][2])) << endl;
    }
}