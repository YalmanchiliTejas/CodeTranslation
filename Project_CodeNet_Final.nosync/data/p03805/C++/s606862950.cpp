#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<int, int> P;
const int inf = INT_MAX;
const ll INF = 1LL << 60;
const ll mod = 1e9+7;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

// 054c

int n, m;
vector<int> adj[10];
int ans=0;

void dfs(int v, vector<bool> visited){
    bool flag = true;
    visited[v] = true;
    rep(i, n){
        flag = false;
        if(!visited[i]){
            flag = true;
            break;
        }
    }

    if (flag){
        rep(i, adj[v].size()){
            int nv = adj[v][i];
            if (visited[nv]) continue;
            dfs(nv, visited);
        }
    }else{
        ans++;
    }
}

int main(){
    cin >> n >> m;
    rep(i, m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<bool> visited(n);
    rep(i, n) visited[i] = false;
    dfs(0, visited);

    cout << ans << endl;
    return 0;
}
