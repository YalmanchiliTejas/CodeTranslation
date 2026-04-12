#include <bits/stdc++.h>
using namespace std;

#define TRACE(x)
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<int MOD> struct modnum {
    int v;
    modnum() : v(0) {}
    modnum(ll _v) : v(_v % MOD) { if (v < 0) v += MOD; }
    explicit operator int() const { return v; }
    friend ostream& operator << (ostream& o, const modnum& n) { return o << n.v; }
    friend istream& operator << (istream& i, modnum& n) { ll v; i >> v; n = modnum(v); return i; }

    friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
    friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }

    modnum& operator += (const modnum& o) { v += o.v; if (v >= MOD) v -= MOD; return *this; }
    modnum& operator -= (const modnum& o) { v -= o.v; if (v < 0) v += MOD; return *this; }
    modnum& operator *= (const modnum& o) { v = int(ll(v) * ll(o.v) % MOD); return *this; }
    modnum operator - () { modnum res; if (v) res.v = MOD - v; return res; }
    friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
    friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
    friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }

    modnum pow(int e) const {
        if (e == 0) return 1;
        if (e & 1) return *this * this->pow(e-1);
        return (*this * *this).pow(e/2);
    }

    modnum inv() const {
        int g = MOD, x = 0, y = 1;
        for (int r = v; r != 0; ) {
            int q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        }

        assert(g == 1);
        assert(y == MOD || y == -MOD);
        return x < 0 ? x + MOD : x;
    }
    modnum& operator /= (const modnum& o) { return (*this) *= o.inv(); }
    friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= modnum(b); }
};
using mn = modnum<1000000007>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M;
    cin >> N >> M;

    string str;
    cin >> str;

    bool mono = true;
    for (int i = 1; i < M; i++)
        mono &= str[i] == str[0];

    if (mono) {
        vector<mn> dp(N + 1);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 3;
        for (int l = 3; l <= N; l++) {
            dp[l] = dp[l-2] + dp[l-1];
        }
        cout << dp.back() << endl;
        return 0;
    }

    if (N&1) {
        cout << 0 << endl;
        return 0;
    }

    int t = str.size() - 1;
    while (str[t] == str[0])
        t--;
    str = str.substr(0, t + 1);
    M = str.size();

    int begin = -1, limit = INT_MAX;
    for (int i = 0; i < M; i++) {
        if (str[i] == str[0]) {
            if (begin == -1) begin = i;
        } else {
            if (begin != -1) {
                int len = i - begin;
                if (begin == 0) {
                    if (len&1) limit = min(limit, len);
                    else limit = min(limit, len + 1);
                } else if (len&1) {
                    limit = min(limit, len);
                }
            }
            begin = -1;
        }
    }

    WATCH(limit);

    vector<mn> ways(N + 1), pref(N + 1);
    ways[0] = 1, pref[0] = 0;
    for (int ln = 1; ln <= N; ln++) {
        if (ln % 2 == 0)
            ways[ln] = pref[ln - 1] - pref[max(0, ln - 1 - limit)];
        pref[ln] = pref[ln-1] + ways[ln-1];
    }

    WATCHC(ways);

    mn ans = 0;
    for (int fs = 2; fs <= limit + 1; fs += 2) {
        WATCH(fs);
        WATCH(ways[N - fs]);
        ans += fs * ways[N - fs];
    }
    cout << ans << endl;

    return 0;
}

