#include <bits/stdc++.h>
using namespace std;

const int64_t MOD = 1e9+7;
void add(int64_t& a, int64_t b){
    a = (a+b) % MOD;
}
void mul(int64_t& a, int64_t b){
    a = a*b % MOD;
}

typedef pair<int64_t, int64_t> P;
const int64_t INF = 1e18;

pair<vector<int64_t>, vector<int64_t>> dijkstra(int N, int s, vector<P> edges[]){
    vector<int64_t> dist(N, INF), num(N, 0);
    dist[s] = 0;
    num[s] = 1;
    priority_queue<P, vector<P>, greater<P>> que;
    que.push({0, s});
    while(que.size()){
        auto p = que.top(); que.pop();
        int i = p.second;
        int64_t d = p.first;
        if(d > dist[i]) continue;
        for(auto& e : edges[i]){
            int j = e.first;
            int64_t d2 = d + e.second;
            if(d2 == dist[j]){
                add(num[j], num[i]);
            }else if(d2 < dist[j]){
                num[j] = num[i];
                dist[j] = d2;
                que.push({d2, j});
            }
        }
    }
    return {dist, num};
}



int main(){
    int N, M, S[2];
    cin >> N >> M >> S[0] >> S[1];
    S[0]--; S[1]--;
    vector<P> edges[100000];
    for(int i=0; i<M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        edges[a].emplace_back(b, c);
        edges[b].emplace_back(a, c);
    }

    vector<int64_t> dist[2], num[2];
    for(int k=0; k<2; k++){
        auto res = dijkstra(N, S[k], edges);
        dist[k] = res.first;
        num[k] = res.second;
    }

    int64_t ans = num[0][S[1]] * num[0][S[1]] % MOD;
    int64_t D = dist[0][S[1]];
    for(int i=0; i<N; i++) if(dist[0][i] + dist[1][i] == D && 2*dist[0][i] == D){
        int64_t res = num[0][i] * num[1][i] % MOD;
        res = res*res % MOD;
        add(ans, MOD - res);
    }
    for(int i=0; i<N; i++) for(auto& e : edges[i]){
        int j = e.first, c = e.second;
        if(dist[0][i] + c + dist[1][j] == D && 2*dist[0][i] < D && 2*dist[1][j] < D){
            int64_t res = num[0][i] * num[1][j] % MOD;
            res = res*res % MOD;
            add(ans, MOD - res);
        }
    }
    cout << ans << endl;
}