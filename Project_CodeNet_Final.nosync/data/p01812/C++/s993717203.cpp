#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<double, double> P;
constexpr int IINF = INT_MAX;


int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> d(m), id(n, -1), dist(1<<m);
    vector<vector<int> > v(n, vector<int>(k)), graph(1<<m);
    for(int i=0;i<m;i++){
        cin >> d[i];
        d[i]--;
        id[d[i]] = i;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            cin >> v[i][j];
            v[i][j]--;
        }
    }
    // i番目の暗い部屋にいるかをbitで持った状態を頂点、指示による遷移を辺とする
    for(int S=1;S<(1<<m);S++){
        for(int j=0;j<k;j++){
            int T = 0;
            for(int i=0;i<m;i++){
                if(((S>>i)&1) && id[v[d[i]][j]] >= 0){
                    T |= 1<<id[v[d[i]][j]];
                }
            }
            graph[S].push_back(T);
        }
    }
    // BFS
    fill(dist.begin(), dist.end(), IINF);
    dist[(1<<m)-1] = 0;
    queue<int> que;
    que.push((1<<m)-1);
    while(!que.empty()){
        int v = que.front();
        que.pop();
        for(auto u : graph[v]){
            if(dist[u] == IINF){
                dist[u] = dist[v] + 1;
                que.push(u);
            }
        }
    }
    cout << dist[0] << endl;
    return 0;
}

