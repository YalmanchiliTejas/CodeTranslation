#include <bits/stdc++.h>
using namespace std;

int N, col1, col2;
bool meow[100005];
vector<int> V[100005];

void dfs(int x, int p, int col) {
	if (col == 0) col1++;
	else col2++;
	for (int i = 0; i < V[x].size(); i++) if (p != V[x][i]) dfs(V[x][i], x, !col);
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		V[a].push_back(b);
		V[b].push_back(a);
	}
	for (int i = 0; i < N; i++) {
		int leafs = 0;
		for (int j = 0; j < V[i].size(); j++) if (V[V[i][j]].size() == 1) leafs++;
		if (leafs > 1) {
			printf("First\n");
			return 0;
		} else if (leafs == 1) meow[i] = 1;
	}
	for (int i = 0; i < N; i++) {
		int sum = 0;
		for (int j = 0; j < V[i].size(); j++) sum += meow[V[i][j]];
		if (sum == V[i].size() && V[i].size() != 1) {
			printf("First\n");
			return 0;
		}
	}
	dfs(0, -1, 0);
	if (col1 == col2) printf("Second\n");
	else printf("First\n");
}
