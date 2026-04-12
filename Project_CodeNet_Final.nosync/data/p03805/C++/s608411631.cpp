#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define REPS(i,x) for(int i=1;i<=(int)(x);i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RREPS(i,x) for(int i=((int)(x));i>0;i--)
const ll mod = 1e9 + 7;
typedef pair<int,int>           PI;
typedef pair<ll,ll>             PL;
typedef vector<PI>               vip; 
typedef vector<int>             vi;
typedef vector<vi>              vvi;
typedef vector<ll>              vl;
typedef vector<vl>              vvl;
    
bool graph[8][8];

int dfs(int v, int n, bool visited[8]){
    bool all_visited = true;
    for(int i = 0; i < n; i++){
        if(visited[i] == false)
            all_visited = false;
    }

    if(all_visited){
        return 1;
    }

    int ret = 0;
    for(int i = 0; i < n; i++){
        if(graph[v][i]==false) continue;
        if(visited[i]) continue;
        visited[i]=true;
        ret+=dfs(i,n,visited);
        visited[i]=false;
    }

    return ret;
}






int main (){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    REP(i,m){
        int a,b;
        cin >> a >> b;
        a--; b--;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }
    bool visited[8];
    REP(i,n){
        visited[i] = false;
    }

    visited[0] = true;
    cout << dfs(0,n,visited) << endl;




    return 0;
}