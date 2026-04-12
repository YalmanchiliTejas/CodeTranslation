#include <bits/stdc++.h>

#include <math.h>
#include <stdlib.h>


#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true; } return false; }

// const int INF = 1001001001;
// long long max => LLONG_MAX

vector<vector<int>> graph;
int ans = 0;
vector<bool> visited;
int cnt;
int n, m;

void dfs(int v){
    visited[v] = true;
    cnt++;
    if(cnt == n){
        ans++;
        visited[v] = false;
        cnt--;
        return;
    }

    for(int nv : graph[v]){
        if(visited[nv]) continue;
        dfs(nv);
    }
    visited[v] = false;
    cnt--;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    cin >> n >> m;

    graph.resize(n);
    visited.resize(n);
    cnt = 0;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(0);

    cout << ans << endl;

    return 0;
}
