#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = (int)1e9 + 7;
const int INF = (int)100100100;
const int nmax=8;
bool graph[nmax][nmax]={};

int dfs(ll v,ll N,bool visited[nmax]){
    bool all_visited=true;
    for (int i = 0; i < N; i++){
        if(!visited[i])all_visited=false;
    }
    if(all_visited){
        return 1;
    }
    int ret=0;
    for(int i=0;i<N;i++){
        if (!graph[v][i])continue;
        if (visited[i])continue;
        visited[i]=true;
        ret+=dfs(i,N,visited);
        visited[i]=false;
    }

    return ret;
}
    
int main() {
    ll N,M;
	cin >> N >> M;
    //ll N; cin >> N;
    //string S; cin >> S;
    //ll H,W; cin >> H >> W;
    vector<vector<ll>> a(N);
    for(int i=0;i<M;i++){
        int x,y;
        cin >> x >> y;
        graph[x-1][y-1]=true;
        graph[y-1][x-1]=true;
    }

    bool visited[N]={};
    visited[0]=true;
    cout << dfs(0,N,visited) << endl;
}

/*



 */

