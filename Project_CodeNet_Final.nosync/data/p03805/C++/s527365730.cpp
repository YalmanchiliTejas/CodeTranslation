#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};
const int INF = 1001001001;
int N,M;
vector<vector<bool>> graph;
vector<bool> reached;

int dfs(int v){
    bool all_reached = true;
    for(int i=0;i<N;i++){
        if(reached[i] == false) all_reached = false;
    }
    if(all_reached) return 1;

    int ret = 0;
    for(int i=0;i<N;i++){
        if(graph[v][i] == false) continue;
        if(reached[i]) continue;

        reached[i] = true;
        ret += dfs(i);
        reached[i] = false;
    }
    return ret;
}

int main(){
    cin >> N >> M;
    graph   = vector<vector<bool>>(N,vector<bool>(N,false));
    reached = vector<bool>(N);
    int x,y;
    for(int i=0;i<M;i++){
        cin >> x >> y;
        x--;y--;
        graph[x][y] = graph[y][x] = true;
    }
    reached[0] = true;
    cout << dfs(0) << endl;
}
