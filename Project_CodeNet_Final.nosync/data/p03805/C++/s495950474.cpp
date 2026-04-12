#include <bits/stdc++.h>
#define int long
#define ll long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define IOS cin.tie(0); ios::sync_with_stdio(false)
using namespace std;
int N,M; bool G[10][10];

int dfs(int v,int n,bool visited[10]){
    bool alvisited = true;
    rep(i,n) if(!visited[i]) {alvisited=false; break;}
    if(alvisited) return 1;
    int res=0;
    rep(i,n) {
        if(!G[v][i] || visited[i]) continue;
        visited[i]=true;
        res+=dfs(i,n,visited);
        visited[i]=false;
    }
    return res;
}

main() {
    cin >> N >> M;
    rep(i,M){
        int a,b; cin >> a >> b;
        a--; b--;
        G[a][b]=true;
        G[b][a]=true;
    }
    bool visited[N]; rep(i,N) visited[i]=false;
    visited[0]=true;
    cout << dfs(0,N,visited) << endl;
}