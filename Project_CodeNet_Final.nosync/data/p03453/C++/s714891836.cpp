#include <bits/stdc++.h>
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define IFOR(i, begin, end) for(int i=(end)-1;i>=(begin);i--)
#define IREP(i, n) IFOR(i,0,n)
#define SORT(a) sort(a.begin(), a.end())
#define REVERSE(a) reverse(a.begin(), a.end())
#define Lower_bound(v, x) distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x) distance(v.begin(), upper_bound(v.begin(), v.end(), x))
#define int long long
#define INF 1000000000000000000
using namespace std;

#define ANS(f) if(f) cout << "YES" << endl; else cout << "NO" << endl;

typedef vector<int> vec;
typedef vector<vec> mat;
typedef pair<int, int> Pii;

template<typename T>
void readv(vector<T> &a){ REP(i, a.size()) cin >> a[i]; }
void readi(vector<int> &a){ REP(i, a.size()){cin >> a[i]; a[i]--;} }
void debug(mat m){REP(i, m.size()){ REP(j, m[i].size()){ cout << m[i][j] << ","; } cout << endl; }}

int mod = 1000000007;

struct edge{int to, cost;};

class Graph
{
public:
    int V;
    vector<vector<edge>> G;

    Graph(int V): V(V){
        G = vector<vector<edge>>(V, vector<edge>(0));
    }

    void add_edge(int from, int to, int cost){
        G[from].push_back(edge({to, cost}));
    }

    void add_edge2(int v1, int v2, int cost){
        add_edge(v1, v2, cost);
        add_edge(v2, v1, cost);
    }

    vec dijkstra(int s, int t){
        vec d(V);
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

    vec pattern(int s, vec &dS, vec &dT, int D){
        vec n(V, 0);
        n[s] = 1;
        vector<bool> pushed(V, false);
        priority_queue<Pii, vector<Pii>, greater<Pii>> que;
        que.push(Pii(dS[s], s));
        while(!que.empty()){
            Pii p = que.top(); que.pop();
            int v = p.second;
            REP(i, G[v].size()){
                if(dS[v] + dT[G[v][i].to] + G[v][i].cost == D){
                    if(!pushed[G[v][i].to]){
                        que.push(Pii(dS[G[v][i].to], G[v][i].to));
                        pushed[G[v][i].to] = true;
                    }
                    n[G[v][i].to] += n[v];
                    n[G[v][i].to] %= mod;
                }
            }
        }
        return n;
    }

};

signed main(){

    int N, M; cin >> N >> M;
    int S, T; cin >> S >> T;
    S--; T--;
    Graph G(N);
    int U, V, D;
    REP(i, M){
        cin >> U >> V >> D;
        G.add_edge2(U - 1, V - 1, D);
    }
    vec dS = G.dijkstra(S, -1);
    vec dT = G.dijkstra(T, -1);
    vec nS = G.pattern(S, dS, dT, dS[T]);
    vec nT = G.pattern(T, dT, dS, dT[S]);

    int ans = (nS[T] * nT[S]) % mod;
    REP(i, N) if(dS[i] == dT[i]){
        int n = (nS[i] * nT[i]) % mod;
        ans -= n * n;
        ans = (ans % mod + mod) % mod;
    }
    REP(i, N){
        REP(k, G.G[i].size()){
            int j = G.G[i][k].to;
            int c = G.G[i][k].cost;
            if(dS[j] == dS[i] + c && dT[i] == dT[j] + c){
                if(!((dS[j] <= dT[j]) || (dT[i] <= dS[i]))){
                    int n = (nS[i] * nT[j]) % mod;
                    ans -= n * n;
                    ans = (ans % mod + mod) % mod;
                }
            }
        }
    }

    cout << ans << endl;
    
    return 0;
}