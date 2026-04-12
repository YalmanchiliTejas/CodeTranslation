#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for(int i=0;i<(int)n;i++)
#define PI acos(-1)
#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);
ll mod=1e9+7;

const int nmax=8;
int graph[nmax][nmax];

int dfs(int v, int N, bool visited[nmax]){
    bool all_visited=true;
    rep(i,N) if(visited[i]==false) all_visited=false;

    if(all_visited) return 1;
    int ret=0;

    rep(i,N){
        if(graph[v][i]==false) continue;
        if(visited[i]) continue;

        visited[i]=true;
        ret+=dfs(i, N, visited);
        visited[i]=false;
    }
    return ret;
}

int main(){
    fast_io

    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++){
        int A, B;
        cin>>A>>B;
        graph[A-1][B-1]=1;
        graph[B-1][A-1]=1;
    }
    bool visited[nmax];
    rep(i,n) visited[i]=false;
    visited[0]=true;

    cout<<dfs(0, n, visited)<<endl;
    return 0;
}