#include <bits/stdc++.h>
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define IFOR(i, begin, end) for(int i=(end)-1;i>=(begin);i--)
#define IREP(i, n) IFOR(i,0,n)
#define SORT(a) sort(a.begin(), a.end())
#define REVERSE(a) reverse(a.begin(), a.end())
#define int long long
#define INF 1000000000000000
using namespace std;

typedef pair<int, int> Pii;

template<typename T>
void readvec(vector<T> &a);
void readindex(vector<int> &a);

#define MAX_V 100000
int V;
struct edge{int to, cost;};
vector<edge> G[MAX_V];

void add_edge(int from, int to, int cost){
    G[from].push_back(edge({to, cost}));
}

void add_edge2(int v1, int v2, int cost){
    G[v1].push_back(edge({v2, cost}));
    G[v2].push_back(edge({v1, cost}));
}

int d[MAX_V];
int d2[MAX_V];
void dijkstra(int s, int t){
    priority_queue<Pii, vector<Pii>, greater<Pii>> que;
    fill(d, d + V, INF);
    d[s] = 0;
    que.push(Pii(0, s));

    while(!que.empty()){
        Pii p = que.top(); que.pop();
        int v = p.second;
        if(v == t) return;
        if(d[v] < p.first) continue;
        REP(i, G[v].size()){
            edge e = G[v][i];
            if(d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] + e.cost;
                que.push(Pii(d[e.to], e.to));
            }
        }
    }
}

signed main(){

    int r = 1000000000 + 7;

    int N, M;
    cin >> N >> M;
    V = N;
    int S, T;
    cin >> S >> T;
    S--; T--;
    int U, V, D;
    REP(i, M){
        cin >> U >> V >> D;
        add_edge2(U - 1, V - 1, D);
    }

    vector<Pii> d0(N);
    dijkstra(S, -1);
    REP(i, N) d0[i] = Pii(d[i], i);
    SORT(d0);
    vector<int> dS(N, 0);
    dS[S] = 1;
    FOR(i, 1, N){
        int v = d0[i].second;
        int c = d0[i].first;
        dS[v] = 0;
        REP(k, G[v].size()){
            if(G[v][k].cost + d[G[v][k].to] == c) dS[v] = (dS[v] + dS[G[v][k].to]) % r;
        }
    }

    dijkstra(T, -1);
    REP(i, N) d2[i] = d[i]; 
    REP(i, N) d0[i] = Pii(d[i], i);
    SORT(d0);
    vector<int> dT(N, 0);
    dT[T] = 1;
    FOR(i, 1, N){
        int v = d0[i].second;
        int c = d0[i].first;
        dT[v] = 0;
        REP(k, G[v].size()){
            if(G[v][k].cost + d[G[v][k].to] == c) dT[v] = (dT[v] + dT[G[v][k].to]) % r;
        }
    }

    int ans = (dS[T] * dT[S]) % r;

    //頂点上で会うのを除く
    int n = 0;
    dijkstra(S, -1);
    REP(i, N){
        if(d[i] * 2 == d[T]){
            int tmp = (dS[i] * dT[i]) % r;
            n = (n + (tmp * tmp)) % r;
        }
    }

    ans = (ans + (r - n)) % r;

    //辺上で会うのを取り除く
    n = 0;
    REP(vS, N){
        REP(k, G[vS].size()){
            int vT = G[vS][k].to;
            if(d[vS] + d2[vT] + G[vS][k].cost == d[T] &&llabs(d[vS] - d2[vT]) < G[vS][k].cost){
                int tmp = (dS[vS] * dT[vT]) % r;
                n = (n + (tmp * tmp)) % r;
            }
        }
    }

    ans = (ans + (r - n)) % r;

    cout << ans;
        
    return 0;
}


template<typename T>
void readvec(vector<T> &a){
    REP(i, a.size()){
        cin >> a[i];
    }
}
void readindex(vector<int> &a){
    REP(i, a.size()){
        cin >> a[i];
        a[i]--;
    }
}