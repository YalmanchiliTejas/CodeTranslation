#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

constexpr int Mod = 998244353;
constexpr int mod = 1e9 + 7;
constexpr ll inf = 1LL << 60;

template <typename T> constexpr bool chmax(T &a, const T b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <typename T> constexpr bool chmin(T &a, const T b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

template <int M> class ModInt {
    int x;

  public:
    constexpr ModInt() : x(0) {}
    constexpr ModInt(int64_t y) : x(y >= 0 ? y % M : (M - (-y) % M) % M) {}
    constexpr ModInt &operator+=(const ModInt &p) {
        if((x += p.x) >= M) x -= M;
        return *this;
    }
    constexpr ModInt &operator-=(const ModInt &p) {
        if((x += M - p.x) >= M) x -= M;
        return *this;
    }
    constexpr ModInt &operator*=(const ModInt &p) {
        x = (int)(1LL * x * p.x % M);
        return *this;
    }
    constexpr ModInt &operator/=(const ModInt &p) {
        *this *= p.inverse();
        return *this;
    }
    constexpr ModInt operator-() const { return ModInt(-x); }
    constexpr ModInt operator+(const ModInt &p) const {
        return ModInt(*this) += p;
    }
    constexpr ModInt operator-(const ModInt &p) const {
        return ModInt(*this) -= p;
    }
    constexpr ModInt operator*(const ModInt &p) const {
        return ModInt(*this) *= p;
    }
    constexpr ModInt operator/(const ModInt &p) const {
        return ModInt(*this) /= p;
    }
    constexpr bool operator==(const ModInt &p) const { return x == p.x; }
    constexpr bool operator!=(const ModInt &p) const { return x != p.x; }
    constexpr ModInt inverse() const {
        int a = x, b = M, u = 1, v = 0, t = 0;
        while(b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return ModInt(u);
    }
    constexpr ModInt pow(const int64_t &n) const {
        ModInt ret(1), mul(x);
        int64_t k = n % (M - 1);
        while(k > 0) {
            if(k & 1) ret *= mul;
            mul *= mul;
            k >>= 1;
        }
        return ret;
    }
    constexpr friend ostream &operator<<(ostream &os, const ModInt &p) {
        return os << p.x;
    }
    constexpr friend istream &operator>>(istream &is, ModInt &a) {
        int64_t t = 0;
        is >> t;
        a = ModInt(t);
        return (is);
    }
};

struct Edge {
    int to, cost;
    Edge(int to, int cost) : to(to), cost(cost) {}
};

struct Node {
    int v;
    ll d;
    Node(int v, ll d) : v(v), d(d) {}
    inline bool operator<(const Node &r) const { return d > r.d; }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    using mint = ModInt<mod>;

    int n, m, s, t;
    cin >> n >> m;
    cin >> s >> t;
    s--;
    t--;
    vector<vector<Edge>> G(n);
    rep(i, m) {
        int u, v, d;
        cin >> u >> v >> d;
        u--;
        v--;
        G[u].push_back(Edge(v, d));
        G[v].push_back(Edge(u, d));
    }
    vector<ll> dis(n, inf);
    priority_queue<Node> pque;
    pque.push(Node(s, 0));
    dis[s] = 0;
    while(!pque.empty()) {
        int v = pque.top().v;
        ll d = pque.top().d;
        pque.pop();
        if(dis[v] < d) continue;
        for(Edge e : G[v])
            if(chmin(dis[e.to], d + e.cost)) pque.push(Node(e.to, dis[e.to]));
    }
    vector<mint> dps(n, 0), dpt(n, 0);
    vector<int> p(n);
    rep(i, n) p[i] = i;
    sort(ALL(p), [&](int a, int b) { return dis[a] < dis[b]; });
    dps[s] = 1;
    for(int i : p) {
        for(Edge e : G[i])
            if(dis[e.to] == dis[i] + e.cost) dps[e.to] += dps[i];
    }
    reverse(ALL(p));
    dpt[t] = 1;
    for(int i : p)
        for(Edge e : G[i])
            if(dis[i] == dis[e.to] + e.cost) dpt[e.to] += dpt[i];
    mint ans = dpt[s] * dps[t];
    rep(i, n) {
        if(dis[i] * 2 == dis[t]) ans -= (dps[i] * dpt[i]).pow(2);
        if(dis[i] * 2 >= dis[t]) continue;
        for(Edge e : G[i])
            if(dis[e.to] * 2 > dis[t] && dis[e.to] == dis[i] + e.cost)
                ans -= (dps[i] * dpt[e.to]).pow(2);
    }
    cout << ans << endl;

    return 0;
}