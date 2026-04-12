#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair < int , int > Pi;
typedef pair < ll , ll > Pl;

const int INF = (1 << 30) - 1;
const ll LLINF = 1LL << 60;
const ll mod = 1000000007;
struct Edge 
{
    ll to, cost;
    Edge () {}
    Edge (ll to, ll cost) : to(to), cost(cost) {}
};
vector < Edge > G[100005];
ll min_cost[100005];
ll N, M, S, T;
ll A[200005], B[200005], C[200005];
ll memo[2][100005];

void Dijkstra(ll s)
{
    priority_queue < Pl , vector < Pl > , greater < Pl > > pq;
    fill_n(min_cost, 100005, LLINF);
    min_cost[s] = 0;
    pq.push(Pl(0, s));
    while(!pq.empty()) {
        Pl d = pq.top(); pq.pop();
        for(int i = 0; i < G[d.second].size(); i++) {
            ll u = G[d.second][i].to, w = G[d.second][i].cost + d.first;
            if(w < min_cost[u]) {
                min_cost[u] = w;
                pq.push(Pl(w, u));
            }
        }
    }
}
ll dfs(ll v, int k)
{
    if(k == 0 && v == T || k == 1 && v == S) return (1);
    if(memo[k][v] == -1) {
        memo[k][v] = 0;
        for(int i = 0; i < G[v].size(); i++) {
            ll u = G[v][i].to, w = G[v][i].cost;
            if(k == 0 && min_cost[v] + w == min_cost[u] || k == 1 && min_cost[u] + w == min_cost[v]) {
                (memo[k][v] += dfs(u, k)) %= mod;
            }
        }
    }
    return (memo[k][v]);
}
int main()
{
    cin >> N >> M >> S >> T; --S, --T;
    for(int i = 0; i < M; i++) {
        scanf("%lld %lld %lld", &A[i], &B[i], &C[i]); --A[i], --B[i];
        G[A[i]].push_back(Edge(B[i], C[i]));
        G[B[i]].push_back(Edge(A[i], C[i]));
    }
    Dijkstra(S);
    memset(memo, -1, sizeof(memo));
    dfs(S, 0); dfs(T, 1); //T -> v,  S -> v
    ll sum = (memo[0][S] * memo[0][S]) % mod;
    for(int i = 0; i < N; i++) {
        if(min_cost[i] * 2 == min_cost[T]) {
            (sum += mod - (((memo[0][i] * memo[0][i]) % mod) * ((memo[1][i] * memo[1][i]) % mod)) % mod) %= mod;
        }
    }
    for(int i = 0; i < M; i++) {
        if(min_cost[A[i]] + C[i] == min_cost[B[i]] && min_cost[A[i]] * 2 < min_cost[T] && min_cost[B[i]] * 2 > min_cost[T]) {
            (sum += mod - (((memo[1][A[i]] * memo[0][B[i]]) % mod) * ((memo[1][A[i]] * memo[0][B[i]]) % mod)) % mod) %= mod;
        }
        if(min_cost[B[i]] + C[i] == min_cost[A[i]] && min_cost[B[i]] * 2 < min_cost[T] && min_cost[A[i]] * 2 > min_cost[T]) {
            (sum += mod - (((memo[1][B[i]] * memo[0][A[i]]) % mod) * ((memo[1][B[i]] * memo[0][A[i]]) % mod)) % mod) %= mod;
        }
    }
    cout << sum << endl;
    return (0);
}