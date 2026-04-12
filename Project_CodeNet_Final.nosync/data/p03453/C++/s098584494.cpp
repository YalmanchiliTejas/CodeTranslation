#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using u64 = uint_fast64_t;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
//constexpr long long MOD = 998244353;
template<class T1, class T2> inline bool chmax(T1 &a, T2 b) { if (a < b) { a = b; return true;} return false; }
template<class T1, class T2> inline bool chmin(T1 &a, T2 b) { if (a > b) { a = b; return true;} return false; }
inline int popcount(int x) {return __builtin_popcount(x);}
inline int popcount(long long x) {return __builtin_popcountll(x);}
void print() { cout << "\n"; }
template<class T, class... Args>
void print(const T &x, const Args &... args) {
    cout << x << " ";
    print(args...);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<typename T>
struct edge {
    int src,to;
    T cost;

    edge(){};
    edge(int to, T cost) : src(-1), to(to), cost(cost) {}
    edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}
    bool operator<(const edge &e) const {
        return cost < e.cost;
    }
};

template <uint_fast64_t Modulus> 
struct ModInt {
    using u64 = uint_fast64_t;

    u64 a;

    constexpr ModInt(const long long x = 0) noexcept : a(x >= 0 ? x % Modulus : (Modulus - (-x) % Modulus) % Modulus) {}
    constexpr u64 &value() noexcept {return a;}
    constexpr const u64 &value() const noexcept {return a;}
    constexpr ModInt operator+(const ModInt rhs) const noexcept {return ModInt(*this) += rhs;}
    constexpr ModInt operator-(const ModInt rhs) const noexcept {return ModInt(*this) -= rhs;}
    constexpr ModInt operator*(const ModInt rhs) const noexcept {return ModInt(*this) *= rhs;}
    constexpr ModInt operator/(const ModInt rhs) const noexcept {return ModInt(*this) /= rhs;}
    constexpr ModInt operator^(const long long rhs) const noexcept {return ModInt(*this) ^= rhs;}
    constexpr bool operator==(const ModInt &rhs) const noexcept {return a == rhs.a;}
    constexpr bool operator!=(const ModInt &rhs) const noexcept {return a != rhs.a;}
    constexpr ModInt &operator+=(const ModInt rhs) noexcept {
        a += rhs.a;
        if (a >= Modulus) {
            a -= Modulus;
        }
        return *this;
    }
    constexpr ModInt &operator-=(const ModInt rhs) noexcept {
        if (a < rhs.a) {
            a += Modulus;
        }
        a -= rhs.a;
        return *this;
    }
    constexpr ModInt &operator*=(const ModInt rhs) noexcept {
        a = a * rhs.a % Modulus;
        return *this;
    }
    constexpr ModInt &operator/=(ModInt rhs) noexcept {
        u64 exp = Modulus - 2;
        while (exp) {
            if (exp&1) *this *= rhs;
            exp >>= 1;
            rhs *= rhs;
        }
        return *this;
    }
    constexpr ModInt &operator^=(long long exp) noexcept {
        ModInt rhs = a;
        a = 1;
        while (exp) {
            if (exp&1) *this *= rhs;
            exp >>= 1;
            rhs *= rhs;
        }
        return *this;
    }

    friend ostream &operator<<(ostream& os, const ModInt& rhs) noexcept {return os << rhs.a;}
    friend istream &operator>>(istream& is, ModInt& rhs) noexcept {long long a; is >> a; rhs = a; return is;}
};

using mint = ModInt<MOD>;

template<typename T>
pair<vector<T>,vector<mint>> Dijkstra(vector<vector<edge<T>>> &G, int s, T inf) {
    vector<T> dist(G.size(),inf);
    vector<mint> cnt(G.size());
    using Pi = pair<T, int>;
    priority_queue<Pi, vector<Pi>, greater<Pi>> pq;
    dist[s] = 0;
    cnt[s] = 1;
    pq.emplace(dist[s],s);
    while (!pq.empty()) {
        T d; int v;
        tie(d,v) = pq.top(); pq.pop();
        if (d > dist[v]) continue;
        for (auto &e : G[v]) {
            if (dist[e.to] > dist[v] + e.cost) {
                dist[e.to] = dist[v] + e.cost;
                pq.emplace(dist[e.to],e.to);
                cnt[e.to] = cnt[v];
            } else if (dist[e.to] == dist[v] + e.cost) {
                cnt[e.to] += cnt[v];
            }
        }
    }

    return make_pair(dist,cnt);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N,M; cin >> N >> M;
    int s,t; cin >> s >> t;
    --s; --t;
    vector<vector<edge<ll>>> G(N);
    vector<edge<ll>> E(M);
    rep(i,M) {
        int u,v,w; cin >> u >> v >> w;
        u--; v--;
        G[u].emplace_back(v,w);
        G[v].emplace_back(u,w);
        E[i] = edge<ll>(u,v,w);
    }

    vector<ll> dist1,dist2;
    vector<mint> cnt1,cnt2;
    tie(dist1,cnt1) = Dijkstra<ll>(G,s,1e18);
    tie(dist2,cnt2) = Dijkstra<ll>(G,t,1e18);
    mint ans = cnt1[t]*cnt2[s];
    rep(i,M) {
        int u = E[i].src;
        int v = E[i].to;
        if (dist1[u] > dist1[v]) swap(u,v);
        if (dist1[u]+E[i].cost != dist1[v]) continue;
        if (dist1[u]+dist2[v]+E[i].cost==dist1[t] and dist1[u] < dist2[u] and dist1[v] > dist2[v]) {
            ans -= cnt1[u]*cnt1[u]*cnt2[v]*cnt2[v];
        }
    }

    rep(i,N) {
        if (dist1[i]+dist2[i]==dist1[t] and dist1[i]==dist2[i]) {
            ans -= cnt1[i]*cnt1[i]*cnt2[i]*cnt2[i];
        }
    }

    cout << ans << ln;
}