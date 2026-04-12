#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define ll long long
#define vi vector<int>
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

int N, M, a, b, cnt = 0;
bool T[13][13];
vector<bool> visited;

int dfs(int u, int N, vector<bool> visited){
    bool all_visited = true;

    rep(i,N)
        if(!visited[i]) all_visited = false;

    if(all_visited) return 1;

    int ret = 0;
    
    rep(i,N){
        //パスがないまたは訪問済みなら飛ばす
        if(!T[u][i] || visited[i])
            continue; 
        // printf("Path from %d to %d exists\n", u, i);
        visited[i] = true;
        ret += dfs(i,N,visited); //iを訪問したことにしてdfs
        visited[i] = false; //戻して他の道でも試す
    }
    return ret;
}

int main(){
    cin >> N >> M;

    rep(i, M){
        cin >> a >> b; //0-indexに
        T[a-1][b-1] = T[b-1][a-1] = true;
    }
    visited.resize(N,false);
    visited[0] = true;
    cout << dfs(0, N, visited) << endl;
}
