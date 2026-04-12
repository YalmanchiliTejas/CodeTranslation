#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef tuple<ll, ll, ll> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
#define REP(i,n) for (ll i = 0; i < n; ++i)
#define REPR(i,n) for (ll i = n-1; i >= 0; --i)
#define FOR(i,m,n) for (ll i = m; i < n; ++i)
#define FORR(i,m,n) for (ll i = n-1; i >= m; --i)
#define FORE(x,xs) for (const auto& x : xs)
#define FORI(i,v) for (auto i = v.begin(); i != v.end(); i++)
#define ALL(v) v.begin(), v.end()
#define CHMIN(x,y) x = min(x, y)
#define CHMAX(x,y) x = max(x, y)

template<int mod> struct ModInt {
    int64_t x;
    ModInt() : x(0) {}
    ModInt(int64_t y) : x(y >= 0 ? y % mod : (y % mod + mod) % mod) {}

    ModInt &operator+=(const ModInt &a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }

    ModInt &operator-=(const ModInt &a) {
        if ((x += mod - a.x) >= mod) x -= mod;
        return *this;
    }

    ModInt &operator*=(const ModInt &a) {
        x = 1LL * x * a.x % mod;
        return *this;
    }

    ModInt &operator/=(const ModInt &a) {
        *this *= a.inverse();
        return *this;
    }

    ModInt operator-() const {
        return ModInt(-x);
    }

    ModInt operator+(const ModInt a) const {
        return ModInt(*this) += a;
    }

    ModInt operator-(const ModInt a) const {
        return ModInt(*this) -= a;
    }

    ModInt operator*(const ModInt a) const {
        return ModInt(*this) *= a;
    }

    ModInt operator/(const ModInt a) const {
        return ModInt(*this) /= a;
    }

    bool operator==(const ModInt a) const {
        return x == a.x;
    }

    bool operator!=(const ModInt a) const {
        return x != a.x;
    }

    ModInt pow(int64_t k) const {
        ModInt ret(1), mul(x);
        while (k > 0) {
            if (k & 1) ret *= mul;
            mul *= mul;
            k >>= 1;
        }
        return ret;
    }

    ModInt inverse() const {
        return pow(mod - 2);
    }

    friend ostream &operator<<(ostream &os, const ModInt &p) {
        return os << p.x;
    }

    friend istream &operator>>(istream &is, ModInt &a) {
        int64_t t;
        is >> t;
        a = ModInt<mod>(t);
        return (is);
    }
};

const int MOD = 1e9+7;
using modint = ModInt<MOD>;

const ll INF = 1ll<<61;

template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;

class Dijkstra {
private:
    int N;
    vvii E;

    void init(int n) {
        E.resize(0); E.clear();
        N = n; E.resize(n);
    }

public:
    Dijkstra() {}
    Dijkstra(int n) { init(n); }

    void add(int from, int to, int cost) {
        E[from].push_back(ii(to, cost));
    }

    pair<vi, vector<modint>> solve(int s) {
        vi dis(N, INF);
        vector<modint> pat(N, modint(0));
        vector<bool> vis(N);
        dis[s] = 0;
        pat[s] = modint(1);

        min_priority_queue<ii> q;
        q.push(ii(0, s));

        while (!q.empty()) {
            int t, d;
            tie(d, t) = q.top(); q.pop();

            if (vis[t]) continue;
            vis[t] = true;

            FORE (p, E[t]) {
                ll next = p.first, c = p.second;
                if (vis[next]) continue;
                if (dis[t] + c < dis[next]) {
                    dis[next] = dis[t] + c;
                    pat[next] = pat[t];
                    q.push(ii(dis[next], next));
                } else if (dis[t] + c == dis[next]) {
                    pat[next] += pat[t];
                }
            }
        }
        return make_pair(dis, pat);
    }
};

ll N, M, S, T;
vvii E;

vi distS, distT;
vector<modint> patternS, patternT;

inline bool isInShortestPath(int n) {
    return distS[n] + distT[n] == distS[T];
}

inline bool isHalfPoint(int n) {
    return distS[n] == distT[n];
}

inline bool isCloseToS(int n) {
    return distS[n] < distT[n];
}

inline bool isCloseToT(int n) {
    return distS[n] > distT[n];
}

modint solve() {
    Dijkstra dijkstra(N);
    REP (i, N) FORE (e, E[i]) dijkstra.add(i, e.first, e.second);
    tie(distS, patternS) = dijkstra.solve(S);
    tie(distT, patternT) = dijkstra.solve(T);
    modint ret = patternS[T].pow(2);

    ll D = distS[T];
    REP (cur, N) if (isInShortestPath(cur)) {
        if (isHalfPoint(cur)) {
            ret -= (patternS[cur] * patternT[cur]).pow(2);
        } else if (isCloseToS(cur)) {
            FORE (e, E[cur]) {
                ll next = e.first, d = e.second;
                if (distS[cur] + d == distS[next] && isInShortestPath(next) && isCloseToT(next)) {
                    ret -= (patternS[cur] * patternT[next]).pow(2);
                }
            }
        }
    }

    return ret;
}

int main() {
    cin >> N >> M >> S >> T;
    E = vvii(N);
    S--; T--;
    REP (i, M) {
        ll u, v, d;
        cin >> u >> v >> d;
        u--; v--;
        E[u].push_back(ii(v, d));
        E[v].push_back(ii(u, d));
    }
    cout << solve() << endl;
}