#include <bits/stdc++.h>
using namespace std;
#define INF (1 << 29)

struct edge { int to, cost; };
typedef pair<int, int> P;   // firstは最短距離、secondは頂点の番号

const int MAX_V=1000;

int V;
vector<int> G[MAX_V];
int d[MAX_V];
int cnt=0;

void dfs(int s, bool f[], int d){
    //cout << s <<" "<< d << endl;
    if(d==V-1){
        bool F=true;
        for(int i=0; i<V; i++){
            if(f[i]==false){
                F = false;
            }
        }
        if(F) cnt++;
        return;
    }
    
    for(int i=0; i<G[s].size(); i++){
        if(f[G[s][i]]!=true){
            f[G[s][i]]=true;
            dfs(G[s][i], f, d+1);
            f[G[s][i]]=false;
        }
    }
}

int main(){
    int E;
    int from, to;
    cin >> V >> E;
    for(int i=0; i<E; i++){
        cin >> from >> to;
        G[from-1].push_back(to-1);
        G[to-1].push_back(from-1);
    }
    bool f[8]={0};
    f[0]=true;
    dfs(0, f, 0);
    
    cout << cnt << endl;
    return 0;
}
