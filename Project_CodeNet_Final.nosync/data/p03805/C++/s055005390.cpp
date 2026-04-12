// 054 AGC C - One-stroke Path 2017/02/11

#include <bits/stdc++.h>
#define rep(i ,n) for(int i=0;i<(int)(n);++i)
using namespace std;
typedef long long int int64;
typedef unsigned long long uint64;

bool Graph[8][8] = {false};

int dfs(int x, int n , bool* visited){
    bool all_visited = true;
    rep(i ,n){
        if(visited[i] == false) all_visited = false;
    }
    if (all_visited) return 1;

    int ret = 0;
    for(int i=1;i<n;++i){
        if( Graph[x][i] == false ) continue;
        if( visited[i] == true ) continue;
        visited[i] = true;
        ret+=dfs(i , n , visited);
        visited[i] = false;
    }
    return ret;
}

int main(){
    int n , m; cin >> n >> m;
    bool visited[8]={false};
    rep(i ,m){
        int a , b;
        cin >> a >> b;
        Graph[a-1][b-1] = true;
        Graph[b-1][a-1] = true;
    }
    visited[0]=true;
    cout << dfs(0,n,visited) << endl;
}