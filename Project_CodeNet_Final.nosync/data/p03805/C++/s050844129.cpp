#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
int res;
int N, M;
vector<vector<int> > e;
vector<int> visited;
void dfs(int a ,int depth) {
	if (depth == N - 1) {
		res++;
	}
	visited[a] = 1;
	for (int i = 0; i < e[a].size(); i++) {
		if (visited[e[a][i]] == 0) {
			dfs(e[a][i], depth + 1);
		}
	}
	visited[a] = 0;
}
signed main() {

	cin >> N >> M;
	e.resize(N);

	int A, B;
	for (int i = 0; i < M; i++) {
		cin >> A >> B;
		A--;
		B--;
		e[A].push_back(B);
		e[B].push_back(A);
	}
	int i;
	visited.resize(N, 0);
	dfs(0, 0);
	cout << res << endl;
	return 0;

}