#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Edge{ UL u,v; UL w; UL h; };

UL N, M;
Edge J[20000];
vector<UL> E[10000];

UL DFS(UL p, UL pre = ~0u) {
	UL ans = 0;
	for (UL e : E[p]) {
		Edge& j = J[e];
		if (j.v == pre) continue;
		if (j.h == ~0u) j.h = DFS(j.v, p);
		ans = max(ans, j.h + j.w);
	}
	return ans;
}

int main() {
	scanf("%u", &N); M = N * 2 - 2;
	rep(i, N - 1) {
		UL u, v, w; scanf("%u%u%u", &u, &v, &w);
		J[i] = { u,v,w,~0u };
		J[i + N - 1] = { v,u,w,~0u };
		E[u].push_back(i);
		E[v].push_back(i + N - 1);
	}
	rep(i, N) printf("%u\n", DFS(i));

	return 0;
}

