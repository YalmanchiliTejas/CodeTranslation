#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int n, m, adj[8][8] = {}, ans = 0;
bool use[8] = {};

// next_permutationを使わずに再帰で書く練習
void dfs(int par, int dep){
    if(dep == n){
        ans++;
        return;
    }
    for(int i = 0; i < n; i++){
        if(use[i] || adj[par][i]==0)  continue;
        use[i] = true;
        dfs(i, dep+1);
        use[i] = false;
    }
}

int main(){
    cin >> n >> m;
    int a, b;
    while(m-- > 0){
        cin >> a >> b;
        a--, b--;
        adj[a][b] = adj[b][a] = 1;
    }
    use[0] = true;
    dfs(0, 1);
    use[0] = false; // いらない
    cout << ans << endl;
    return 0;
}