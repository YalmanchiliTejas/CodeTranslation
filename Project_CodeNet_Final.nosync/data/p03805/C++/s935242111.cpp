#include <bits/stdc++.h>   
#define rep(i, n) for(long long int i = 0; i < n; i++)
#define _rep(i, m, n) for(long long int i = m; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll mod = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
     
ll gcd(ll A, ll B){
    if(B == 0)return A;
    return gcd(B, A % B);
}
ll lcm(ll A, ll B){
    return A * B / gcd(A, B);
}
using Graph = vector<vector<int>>;
Graph G;

void dfs(const Graph &G, int v, vector<bool> &seen, int &ans){
    bool flag = true;

    for(int i = 0; i < seen.size(); i++){
        if(!seen[i] and i != v) flag = false;
    }

    if(flag){
        ans++;
        return;
    }

    seen[v] = true;
    for(auto next_v : G[v]){
        if(seen[next_v]) continue;
        dfs(G, next_v, seen, ans);
    }
    seen[v] = false;
}

int main(){
    int n, m; cin >> n >> m;
    Graph G(n);

    rep(i, m){
        int a, b; cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<bool> seen(n, false);
    int ans = 0;

    dfs(G, 0, seen, ans);
    cout << ans << endl;
}