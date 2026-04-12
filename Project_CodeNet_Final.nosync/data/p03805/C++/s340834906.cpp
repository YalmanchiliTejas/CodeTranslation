#include <iostream>
#include<sstream>
#include<string>
#include<vector>
#include <cmath>
#include <limits>
#include <queue>
#include<algorithm>
#include<cstring>
#include <cstdlib>
#include <cstdio>
#include <set>
 
using namespace std;
 
#define rep(i,n) for (int (i)=0;(i)<(n);i++)
const int nmax = 8;
bool G[nmax][nmax];


int dfs(int v, int n, bool visited[nmax]){
    bool all_visited = true;
    for (int i = 0; i < n; i++){
        if(!visited[i]){
            all_visited = false;
        }
    }
    if (all_visited) return 1;

    int ret = 0;

    for (int i = 0; i < n; i++){
        if (visited[i]) continue;
        if (G[v][i] == false) continue;

        visited[i] = true;
        ret += dfs(i,n,visited);
        visited[i] = false;
    }
    return ret;
}


int main(void){
    int n,m;
    cin >> n >> m;
    int a,b;
    rep(i,m){
        cin >> a >> b;
        G[a-1][b-1] = true;
        G[b-1][a-1] = true;
    }
    bool visited[nmax];
    rep(i,nmax) visited[i] = false;
    visited[0] = true;

    cout << dfs(0,n,visited) << endl;

    return 0;
}