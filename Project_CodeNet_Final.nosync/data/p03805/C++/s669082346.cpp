#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define erep(i, n) for (ll i = 0; i <= (ll)(n); ++i)
#define FOR(i,a,b) for (ll i = (a); i < (ll)(b); ++i)
#define EFOR(i,a,b) for (ll i = (a); i <= (ll)(b); ++i)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } }

using Graph = vector<vector<int>>;
Graph G;


void dfs(int v, vector<bool> &seen, int &res) {
    // flag立てる
    bool end = true;

    rep(i,seen.size()) {
        // まだ到達していない頂点があれば、続ける
        // 自分自身のチェックはしないようにする
        if (!seen[i] && i != v) end = false;
    }
    if (end) {
        // 全ての頂点に到達すれば、このパスはおk
        ++res;
        return;
    }
    seen[v] = true;
    for (auto nv : G[v]) {
        // 自分からいける、かつまだ行ってない場所にいく
        if (seen[nv]) continue;
        dfs(nv, seen, res);
    }
    // 1つ前の頂点に戻るときに、自分自身を未到達に戻しておく
    // 例えば、1 -> 2 -> 3, 1 -> 3 -> 2という２通りがあるとして
    // 今が1 -> 2の2だとする, ここから戻って 1 -> 3と行ったときに
    // 3から2へ行こうとするとすでに2を通ってるだとダメなので
    seen[v] = false;
}

int main() {
    int n, m; cin >> n >> m;
    G.assign(n, vector<int>());
    rep(i, m) {
        int a, b; cin >> a >> b; --a, --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<bool> seen(n, false);
    int res = 0;
    dfs(0, seen, res);
    cout << res << endl;
}
