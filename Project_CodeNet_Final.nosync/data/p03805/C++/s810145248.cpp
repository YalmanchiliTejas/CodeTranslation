#include <bits/stdc++.h>
using namespace std;

int ans = 0, N, M;
vector<int> E[9];
bool seen[9];

void dfs(int u = 1, int d = 0){
    if(d == N - 1){
        ans++;
    }
    vector<int>::iterator it;
    for(it = E[u].begin(); it != E[u].end(); it++){
        int v = *it;
        if(!seen[v]){
            seen[v] = true;
            dfs(v, d + 1);
            seen[v] = false;
        }
    }
    return;
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        E[a].push_back(b);
        E[b].push_back(a);
    }
    fill(seen, seen + N + 1, false);
    seen[1] = true;
    dfs();
    cout << ans << endl;
    return 0;
}