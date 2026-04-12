#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m,ans=0;
vector<int> g[10];
bool seen[10];


void dfs(int v){
    seen[v] = true;
    bool ok = true;
    for(int i=0;i<n;i++){
        if(!seen[i]){
            ok = false;
            break;
        }
    }
    if(ok) ans++;
    for(auto nv : g[v]){
        if(seen[nv]) continue;
        dfs(nv);
        seen[nv] = false;
    } 
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0);
    cout << ans << endl;
    return 0;
}