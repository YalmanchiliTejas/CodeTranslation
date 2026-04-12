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

typedef vector<vi> board;

board decode(string s) {
    board b;
    b.push_back({});
    for (char c : s) {
        if (isdigit(c)) {
            rep(i, 0, c - '0') b.back().push_back(0);
        } else if (c == '/') {
            b.push_back({});
        } else {
            b.back().push_back(1);
        }
    }
    return b;
}

string encode(board b) {
    string res;
    for (int i = 0; i < b.size(); i++) {
        if (i) res.push_back('/');
        int len = 0;
        for (int j = 0; j < b[i].size(); j++) {
            if (b[i][j] == 1) {
                if (len) {
                    res.push_back('0' + len);
                }
                res.push_back('b');
                len = 0;
            } else {
                len++;
            }
        }
        if (len) res.push_back('0' + len);
    }
    return res;
}

int main() {
    for (;;) {
        string s; cin >> s; if (s == "#") break;
        board b = decode(s);
        // for (auto p : b) {
        //     cout << "[" << p.size() << "] ";
        //     for (auto q : p) cout << q << " "; cout << endl;
        // }
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        --x1, --y1, --x2, --y2;
        b[x1][y1] = 0, b[x2][y2] = 1;
        cout << encode(b) << endl;
    }
}
