/**
*    created: 09.05.2020 11:15:22
**/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int inf =1000000000;
using Graph = vector<vector<int>>;
vector<bool> seen;
int N, M, ans = 0;
vector<int> a, b;
//Graph取得時各頂点の値-1
void dfs(const Graph G,int v){
    seen[v] = true;

    bool ss = true;//ssは隣接する頂点すべて訪れたか
    for(int next_v:G[v]){
        ss &= seen[next_v];
    }
    if(ss)
    { //終端条件。ss:true&&sss:trueでans++
        bool sss = true;//sssは前頂点訪れたか
        rep(i,N) sss &= seen[i];
        if(sss) ans++;
        return;
    }

    for(int next_v:G[v]){
        if(seen[next_v]) continue;
        dfs(G, next_v);
        //seen更新。
        seen[next_v] = false;
    }
}

int main() {
    cin >> N >> M;
    a.resize(M), b.resize(M);
    Graph G(N);
    rep(i, M) {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
    }
    seen.assign(N, false);
    dfs(G, 0);
    cout << ans << endl;
}