#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const ll MOD = 1000000007;

bool visited[10];
int cnt;
int N, M;
vector<vector<int>> G;

int dfs(int v){
    if(cnt == N-1) return 1;
    visited[v] = true;
    int ret = 0;
    for(int to: G[v]){
        if(!visited[to]){
            cnt++;
            ret += dfs(to);
            cnt--;
        }
    }
    visited[v] = false;
    return ret;
}

int main(){
    cin >> N >> M;

    G.assign(N, vector<int>());
    for(int i=0;i<M;i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    cnt = 0;
    memset(visited, 0, sizeof(visited));
    cout << dfs(0) << endl;

    return 0;
}