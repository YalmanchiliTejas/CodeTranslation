#include <bits/stdc++.h>
using namespace std;

// macros
#define overload_rep(_1, _2 ,_3 ,name, ...) name
#define re_p(i, n) for(int i = 0; i < (n); ++i)
#define r_ep(i, x, y) for(int i = (x); i <= (y); ++i)
#define rep(...) overload_rep(__VA_ARGS__, r_ep, re_p)(__VA_ARGS__)
#define all(a) a.begin(), a.end()
#ifndef STOP_DEBUG
#define debug(...)\
    do { cerr << boolalpha << "[" << #__VA_ARGS__ << "]:";\
    debug_cerr(__VA_ARGS__); cerr << noboolalpha; } while (0)
#else
#define debug(...)
#endif

// functions
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
void debug_cerr(){ cerr << '\n'; }
template<class Head, class... Tail>
void debug_cerr(Head head, Tail... tail){
    cerr << ' ' << head;
    debug_cerr(tail...);
}

// cin/cout setup
struct IoSetup{
    IoSetup(){
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
    }
} iosetup;

// libraries
template<const int_fast64_t mod = 1000000007>
struct ModInt{
private: using ll = int_fast64_t;
public: ll x;
    inline constexpr ModInt(ll t = 0) noexcept : x((t %= mod) < 0 ? t + mod : t) {}
    inline constexpr friend istream& operator >> (istream& s, ModInt& m) noexcept {
        s >> m.x; m.x %= mod; if(m.x < 0)m.x += mod; return s;
    }
    inline constexpr friend ostream& operator << (ostream& s, ModInt m) noexcept {
        return s << m.x;
    }
    inline constexpr ModInt operator + (const ModInt m) noexcept { return ModInt(*this) += m; }
    inline constexpr ModInt& operator += (const ModInt m) noexcept {
        if((x += m.x) >= mod)x -= mod; return *this;
    }
    inline constexpr ModInt operator - (const ModInt m) noexcept { return ModInt(*this) -= m; }
    inline constexpr ModInt& operator -= (const ModInt m) noexcept {
        if((x += mod - m.x) >= mod)x -= mod; return *this;
    }
    inline constexpr ModInt operator * (const ModInt m) noexcept { return ModInt(*this) *= m; }
    inline constexpr ModInt& operator *= (const ModInt m) noexcept {
        x = x * m.x % mod; return *this;
    }
    inline constexpr ModInt operator / (const ModInt m) noexcept { return ModInt(*this) /= m; }
    inline constexpr ModInt& operator /= (const ModInt m) noexcept {
        return *this *= m.inv();
    }
    inline constexpr ModInt inv() const noexcept {
        ll a = x, b = mod, u = 1, v = 0, t = 0;
        while(b){ t = a / b; a -= t * b; swap(a, b); u -= t * v; swap(u, v); }
        return ModInt(u);
    }
    inline constexpr ModInt pow(ll p) const noexcept {
        ModInt res(1), mult(*this);
        for(; p; p >>= 1){ if(p & 1)res *= mult; mult *= mult; }
        return res;
    }
};

// declarations
using mint = ModInt<>;
typedef long long ll;
const long long inf = 1ll << 60;

struct edge{
    int to, cost;
    edge(int t, int c) : to(t), cost(c) {}
};

int N, M, S, T;
int order[100000];
vector<edge> graph[100000];
ll dist[2][100000];
mint ways[2][100000];

void dijkstra(int index, int start){
    fill(dist[index], dist[index] + N, inf);
    dist[index][start] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que;
    que.push(make_pair(dist[index][start], start));
    while(!que.empty()){
        int v; ll d;
        tie(d, v) = que.top();
        que.pop();
        for(edge e : graph[v]){
            if(chmin(dist[index][e.to], d + e.cost)){
                que.push(make_pair(d + e.cost, e.to));
            }
        }
    }   
}

void calc_ways(int index){
    iota(order, order + N, 0);
    sort(order, order + N, [&](int i, int j){
        return dist[index][i] < dist[index][j];
    });
    ways[index][order[0]] = mint(1);
    rep(loop, N){
        int i = order[loop];
        for(edge e : graph[i]){
            if(dist[index][e.to] == dist[index][i] + e.cost){
                ways[index][e.to] += ways[index][i];
            }
        }
    }
}

// solve
int main(){

    cin >> N >> M >> S >> T;
    S--; T--;
    rep(i, M){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        graph[a].push_back(edge(b, c));
        graph[b].push_back(edge(a, c));
    }

    dijkstra(0, S);
    dijkstra(1, T);
    calc_ways(0);
    calc_ways(1);

    ll dist_st = dist[0][T];
    mint ans;
    rep(i, N){
        if(dist[0][i] + dist[1][i] == dist_st){
            if(dist[0][i] == dist[1][i]){
                ans += ways[0][i] * ways[1][i] * ways[0][i] * ways[1][i];
            }
        }
        for(edge e : graph[i]){
            if(dist[0][i] + dist[1][e.to] + e.cost == dist_st){
                if(dist[0][i] * 2 < dist_st && dist[1][e.to] * 2 < dist_st){
                    ans += ways[0][i] * ways[1][e.to] * ways[0][i] * ways[1][e.to];
                }
            }
        }
    }

    cout << ways[0][T] * ways[1][S] - ans << '\n';
    return 0;

}
