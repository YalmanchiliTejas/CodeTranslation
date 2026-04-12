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

int lreval(string s) {
    int val = s[0] - '0';
    for (int i = 1; i < s.length(); i += 2) {
        if (s[i] == '+') {
            val = val + (s[i + 1] - '0');
        } else {
            val = val * (s[i + 1] - '0');
        }
    }
    return val;
}

int creval(string s) {
    int ttl = 0, cur = s[0] - '0';
    for (int i = 1; i < s.length(); i += 2) {
        if (s[i] == '*') {
            cur *= (s[i + 1] - '0');
        } else {
            ttl += cur;
            cur = s[i + 1] - '0';
        }
    }
    ttl += cur;
    return ttl;
}

int main() {
    char mask[] = {'I', 'L', 'M', 'U'};
    string s; cin >> s;
    int m = 0, v; cin >> v;
    // cout << lreval(s) << " " << creval(s) << endl;
    if (lreval(s) == v) m |= 1;
    if (creval(s) == v) m |= 2;
    cout << mask[m] << endl;
}
