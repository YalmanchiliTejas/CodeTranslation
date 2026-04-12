#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define MOD (1000000007)
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1}; // 移動方向

int n,m;
int a[9],b[9];
bool visited[9] = {false};
bool graph[9][9];

void input(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        graph[a-1][b-1] = true;
        graph[b-1][a-1] = true;
    }
}
// 引数に現在の頂点を取る
int dfs(int cur){
    bool allvisited = true;
    for(int i=0;i<n;i++){
        if(visited[i]==false) allvisited = false;
    }
    if(allvisited) return 1;
    int ret = 0;
    for(int i=0;i<n;i++){
        if(graph[cur][i]==false) continue;
        if(visited[i]) continue;

        visited[i] = true;
        ret += dfs(i);
        visited[i] = false;
    }
    return ret;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    input();
    visited[0] = true;
    cout << dfs(0) << endl;
}