#include <bits/stdc++.h>

using namespace std;

long long res = 0;
vector < vector <int> > g;

bool visitados[8];

void dfs(int nodo, int may, int cont) {
	if (may == cont) {
		res++;
		return;
	}
	for (int i = 0; i < g[nodo].size(); i++) {
		if (!visitados[g[nodo][i]]) {
			visitados[g[nodo][i]] = true;
			dfs(g[nodo][i], may, cont + 1);
			visitados[g[nodo][i]] = false;
		}
	}
}



int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	vector < vector <int> > aux(n);
	g = aux;
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		g[a - 1].push_back(b - 1);
		g[b - 1].push_back(a - 1);
	}
	visitados[0] = true;
	dfs(0, n, 1);
	printf("%lld\n", res);
	return 0;
}