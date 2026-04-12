#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = b - 1; i >= a; i--)
#define ALL(a) a.begin(), a.end()
#define pii pair<int,int>
#pragma GCC optimize("Ofast")
#define pcnt __builtin_popcount
#define buli(x) __builtin_popcountll(x)
#define pb push_back
#define mp make_pair
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define isSquare(x) (sqrt(x)*sqrt(x) == x)
template<class T>bool chmax(T &a, const T &b) {if(a<b){a = b; return 1;} return 0; };
template<class T>bool chmin(T &a, const T &b) {if(a>b){a = b; return 1;} return 0; };
inline void IN(void){return;}
template <typename First, typename... Rest> void IN(First& first, Rest&... rest){cin >> first;IN(rest...);return;}
inline void OUT(void){cout << "\n";return;}
template <typename First, typename... Rest> void OUT(First first, Rest... rest){cout << first << " ";OUT(rest...);return;}
const double EPS = 1e-9;
const int mod = 1e9 + 7;
const int INF = 1e9;
const long long LLINF = 1e18;
long long lcm(ll a, ll b){return a * b / __gcd(a,b);}
struct IoSetup { IoSetup() {
    cin.tie(nullptr);ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(10);
} } iosetup;
template< typename T1, typename T2 >
ostream &operator<<(ostream &os, const pair< T1, T2 >& p) {
    os << p.first << " " << p.second;
    return os;
}
template< typename T1, typename T2 >
istream &operator>>(istream &is, pair< T1, T2 > &p) {
    is >> p.first >> p.second;
    return is;
}
template< typename T >
ostream &operator<<(ostream &os, const vector< T > &v) {
    for(int i = 0; i < (int) v.size(); i++) {
        os << v[i] << (i + 1 != v.size() ? " " : "");
    }
    return os;
}
template< typename T >
istream &operator>>(istream &is, vector< T > &v) {
    for(T &in : v) is >> in;
    return is;
}
template <typename T> void Exit(T first){cout << first << endl;exit(0); };
template< int mod > struct ModInt {
    int x; ModInt() : x(0) {}
    ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}
    ModInt &operator+=(const ModInt &p) {if((x += p.x) >= mod) x -= mod;return *this;}
    ModInt &operator-=(const ModInt &p) {if((x += mod - p.x) >= mod) x -= mod;return *this;}
    ModInt &operator*=(const ModInt &p) {x = (int) (1LL * x * p.x % mod);return *this;}
    ModInt &operator/=(const ModInt &p) {*this *= p.inverse();return *this;}
    ModInt operator-() const { return ModInt(-x); }
    ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }
    ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }
    ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }
    ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }
    bool operator==(const ModInt &p) const { return x == p.x; }
    bool operator!=(const ModInt &p) const { return x != p.x; }
    ModInt inverse() const {int a = x, b = mod, u = 1, v = 0, t;
    while(b > 0) { t = a / b; swap(a -= t * b, b); swap(u -= t * v, v); }return ModInt(u);}
    ModInt pow(int64_t n) const {ModInt ret(1), mul(x); while(n > 0) {if(n & 1) ret *= mul;mul *= mul;n >>= 1;}return ret;}
    friend ostream &operator<<(ostream &os, const ModInt &p) { return os << p.x;}
    friend istream &operator>>(istream &is, ModInt &a) { int64_t t; is >> t; a = ModInt< mod >(t); return (is); }
    static int get_mod() { return mod; }
}; using modint = ModInt< mod >;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

template< typename T > struct edge {
   int src, to; T cost;
   edge(int to, T cost) : src(-1), to(to), cost(cost) {}
   edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}
   edge &operator=(const int &x) { to = x; return *this;}
   operator int() const { return to; }
};
template< typename T > using Edges = vector< edge< T > >;
template< typename T > using WeightedGraph = vector< Edges< T > >;
using UnWeightedGraph = vector< vector< int > >;
template< typename T > using Matrix = vector< vector< T > >;

template< typename T > struct dijkstra
{
        WeightedGraph< T > g;
        int s;
        int V;
        vector<int> Prev;
        vector<T> Dist;
        vector<modint> dp;

        using Pi = pair< T, int >;
        dijkstra(WeightedGraph< T > &G, int S){
            g = G;
            s = S;
            V = G.size();
            Prev.resize(V, -1);
            Dist.resize(g.size(), LLINF);
            dp.resize(V, 0);
        }


        vector< T > dist(){
            priority_queue< Pi, vector< Pi >, greater< Pi > > que;
            Dist[s] = 0;
            dp[s] = 1;
            que.emplace(Dist[s], s);
            while(!que.empty()) {
                T cost;
                int idx;
                tie(cost, idx) = que.top();
                que.pop();
                if(Dist[idx] < cost) continue;
                for(auto &e : g[idx]) {
                    auto next_cost = cost + e.cost;
                    if(Dist[e.to] < next_cost) continue;
                    else if(Dist[e.to] == next_cost){
                        dp[e.to] += dp[idx];
                        continue;
                    }
                    dp[e.to] = dp[idx];
                    Dist[e.to] = next_cost;
                    Prev[e.to] = idx;
                    que.emplace(Dist[e.to], e.to);
                }
            }
            return Dist;
        }

        // 頂点tへの最短路
        vector<int> get_path(int t){
            vector<int> path;
            for(; t != -1; t = Prev[t]) path.push_back(t);//tがsになるまで辿っていく
            reverse(path.begin(), path.end());
            return path;
        }
};
// dijkstra<int> ds(G, 1);

int main(){
    iosetup;
    int N, M; cin >> N >> M;
    int S, T;IN(S, T);S--, T--;
    WeightedGraph<ll> G(N);
    rep(i, 0, M){
        int u, v;
        ll d; cin >> u >> v >> d; u--, v--;
        G[u].push_back({v, d});
        G[v].push_back({u, d});
    }
    dijkstra<ll> distt(G, S), dista(G, T);
    auto d_T = distt.dist();
    auto d_A = dista.dist();
    ll TL = d_T[T];
    modint ans = distt.dp[T];
    ans *= ans;
    // cerr << ans << endl;
    // cerr << TL << endl;
    rep(i, 0, N){
        // cerr << i << " " << ans << endl;
        if(TL%2 == 0){
            if(TL/2 == d_T[i]){
                modint tmp = distt.dp[i] * dista.dp[i];
                ans -= tmp * tmp;
            }
            else{
                for(auto nv: G[i]){
                    if(d_T[i] < TL/2 && d_A[nv.to] < TL/2 && d_T[i] + d_A[nv.to] + nv.cost == TL){
                        modint tmp = distt.dp[i] * dista.dp[nv.to];
                        ans -= tmp * tmp;
                    }
                }
            }
        }else{
            for(auto nv: G[i]){
                if(d_T[i] <= TL/2 && d_T[nv.to] > TL/2 && d_T[i] + d_A[nv.to] + nv.cost == TL){
                    modint tmp = distt.dp[i] * dista.dp[nv.to];
                    ans -= tmp * tmp;
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}