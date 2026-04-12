#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i < (n);i++)
typedef long long ll;
typedef pair<int,int> P;
const int MOD = 1000000007;
const int nmax = 8;
bool graph[nmax][nmax];

int dfs(int now, int n,bool visited[]){
    bool all_visited = true;
    visited[now] = true;
    //全てのノートを通ったパスを発見した時の分岐条件
    rep(i,n){
        if(visited[i] == false)all_visited = false;
    }
    if(all_visited)return 1;

    int rtn = 0;
    rep(i,n){
        if(graph[now][i] == false)continue;
        if(visited[i])continue;
        rtn += dfs(i,n,visited);
        //なぜfalseにする？
        visited[i] = false;
    }
    return rtn;
}


int main(){
    int n,m;
    cin >> n >> m;
    rep(i,m){
        int a,b;
        cin >> a >> b;
        graph[a-1][b-1] = true;
        graph[b-1][a-1] = true;
    }

    bool visited[n];
    rep(i,n)visited[i] = false;
    int ans = dfs(0,n,visited);
    cout << ans << endl;
    return 0;
}