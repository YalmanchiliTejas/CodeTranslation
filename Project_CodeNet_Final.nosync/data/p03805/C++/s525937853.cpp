#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
vector<int> G[10];
vector<bool> seen(10, false);

int dfs(int from, int now){
    seen[now]=true;
    bool all_visit=true;
    for(int i=0; i<n; ++i) if(!seen[i]) all_visit=false;
    if(all_visit){
        seen[now]=false;
        return 1;
    }

    int ret=0;
    for(auto to:G[now]){
        if(!seen[to] && to!=from) ret+=dfs(now, to);
    }

    seen[now]=false;
    return ret;
}

int main(){
    cin >> n >> m;
    for(int i=0; i<m; ++i){
        int a, b; cin >> a >> b;
        --a; --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    cout << dfs(-1, 0) << '\n';
    return 0;
}