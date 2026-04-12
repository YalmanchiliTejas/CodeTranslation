#include <bits/stdc++.h>
// #include <cmath>
// #include <numeric>
// #include <regex> //正規表現
using namespace std;
#define rep(i,a,b) for(int i=(a); i<(b); ++i) // a ≦ i < b 
#define Rrep(i,a,b) for(int i=(a);i>=(b);--i) // reverse repeat. a から b まで減少．
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend() //逆イテレータ
#define RANGE(a,b,c) (a).begin()+b,(a).begin()+c // コンテナ a の 要素 b から c へのイテレータ
#define MOD 1000000007ll
#define INF 1000000000
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef vector<PII> VP;
// グリッドグラフの移動ベクトル
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

void dfs(map<int, set<int>> &G, vector<bool> seen, int &cnt, int len, int node){
    seen[node] = true;
    ++len;
    if (len == seen.size() - 1) {
        ++cnt; 
        return;
    }
    for (int v : G[node]){
        if (seen[v]) continue;
        dfs(G, seen, cnt, len, v);
    }
}

int main() {
cin.tie(0);
ios::sync_with_stdio(false);

int N, M; cin >> N >> M;
int a, b; 
map<int, set<int>> map;
rep(i, 0, M) {
    cin >> a >> b;
    map[a].insert(b);
    map[b].insert(a);
}

vector<bool> seen(N+1, false);
int cnt = 0, len = 0;

dfs(map, seen, cnt, len, 1);


cout << cnt << endl;
}

// 境界，出力文字列 チェック

