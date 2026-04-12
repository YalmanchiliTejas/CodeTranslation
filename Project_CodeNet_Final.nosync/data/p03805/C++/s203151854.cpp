#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<bool>> G(8, vector<bool>(8));
vector<bool> seen(N, false);
int Vis = 0;
int ans = 0;

void dfs(int now){
    seen[now] = true;
    Vis++;
    if(Vis == N){
        ans++;
        Vis--;
        seen[now] = false;
        return;
    }
    
    
    for(int next = 0; next < 8; next++){
        if(!seen[next] && G[now][next])dfs(next);
    }
    
    seen[now] = false;
    Vis--;
    return;
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a][b] = true;
        G[b][a] = true;
    }
    dfs(0);
    cout << ans << endl;
    return 0;
}
