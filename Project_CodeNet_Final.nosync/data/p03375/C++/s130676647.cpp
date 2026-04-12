#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int MOD;
struct modnum {
    int v;
    modnum() : v(0) {}
    modnum(ll _v) : v(_v % MOD) { if (v < 0) v += MOD; }
    explicit operator int() const { return v; }
    friend istream& operator >> (istream& i, modnum& n) { ll v; i >> v; n = modnum(v); return i; }
    friend ostream& operator << (ostream& o, const modnum& n) { return o << n.v; }

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

    static modnum fact(int n) {
        static vector<modnum> fact = { 1 };
        while (fact.size() <= n)
            fact.push_back(fact.back() * fact.size());
        return fact[n];
    }
    static modnum ncr(int n, int r) {
        if (r < 0 || n < r) return 0;
        return fact(n) / (fact(r) * fact(n - r));
    }
};
using mn = modnum;
using vmn = vector<mn>;
using vvmn = vector<vmn>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N >> MOD;

    vvmn part(N + 3, vmn(N + 3));
    part[0][0] = 1;
    for (int e = 1; e <= N + 1; e++) {
        for (int p = 1; p <= N + 1; p++) {
            part[e][p] = part[e-1][p-1] + part[e-1][p] * p;
        }
    }

    MOD--;
    int power = mn(2).pow(N).v;
    MOD++;

    mn ans = mn(2).pow(power);
    for (int bad = 1; bad <= N; bad++) {
        mn tot = 0;
        mn wt = 1, incr = mn(2).pow(N - bad);
        for (int grp = 1; grp <= bad + 1; grp++) {
            tot += part[bad + 1][grp] * wt;
            wt *= incr;
        }

        MOD--;
        int power2 = mn(2).pow(N - bad).v;
        MOD++;
        mn rem = mn(2).pow(power2);

        if (bad&1) ans -= mn::ncr(N, bad) * tot * rem;
        else ans += mn::ncr(N, bad) * tot * rem;
    }
    cout << ans << endl;

    return 0;
}

