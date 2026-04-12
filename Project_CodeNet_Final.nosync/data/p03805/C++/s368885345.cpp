#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
#define all(v) v.begin(), v.end()
using ll = long long;
using P = pair<int, int>;
const int inf = 1000000000; //10^9
const ll MOD = 1e9 + 7;
//加算代入演算子は+=！！！！！
//int 2^31 10^9まで

vector<vector<int>> G;

void dfs(int v, vector<bool> &seen, int &res) // 0、チェック済み配列、まずは0
{
    bool end = true; // 終了フラグ
    for (int i = 0; i < seen.size(); i++) //チェック済み配列の長さ分最大N繰り返す
        if (!seen[i] && i != v) //もしチェック済みじゃなくて、かつ、iがvじゃなければ
            end = false; //終了しない
    if (end) //チェック済みなら
    {
        ++res; //終了する場合はカウンタを加算して返す
        return;
    }

    seen[v] = true; // v を訪問済にする
    for (auto next_v : G[v]) // v から行ける各頂点 next_v について
    {
        if (seen[next_v]) // next_v が探索済だったらスルー
            continue;
        dfs(next_v, seen, res); // 再帰的に探索
    }
    seen[v] = false; //v番目をfalseにする
}

int main()
{
    int N, M; //N頂点、M辺
    cin >> N >> M;
    G.assign(N, vector<int>()); //N個のint型の配列を入れる
    // 各辺と頂点の関係性の表の作成。下記のように各頂点と線でつながってる頂点の表ができる。
    // G[0] {1, 3}
    // G[1] {0, 3}
    // G[2] {0, 1}
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        --a, --b; //配列の0スタートに合わせてる
        G[a].push_back(b);
        G[b].push_back(a); //無向グラフのため
    }
    vector<bool> seen(N, false); //チェック済みの頂点を格納してる配列 初期値はN個のfalse
    int res = 0;
    dfs(0, seen, res); // 頂点 0 をスタートとした探索
    cout << res << endl;
}