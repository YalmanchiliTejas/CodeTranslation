#include <stdio.h>
#include <iostream>
#include <vector>
#include <assert.h>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <memory.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
typedef long long ll;
int n;
vector<vector<int> > g;
bool DFS(int u, int p) {
	bool clr = true;
	int res[2] = {};
	for (int i = 0; i < g[u].size(); ++i)
		if (g[u][i] != p)
			++res[DFS(g[u][i], u)];
	if (res[0] + res[1] == 0)
		return clr;
	if (res[1]>1) {
		puts("First");
		exit(0);
	}
	if (res[1])
		return false;
	return res[0];
}
int main()
{
	scanf("%d", &n);
	g.resize(n);
	for (int i = 1, a, b; i < n; ++i) {
		scanf("%d%d", &a, &b);
		--a; --b;
		g[a].push_back(b);
		swap(a, b);
		g[a].push_back(b);
	}
	if (n == 2) {
		puts("Second");
		return 0;
	}
	if (DFS(0, -1))
		puts("First");
	else
		puts("Second");
	return 0;
}