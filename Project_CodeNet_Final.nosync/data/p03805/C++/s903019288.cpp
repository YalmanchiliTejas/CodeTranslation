#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
typedef long long ll;

vector<bool> eratosthenes(int n) {
	vector<bool> prime(n + 1);
	for (int i = 2; i <= n; i++) {
		prime[i] = true; // 初期化
	}
	prime[0] = prime[1] = false;
	for (int i = 2; i*i <= n;i++) {
		if (prime[i]) {
			for (int j = i * 2; j <= n; j += i) {
				prime[j] = false;
			}
		}
	}
	return prime;
}
int n, m,p[10], ans = 0,a[29], b[29];
const int nmax = 8;
bool graph[nmax][nmax];
/**
 * pos個は決定済み
 * mask 残に置く数の集合を表すビット配列
 */
void dfs(int pos, int mask) {
//	cout << "pos=" << pos << ",mask=" << mask << endl;
	if (pos == n) { // posが最後までいった
//		cout << p[0] << p[1] << p[2] << endl;
		return;
	}
	REP(i, n) {
		if (mask  & (1 << i)) { // 残の中にiが残っている場合
//			cout << "mask=" << mask << ",1<<" << i << "="  << (1 << i) << "=true" << endl;
			p[pos] = i; // 配列のPOS位置を0～nまでループ
			if (p[0] != 0)continue;
			if (pos > 0 && graph[p[pos - 1]][p[pos]] == false) {
				//				cout << "pos=" << pos << "," << p[0] << p[1] << p[2] << ",graph[" << p[pos - 1] << "][" << p[pos] << "]=false" << endl;
				continue;
			}
			dfs(pos + 1, (mask ^ (1 << i))); // 配列のPOS位置を進める,排他的論理和でフラグを下ろす
		}
		else {
//			cout << "mask=" << mask << ",1<<" << i << "=" << (1 << i) << "=false" << endl;
		}
	}
}
/*int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	scanf("%d %d", &n ,&m);

	REP(i, m) {
		scanf("%d %d",&a[i], &b[i]);
		p[i] = i;
		graph[a[i] - 1][b[i] - 1] = graph[b[i] - 1][a[i] - 1] = true;
	}

	dfs(0, (1 << n) - 1);
	cout << ans << endl;
	return 0;
}*/
/**
 * v 現在の頂点
 */
int dfs(int v, int n, bool visited[]) {
	bool all_visited = true; // 全頂点を訪問済
	REP(i, n) {
		if(!visited[i])all_visited = false;
	}
	if (all_visited)return 1; //答を1増やす
	int ret = 0;
	REP(i, n) { //頂点i:頂点vに隣接、且つ、未訪問
		if (!graph[v][i])continue;
		if(visited[i])continue;

		visited[i] = true;
		ret += dfs(i, n, visited);
		visited[i] = false;
	}
	return ret;
}
int main() {
	scanf("%d %d", &n, &m);

	int A, B;
	for (int i = 0; i < m; ++i) {
		scanf("%d %d", &A, &B);
		graph[A - 1][B - 1] = graph[B - 1][A - 1] = true;
	}
	
	bool visited[nmax];
	for (int i = 0; i < n; ++i) {
		visited[i] = false;
	}
	
	visited[0] = true;
	cout << dfs(0, n, visited) << endl;
	return 0;

}
