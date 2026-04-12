#include <utility>
#include <vector>
#include <iostream>
#include <cstdlib>
#include<bits/stdc++.h>
#include <limits>
#include <set>
#define REP(i,n) for(int i=0;i<n;i++)
typedef unsigned long ul;
using namespace std;

const int nmax=8;
bool graph[nmax][nmax];

int dfs(int v, int N, bool visited[nmax]){
    bool all_visted=true;
    for(int i = 0; i < N; i++){
        if(visited[i] == false){
            all_visted = false;
        }
    }

    if(all_visted){
        return 1;
    }

    int ret =0;

    for(int i = 0; i < N; i++){
        if(graph[v][i] == false)continue;
        if(visited[i]) continue;

        visited[i] = true;
        ret+=dfs(i, N, visited);
        visited[i] = false;
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    int a, b;
    REP(i, M){
        cin >> a >> b;
        graph[a-1][b-1] = true;
        graph[b-1][a-1] = true;
    }
    bool visited[N];
    REP(i, N) visited[i] = false;
    visited[0] = true;
    int ans = dfs(0,N,visited);
    cout << ans << endl;
    return 0;
}