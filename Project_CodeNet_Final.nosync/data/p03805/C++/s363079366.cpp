#include<bits/stdc++.h>

using namespace std;

// 答え, 頂点数, 辺の本数, 始点の配列, 終点の配列, 訪れた頂点数
int ans, N, M, a[28], b[28], num_visted;
// 隣接リスト
vector< vector<int> > G;
// 訪問済み頂点
vector<bool> visted;

// 深さ優先探索
void dfs(int now){
	visted[now] = true;
	num_visted++;
	if(num_visted == N) ans++;
	for(int i = 0; i < G[now].size(); ++i){
		if(!visted[G[now][i]]) dfs(G[now][i]);
	}
	visted[now] = false;
	num_visted--;
}

int main(){
	// 入力
	cin >> N >> M;
	for(int i = 0; i < M; ++i) cin >> a[i] >> b[i];
	// 訪問済み頂点の初期化
	visted = vector<bool>(N, false);
	// 入力から隣接リストに変換
	G = vector< vector<int> >(N);
	for(int i = 0; i < M; ++i){
		G[a[i]-1].push_back(b[i]-1);
		G[b[i]-1].push_back(a[i]-1);
	}
	// 再帰
	dfs(0);
	// 答えを出力
	cout << ans << endl;
}