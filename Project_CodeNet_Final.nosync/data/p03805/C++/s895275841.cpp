#include<bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a)  (a).begin(),(a).end()
#define pb push_back
#define ppb pop_back
#define INF 1e18
typedef long long ll;

using namespace std;

const int nmax = 8;

bool graph[nmax][nmax];

int dfs(int v, int N, bool visited[nmax]){
 
    bool all_visited = true;
 
    for(int i = 0; i < N; i++){
        if(visited[i] == false){
            all_visited = false;
            break;
        }
    }
 
    if(all_visited){
        return 1;
    }
 
    int ret = 0;
 
    for(int i = 0; i < N; i++){
        if(graph[v][i] == false) continue;
        if(visited[i]) continue;
 
        visited[i] = true;
        ret += dfs(i, N, visited);
        visited[i] = false;
    }
 
    return ret;
}

int main(int argc,char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N,M;
    cin>>N>>M;

    rep(i,M)
    {
        int A,B;
        cin>>A>>B;
        graph[A-1][B-1] = graph[B-1][A-1] = true;
    }

    bool visited[nmax];
    rep(i,N)
    {
        visited[0] = false;
    }

    visited[0] = true;

    cout<<dfs(0,N,visited)<<endl;

    return 0;
}