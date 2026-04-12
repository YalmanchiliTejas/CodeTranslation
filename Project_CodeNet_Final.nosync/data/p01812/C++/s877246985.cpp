#include <bits/stdc++.h>
using namespace std;

int N, M, K;
vector<vector<vector<int>>> rV;
int utod[100];
int sD[100];
int dist[1<<16];

int bfs(){
    memset(dist, -1, sizeof(dist));
    queue<int> que;
    
    dist[0] = 0;
    que.push(0);
    
    while(!que.empty()){
        int s = que.front(); que.pop();
        if(s == (1<<M)-1)
            return dist[s];
        
        for(int i=0; i<K; i++){
            int t = 0;
            for(int u=0; u<N; u++){
                if(!sD[u]){
                    // light
                    for(auto v: rV[u][i])
                        t |= 1<<v;
                }else{
                    // dark
                    if(((s>>utod[u]) & 1) == 0)
                        continue;
                    for(auto v: rV[u][i])
                        t |= 1<<v;
                }
            }
            if(dist[t] == -1){
                dist[t] = dist[s] + 1;
                que.push(t);
            }
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> M >> K;
    
    for(int i=0; i<M; i++){
        int d;
        cin >> d; d--;
        utod[d] = i;
        sD[d] = true;
    }
    rV.resize(N);
    for(int i=0; i<N; i++)
        rV[i].resize(K);
    
    for(int i=0; i<N; i++){
        for(int j=0; j<K; j++){
            int v;
            cin >> v; v--;
            if(!sD[i])
                continue;
            rV[v][j].push_back(utod[i]);
        }
    }
    
    cout << bfs() << endl;
    return 0;
}