#include <bits/stdc++.h>
#define loop2(i, s, n, a) for (int i = int(s); i < int(n); i += a)
#define loop(i, s, n) loop2(i, s, n, 1)
#define rep(i, n) loop(i, 0, n)

#define pb push_back
#define all(in) in.begin(),in.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;

void dfs(int v, int n, vector<vector<int>> G, vector<bool> &used, int &count, int &depth){
    used[v] = true;
    depth++;
    if(depth == n) count++;
    else if(depth < n){
        for(auto nv : G[v]){
            if(used[nv] == false) { dfs(nv, n, G, used, count, depth); }
        }
    }
    used[v] = false;
    depth--;
    return;
}

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> G(n);
    rep(i,m){
        int a, b; cin >> a >> b;
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);
    }
    
    vector<bool> used(n,false);
    int count = 0;
    int depth = 0;
    dfs(0, n, G, used, count, depth);
    cout << count << endl;
}