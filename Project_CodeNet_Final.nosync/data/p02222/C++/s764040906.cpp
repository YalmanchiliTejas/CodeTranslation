#include <bits/stdc++.h>
using namespace std;
/*#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T> using gpp_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename L> using gpp_map = tree<T, L, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T> using gpp_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;*/
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define IFOR(i, begin, end) for(int i=(end)-1;i>=(begin);i--)
#define IREP(i, n) IFOR(i,0,n)
#define Sort(v) sort(v.begin(), v.end())
#define Reverse(v) reverse(v.begin(), v.end())
#define all(v) v.begin(),v.end()
#define SZ(v) ((int)v.size())
#define Lower_bound(v, x) distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x) distance(v.begin(), upper_bound(v.begin(), v.end(), x))
#define Max(a, b) a = max(a, b)
#define Min(a, b) a = min(a, b)
#define bit(n) (1LL<<(n))
#define bit_exist(x, n) ((x >> n) & 1)
#define debug(x) cout << #x << "=" << x << endl;
#define vdebug(v) { cout << #v << "=" << endl; REP(i_debug, v.size()){ cout << v[i_debug] << ","; } cout << endl; }
#define mdebug(m) { cout << #m << "=" << endl; REP(i_debug, m.size()){ REP(j_debug, m[i_debug].size()){ cout << m[i_debug][j_debug] << ","; } cout << endl;} }
#define Return(ans) { cout << (ans) << endl; return 0; }
#define pb push_back
#define f first
#define s second
#define int long long
#define INF 1000000000000000000
template<typename T> istream &operator>>(istream &is, vector<T> &v){ for (auto &x : v) is >> x; return is; }
template<typename T> ostream &operator<<(ostream &os, vector<T> &v){ for(int i = 0; i < v.size(); i++) { cout << v[i]; if(i != v.size() - 1) cout << endl; }; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, pair<T1, T2> p){ cout << '(' << p.first << ',' << p.second << ')'; return os; }
template<typename T> void Out(T x) { cout << x << endl; }
template<typename T1, typename T2> void Ans(bool f, T1 y, T2 n) { if(f) Out(y); else Out(n); }

using vec = vector<int>;
using mat = vector<vec>;
using Pii = pair<int, int>;
using PiP = pair<int, Pii>;
using PPi = pair<Pii, int>;
using bools = vector<bool>;
using pairs = vector<Pii>;

//int dx[4] = {1,0,-1,0};
//int dy[4] = {0,1,0,-1};
//char d[4] = {'D','R','U','L'};

const int mod = 1000000007;
//const int mod = 998244353;
//#define Add(x, y) x = (x + (y)) % mod
//#define Mult(x, y) x = (x * (y)) % mod

struct edge{int to, cost, id;};

class Graph
{
public:
    int N;
    vector<vector<edge>> G;

    Graph(int N): N(N){
        G = vector<vector<edge>>(N, vector<edge>(0));
    }

    void add_Directed_edge(int from, int to, int cost = 1, int id = 0){
        G[from].push_back(edge({to, cost, id}));
    }

    void add_Undirected_edge(int v1, int v2, int cost = 1, int id = 0){
        add_Directed_edge(v1, v2, cost, id);
        add_Directed_edge(v2, v1, cost, id);
    }

    //calculate diameter of a Tree
    void dfs_for_calcdist(int v, int p, int c, vec &dist){
        if(p != -1) dist[v] = dist[p] + c;
        for(auto e: G[v]) if(e.to != p) dfs_for_calcdist(e.to, v, e.cost, dist);
    } 

    int diameter(int &v1, int &v2, int s = 0){
        vec dist(N, 0);
        dfs_for_calcdist(s, -1, -1, dist);
        v1 = distance(dist.begin(), max_element(dist.begin(), dist.end()));
        fill(dist.begin(), dist.end(), 0);
        dfs_for_calcdist(v1, -1, -1, dist);
        auto amax = max_element(dist.begin(), dist.end());
        v2 = distance(dist.begin(), amax);
        return *amax;
    }

    vec dijkstra(int s, int t){
        vec d(N);
        priority_queue<Pii, vector<Pii>, greater<Pii>> que;
        fill(d.begin(), d.end(), INF);
        d[s] = 0;
        que.push(Pii(0, s));

        while(!que.empty()){
            Pii p = que.top(); que.pop();
            int v = p.second;
            if(v == t) return d;
            if(d[v] < p.first) continue;
            REP(i, G[v].size()){
                edge e = G[v][i];
                if(d[e.to] > d[v] + e.cost){
                    d[e.to] = d[v] + e.cost;
                    que.push(Pii(d[e.to], e.to));
                }
            }
        }
        return d;
    }

};

signed main(){

    int N; cin >> N;
    Graph G(N);
    REP(i, N - 1){
        int a, b; cin >> a >> b;
        a--; b--;
        G.add_Undirected_edge(a, b); 
    }

    int s, t;
    int R = G.diameter(s, t);

    vec d_s = G.dijkstra(s, -1), d_t = G.dijkstra(t, -1);
    int M = 0;
    REP(i, N) {
        int z = (d_s[i] + d_t[i] - R) / 2;
        int x = d_s[i] - z, y = d_t[i] - z;
        if(z == 0) continue;
        if(x < y) swap(x, y);

        //debug(i); debug(x); debug(y); debug(z);

        if(x == y && y == z){
            Max(M, x + z - 1);
        }else{
            Max(M, x + z);
        }
    }
    //debug(M);

    string ans(N, '0');
    ans[0] = '1';
    ans[1] = '1';
    FOR(i, 3, N + 1){
        if(i > M) ans[i - 1] = '1';
    }
    Out(ans);

    return 0;
}

