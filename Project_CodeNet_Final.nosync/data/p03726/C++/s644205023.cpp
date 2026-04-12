#include <bits/stdc++.h>

#define debug(x) cout << #x" = " << x;

#define st first
#define nd second

using namespace std;
using namespace placeholders;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

const int MAXN = 1E5 + 10;

int n;
vector<int> E[MAXN];
int deg[MAXN], fa[MAXN], mark[MAXN];

int main(){
	scanf("%d", &n);
	for (int u, v, i = 1; i < n; ++i){
		scanf("%d%d", &u, &v);
		E[u].push_back(v), ++deg[u];
		E[v].push_back(u), ++deg[v];
	}

	queue<int> Q;
	for (int i = 1; i <= n; ++i)
		if (deg[i] == 1){
			fa[i] = E[i][0];
			Q.push(i);
		}

	while (!Q.empty()){
		map<int, int> lst;
		while (!Q.empty()){
			int u = Q.front();
			Q.pop();
			++lst[fa[u]];
			mark[u] = true;
		}

		for (auto &x: lst){
			mark[x.st] = true;
			if (x.nd > 1)
				return puts("First"), 0;
		}
		for (auto &x: lst)
			for (auto &v: E[x.st])
				--deg[v];

		set<int> ms;
		for (auto &x: lst){
			int u = x.st;
			for (auto &v: E[u])
				if (!mark[v] && !ms.count(v)){
					if (deg[v] == 0)
						return puts("First"), 0;
					if (deg[v] == 1){
						for (auto &w: E[v])
							if (!mark[w])
								fa[v] = w;
						ms.insert(v);
						Q.push(v);
					}
				}
		}
	}
	puts("Second");
	return 0;
}
