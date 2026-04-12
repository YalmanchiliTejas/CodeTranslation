
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define REVERSE(v,n) reverse(v,v+n);
#define VREVERSE(v) reverse(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
#define INF 9999999

using namespace std;

typedef pair<int, int> P;

int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };

const int nmax = 8;
//接続状況を格納する隣接行列
bool graph[nmax][nmax];

//パスを全探索する関数
// v:今いる頂点
// N:頂点の数
int dfs(int v, int N, bool visited[nmax]) {
	//すべての頂点に訪れたかどうかのフラグ
	bool all_visited = true;
	//一つでも訪れていない頂点があればfalseにする
	for (int i = 0; i < N; i++) {
		if (visited[i] == false)all_visited = false;
	}

	//すべての頂点に訪れていれば有効なパスなので1を返す
	if (all_visited) {
		return 1;
	}

	int ret = 0;

	//すべての遷移先について調べる
	for (int i = 0; i < N; i++) {
		//頂点iが接続されていない、あるいはすでに訪れていればi+1に移る
		if (graph[v][i] == false)continue;
		if (visited[i])continue;
		//iに遷移する
		visited[i] = true;
		//iからの遷移を試す
		ret += dfs(i, N, visited);
		//iのフラグを取り消す
		visited[i] = false;
	}
	return ret;
}

int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		//接続状況の入力
		//無向グラフなので両方向からの接続をtrueにする
		graph[A - 1][B - 1] = graph[B - 1][A - 1] = true;
	}
	bool visited[nmax];
	//visitedをfalseで初期化する
	for (int i = 0; i < N; i++) {
		visited[i] = false;
	}

	visited[0] = true;
	//頂点0から始まるパスの数を出力する
	cout << dfs(0, N, visited) << endl;
	return 0;
}
