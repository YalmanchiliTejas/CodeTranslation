#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(),(v).end()
const int INF = 1e9;
typedef long long ll;
typedef pair<ll, ll> P;

int N, M;
vector<int> visited;
vector<vector<int>> G;
int num_visited = 0;
int ans = 0;

void dfs(int now){
    visited[now] = 1;
    num_visited++;
    //すべての頂点を訪れたなら
    if(num_visited == N){
        ans++;
    }
    for(int i=0;i<G[now].size();i++){
        int next = G[now][i];
        if(!visited[next]) dfs(next);

    }
    visited[now] = 0;
    num_visited--;
}

int main() {
    cin >> N >> M;
    G = vector<vector<int>> (N); //サイズを確保する
    visited = vector<int> (N,0);
    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    //頂点番号0からDFSを始める
    dfs(0);
    cout << ans << endl;
}