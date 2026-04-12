#include <iostream>
#include <vector>
#include <queue>

#define V_MAX 100000
#define E_MAX 200000
#define INF 10e+17
#define MOD 1000000007

using namespace std;
struct edge{long to, cost;};
//struct vertex{long pos, dist;};
typedef pair<long, long> P;

vector<edge> G[V_MAX];

long ds[V_MAX];
long dt[V_MAX];
long cnt_t[V_MAX], cnt_s[V_MAX];

long N;//頂点数

bool can_use[V_MAX];

void dijkstra(long s, long d[]){
    priority_queue<P, vector<P>, greater<P>> que;
    fill(d, d+N, INF);
    d[s] = 0;
    que.push(P(0, s));
    while(!que.empty()){
        P p = que.top();que.pop();
        long v = p.second;
        if(d[v] < p.first) continue;
        for(long i = 0; i < G[v].size(); i++){
            edge e = G[v][i];
            if(d[v] + e.cost < d[e.to]){
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

int main(){
    long M;//辺の数
    long S, T;
    cin >> N >> M;
    cin >> S >> T;
    S--;
    T--;
    for(long i = 0; i < M; i++){
        long u, v, d;
        cin >> u >> v >> d;
        u--;
        v--;
        edge e1, e2;
        e1.to = v; e1.cost = d;
        e2.to = u; e2.cost = d;
        G[u].push_back(e1);
        G[v].push_back(e2);
    }
    dijkstra(S, ds);
    dijkstra(T, dt);
    long dist = ds[T];
    //cout << "dist end to end " << dist << endl; 
    for(int i = 0; i < N; i++){
        //cout << "dist_s " << i << ' ' << ds[i] << ' ' << dt[i] << endl; 
        if(ds[i]+dt[i] == dist) {
            can_use[i] = true;
            //cout << "can use " << i << endl;
        }
        else {
            can_use[i] = false;
            //cout << "can not use " << i << endl;
        }
    }
    cnt_t[T] = 1;
    cnt_s[S] = 1;
    priority_queue<P, vector<P>, greater<P>> que;
    for(int i = 0; i < N; i++) que.push(P(ds[i], i));
    while(!que.empty()){
        P top = que.top();
        que.pop();
        //if(!can_use[top.second]) continue;
        //cout << "cnt_s " << top.second << ' ' << cnt_s[top.second] << endl;
        for(int i = 0; i < G[top.second].size(); i++){
            if(ds[G[top.second][i].to] == ds[top.second]+G[top.second][i].cost){
                cnt_s[G[top.second][i].to] += cnt_s[top.second];
                cnt_s[G[top.second][i].to] %= MOD;
            }
        }
    }
    for(int i = 0; i < N; i++) que.push(P(dt[i], i));
    while(!que.empty()){
        P top = que.top();
        que.pop();
        //if(!can_use[top.second]) continue;
        //cout << "cnt_t " << top.second << ' ' << cnt_t[top.second] << endl;
        for(int i = 0; i < G[top.second].size(); i++){
            if(dt[G[top.second][i].to] == dt[top.second]+G[top.second][i].cost){
                cnt_t[G[top.second][i].to] += cnt_t[top.second];
                cnt_t[G[top.second][i].to] %= MOD;
            }
        }
    }
    long cnt_total = (cnt_s[T]*cnt_t[S])%MOD;
    long ans = 0;
    for(int i = 0; i < N; i++){
        if(2*ds[i] < dist && can_use[i]){
            for(int j = 0; j < G[i].size(); j++){
                if(2*ds[G[i][j].to] > dist && can_use[G[i][j].to] && ds[G[i][j].to] == ds[i]+G[i][j].cost){
                    ans += (((cnt_s[i]*cnt_t[G[i][j].to])%MOD)*((cnt_s[i]*cnt_t[G[i][j].to])%MOD))%MOD;
                    ans %= MOD;
                    //cout << i << ' ' << G[i][j].to << endl;
                    //cout << cnt_s[i] << ' ' << cnt_t[G[i][j].to] << endl;
                }
            }
        }else if(2*ds[i] == dist && can_use[i]){
            //cout << i << endl;
            ans += (((cnt_s[i]*cnt_t[i])%MOD)*((cnt_s[i]*cnt_t[i])%MOD))%MOD;
            ans %= MOD;
        }
    }
    ans = ((cnt_total-ans)%MOD+MOD)%MOD;
    cout << ans << endl;
}