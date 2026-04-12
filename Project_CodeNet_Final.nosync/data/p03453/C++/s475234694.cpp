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

template<int MOD> struct modnum {
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

    modnum pow(ll e) const {
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

    static int totient() {
        int tot = MOD, tmp = MOD;
        for (int p = 2; p * p <= tmp; p++) if (tmp % p == 0) {
            tot = tot / p * (p - 1);
            while (tmp % p == 0) tmp /= p;
        }
        if (tmp > 1) tot = tot / tmp * (tmp - 1);
        return tot;
    }

    static int primitive_root() {
        if (MOD == 1) return 0;
        if (MOD == 2) return 1;

        int tot = totient(), tmp = tot;
        vi tot_pr;
        for (int p = 2; p * p <= tmp; p++) if (tot % p == 0) {
            tot_pr.push_back(p);
            while (tmp % p == 0) tmp /= p;
        }
        if (tmp > 1) tot_pr.push_back(tmp);

        for (int r = 2; r < MOD; r++) if (__gcd(r, MOD) == 1) {
            bool root = true;
            for (int p : tot_pr) root &= modnum(r).pow(tot / p) != 1;
            if (root) return r;
        }
        assert(false);
    }

    static modnum generator() { static modnum g = primitive_root(); return g; }
    static int discrete_log(modnum v) {
        static const int M = ceil(sqrt(MOD));
        static unordered_map<int, int> table;
        if (table.empty()) {
            modnum e = 1;
            for (int i = 0; i < M; i++) { table[e.v] = i; e *= generator(); }
        }
        static modnum f = generator().pow(totient() - M);

        for (int i = 0; i < M; i++) {
            if (table.count(v.v)) return table[v.v] + i * M;
            v *= f;
        }
        assert(false);
    }

    static modnum fact(int n) {
        static vector<modnum<MOD>> fact = { 1 };
        while (fact.size() <= n)
            fact.push_back(fact.back() * fact.size());
        return fact[n];
    }

    static modnum ncr(int n, int r) {
        if (r < 0 || n < r) return 0;
        return fact(n) / (fact(r) * fact(n - r));
    }
};
using mn = modnum<int(1e9 + 7)>;

vector<pair<ll, mn>> calc(auto& adj, int r) {
    vector<pair<ll, mn>> res(sz(adj), { LLONG_MAX, 0 });
    res[r] = { 0, 1 };

    priority_queue<pair<ll, int>> dij; dij.push({ 0, r });
    while (!dij.empty()) {
        ll dist; int loc; tie(dist, loc) = dij.top(); dij.pop();
        for (auto e : adj[loc]) {
            ll tot = -dist + e.second;
            if (tot < res[e.first].first) {
                res[e.first] = { tot, 0 };
                dij.push({ -tot, e.first });
            }
            if (tot <= res[e.first].first) {
                res[e.first].second += res[loc].second;
            }
        }
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, S, T;
    cin >> N >> M >> S >> T;
    S--, T--;

    vector<vector<pair<int, int>>> adj(N);
    for (int i = 0, u, v, w; i < M; i++) {
        cin >> u >> v >> w;
        adj[u-1].emplace_back(v-1, w);
        adj[v-1].emplace_back(u-1, w);
    }

    auto s = calc(adj, S), t = calc(adj, T);

    mn ans = s[T].second * t[S].second;

    for (int i = 0; i < N; i++) {
        if (s[i].first == t[i].first &&
                s[i].first + t[i].first == s[T].first) {
            ans -= (s[i].second * t[i].second).pow(2);
        }
        for (auto e : adj[i]) {
            if (abs(s[i].first - t[e.first].first) < e.second
                    && s[i].first + t[e.first].first + e.second == s[T].first) {
                ans -= (s[i].second * t[e.first].second).pow(2);
            }
        }
    }

    cout << ans << endl;

    return 0;
}

