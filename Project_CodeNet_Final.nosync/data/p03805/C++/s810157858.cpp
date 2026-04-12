#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> edges[10];

int dfs(int curr, int mask) {
	if(mask == (1<<n)-1) return 1;
	int ret = 0;
	for(int out: edges[curr]) {
		if(!(mask&(1<<out))) {
			ret += dfs(out, mask | (1 << out));
		}
	}
	return ret;
}

int main() {
	scanf("%d%d", &n, &m);
	while(m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	printf("%d\n", dfs(0, 1));
}