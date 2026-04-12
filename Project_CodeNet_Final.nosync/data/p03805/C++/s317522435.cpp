#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int INF = 1001001001;
const int mod = 1000000007;

/*
 * seenとwaitを渡して探索地点がなくなるまで再起関数を回す
 */

//N:頂点の数，M:辺の数
int N, M;
int cnt = 0;

vector<vector<int>> v(10,vector<int>(10));
vector<int> used;


int dfs(int now, int depth){
    // すでに訪れた頂点なら終了する
    if(used[now] == 1) return 0;

    // depthがNなら有効なパスなので1を返す
    if(depth == N) return 1;

    // 使用済みのフラグを立てる
    used[now] = 1;

    int ans = 0;

    // 全部の遷移先をチェックする
    for(int i = 0; i < N; i++){
        // nowから繋がっている頂点であれば，遷移を写す
        if(v[now][i]){
            ans += dfs(i, depth + 1);
        }
    }
    // 使用済みフラグを折る
    used[now] = 0;
    return ans;
}


int main() {
    cin >> N >> M;
    rep(i, M){
        int a, b;
        cin >> a >> b;
        --a; --b;
        v[a][b] = v[b][a] = 1;
    }
    used = vector<int>(N, 0);

    cout << dfs(0, 1) << endl;
    return 0;

}
