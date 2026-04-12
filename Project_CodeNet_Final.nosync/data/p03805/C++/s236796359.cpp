#include<iostream>
#include<vector>
using namespace std;

bool graph[10][10];
bool visited[10], all_visited;//グローバル宣言すると0で初期化される
//この場合はfalse


int dfs(int v,int n) {
	visited[1] = true;//始点なので
	all_visited = true;//すべての頂点を通ったかを判別する変数
	for (int i = 1; i <= n; ++i) {
		if (visited[i] == false) {
			all_visited = false;//１つでも通っていなければダメ
		}
	}
	if (all_visited)return 1;//ここは1つの試行で（スタートからゴールまでの行き方の一つを１試行とする）1度しか判定されるチャンスがない。すなわちゴールの頂点がvと
	//なるときのdfs(それ以外ではall_visited=falseであるから)なおそのときに通り逃した頂点があると判定されない
	int sum = 0;//ゴールの頂点以外のdfsでは0,ゴールの頂点でも通り逃した頂点があるとsum=0になる。そのとき、ゴールの頂点以外の頂点でのdfsはここを通り過ぎており、
	//もう通らないからその試行での値は0、最大でも１つの試行では１しかとらないこともわかる(当たり前)
	for (int i = 1; i <= n; ++i) {
		if (visited[i])continue;
		if (graph[v][i]) {
			visited[i] = true;
			sum += dfs(i, n);
			visited[i] = false;
		}
	}
	return sum;
}

int main() {
	int n, m,a,b;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> a>>b;
		graph[a][b] = true;
		graph[b][a] = true;
	}
	cout << dfs(1,n) << endl;
	return 0;
}