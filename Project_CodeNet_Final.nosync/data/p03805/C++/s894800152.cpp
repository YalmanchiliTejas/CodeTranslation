#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, M;
vector<int> G[10];
bool visited[10];
int ans = 0;

void dfs(int v, int cnt) {
    if (cnt == N-1) {
        ans++;
        return;
    }
    
    for (int i = 0; i < G[v].size(); i++) {
        if (!visited[G[v][i]]) {
            visited[G[v][i]] = true;
            dfs(G[v][i], cnt+1);
            visited[G[v][i]] = false;
        }
    }
    return;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    memset(visited, false, sizeof(visited));
    visited[1] = true;

    dfs(1, 0);

    cout << ans << endl;
    
    return 0;
}
