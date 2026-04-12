#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;

const int MAX = 1e5;
struct edge{
    int v; // 次の頂点.
    int w; // 距離.
    edge(int v, int w) : v(v), w(w) {}
};

vector<edge> adj[MAX]; // 隣接リスト
bool visited[MAX];
int LD[MAX]; // 各頂点の高さ

// グラフを深さ優先探索する.
// @param c: グラフの探索開始頂点.
// @param d: グラフの探索開始頂点からの距離を保存.
// @return: 特に無し.
void dfs(int c, int d) {
    // 1. 訪問済みならば, 終了.
    if(visited[c]) return;

    // 2. 訪問済みフラグ設定.
    visited[c] = true;
    
    // 3. 未訪問の頂点であれば, 距離を更新.
    LD[c] = max(LD[c], d);
    for(auto &e : adj[c]) if(!visited[e.v]) dfs(e.v, d + e.w);

}

int main(){
    
    // 1. 入力情報取得.
    int N; // 頂点数
    scanf("%d", &N);
    for(int i = 0; i < N - 1; ++i){
        int s, t, w;
        // s : from, t : to, w : cost
        scanf("%d %d %d", &s, &t, &w);
        adj[s].emplace_back(t, w);
        adj[t].emplace_back(s, w);
    }
    memset(LD, 0, sizeof(LD));
    
    // 2. 頂点の次数が, 1 のものに対して, 木の高さを計算.
    for(int r = 0; r < N; r++){
        if(adj[r].size() == 1){
            memset(visited, 0, sizeof(visited));
            dfs(r, 0);
        }
    }
    
    // 3. 出力 ～ 後処理.
    for(int r = 0; r < N; r++){
        printf("%d\n", LD[r]);
    }
    return 0;
}



