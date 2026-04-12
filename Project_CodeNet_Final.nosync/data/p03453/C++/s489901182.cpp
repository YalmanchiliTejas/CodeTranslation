#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i= (a); i<((int)b); ++i)
#define RFOR(i,a) for(int i=(a); i >= 0; --i)
#define FOE(i,a) for(auto i : a)
#define ALL(c) (c).begin(), (c).end()
#define RALL(c) (c).rbegin(), (c).rend()
#define DUMP(x)  cerr << #x << " = " << (x) << endl;
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v,x) (std::find(v.begin(), v.end(), x) != v.end())
#define BIT(n) (1LL<<(n))
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end());

typedef long long LL;
template<typename T> using V = std::vector<T>;
template<typename T> using VV = std::vector<std::vector<T>>;
template<typename T> using VVV = std::vector<std::vector<std::vector<T>>>;

template<class T> inline T ceil(T a, T b) { return (a + b - 1) / b; }
template<class T> inline void print(T x) { std::cout << x << std::endl; }
template<class T> inline void print_vec(const std::vector<T> &v) { for (int i = 0; i < v.size(); ++i) {  if (i != 0) {std::cout << " ";} std::cout << v[i];} std::cout << "\n"; }
template<class T> inline bool inside(T y, T x, T H, T W) {return 0 <= y and y < H and 0 <= x and x < W; }
template<class T> inline double euclidean_distance(T y1, T x1, T y2, T x2) { return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)); }
template<class T> inline double manhattan_distance(T y1, T x1, T y2, T x2) { return abs(x1 - x2) + abs(y1 - y2); }

const int INF = 1L << 30;
const double EPS = 1e-9;
const std::string YES = "YES", Yes = "Yes", NO = "NO", No = "No";
const std::vector<int> dy4 = { 0, 1, 0, -1 }, dx4 = { 1, 0, -1, 0 };    // 4近傍（右, 下, 左, 上）
const std::vector<int> dy8 = { 0, -1, 0, 1, 1, -1, -1, 1 }, dx8 = { 1, 0, -1, 0, 1, 1, -1, -1 };

using namespace std;
LL MOD = 1000000000 + 7;

pair<vector<LL>, vector<LL>> func(int S, int N, const vector<vector<pair<int, LL>>> &graph) {
    priority_queue<pair<LL, LL>, vector<pair<LL, LL>>, greater<pair<LL, LL>>> que;
    que.emplace(make_pair(0, S));

    vector<LL> cost(N, LLONG_MAX), dp(N, 0);
    cost[S] = 0;
    dp[S] = 1;
    while (not que.empty()) {
        LL now_cost = que.top().first;
        LL now_node = que.top().second;
        que.pop();

        FOE(p, graph[now_node]) {
            int next_node = p.first;
            LL next_cost = p.second;

            LL new_cost = now_cost + next_cost;
            if (new_cost < cost[next_node]) {
                dp[next_node] = dp[now_node];
                cost[next_node] = new_cost;
                que.emplace(make_pair(new_cost, next_node));
            }
            else if (new_cost == cost[next_node]) {
                dp[next_node] += dp[now_node];
                dp[next_node] %= MOD;
            }
        }
    }

    return make_pair(dp, cost);

};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N, M, S, T;
    cin >> N >> M;
    cin >> S >> T;
    S--; T--;

    vector<vector<pair<int, LL>>> graph(N);
    FOR(i, 0, M) {
        int u, v, d;
        cin >> u >> v >> d;
        u--; v--;

        graph[u].emplace_back(make_pair(v, d));
        graph[v].emplace_back(make_pair(u, d));
    }

    auto a1 = func(S, N, graph);
    auto a2 = func(T, N, graph);

    auto dist = a1.second[T];

    LL ans = 0;
    FOR(i, 0, N) {
        if (a1.second[i] * 2 == dist and a2.second[i] * 2 == dist) {
            LL a = (a1.first[i] * a2.first[i]) % MOD;
            ans += (a * a) % MOD;
            ans %= MOD;
        }
    }


    FOR(u, 0, N) {
        FOE(p, graph[u]) {
            int v = p.first;
            LL d = p.second;

            if (a1.second[u] + d + a2.second[v] == dist) {
                if (a1.second[u] * 2 < dist and a2.second[v] * 2 < dist) {
                    LL a = (a1.first[u] * a2.first[v]) % MOD;
                    ans += (a * a) % MOD;
                    ans %= MOD;
                }
            }
        }
    }

    print((a1.first[T] * a1.first[T] + MOD - ans) % MOD);

    return 0;
}