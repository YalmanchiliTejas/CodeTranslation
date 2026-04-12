#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod=1e9+7;

int visited[8];
int n[8][8];
int ans;
int N, M;

void dfs(int s, int cnt){
    if(cnt==N){
        ans ++;
        return;
    }
    visited[s]=1;
    for(int i=0; i<N; i++){
        if(n[s][i] && !visited[i]){
            dfs(i, cnt+1);
        }
    }
    visited[s]=0;
}

int main() {
    cin >> N >> M;
    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        n[a][b]=n[b][a]=1;
    }
    ans = 0;
    dfs(0, 1);
    cout << ans;
}