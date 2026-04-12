// C++(GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) repex(i, a, b, 1)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)
#define pb push_back

int main() {
    
    // 1. 入力情報取得.
    int N, M;
    scanf("%d %d", &N, &M);
    vvi G(N);
    rep(i, M){
        int a, b;
        scanf("%d %d", &a, &b);
        a--, b--;
        G[a].pb(b);
        G[b].pb(a);
    }
    
    // 2. 経路探索.
    // -> 頂点番号が, 1桁である場合の探索(※2桁以上は, 成立しない)
    int ans = 0;
    function<void(int, string, int)> dfs = [&](int s, string route, int N) {
        // 2-1. 終了条件.
        if(route.size() == N){
            ans++;
            return;
        }
        
        // 2-2. 次の頂点へ.
        int l = route.size();
        for(auto &u : G[s]){
            // すでに訪問済みか確認.
            bool ok = true;
            rep(i, l) if((route[i] - '0') == u) ok = false;
            
            // 未訪問の場合.
            if(!ok) continue;
            string nr = route + to_string(u);
            dfs(u, nr, N);
        }
    };
    dfs(0, "0", N);
    
    // 3. 出力.
    printf("%d\n", ans);
    return 0;
    
}