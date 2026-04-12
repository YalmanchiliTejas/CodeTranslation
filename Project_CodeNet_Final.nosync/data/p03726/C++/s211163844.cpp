#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int MAXN = 100005;

template <typename T> inline void read(T &AKNOI) {
	T x = 0, flag = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') flag = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	AKNOI = flag * x;
}

int n, son[MAXN];
vector<int> e[MAXN];

int DFS(int u, int fa) {
	for (auto v : e[u]) {
		if (v == fa) continue;
		son[u] += DFS(v, u);
	}
	if (son[u] >= 2) {
		puts("First");
		exit(0);
	}
	return son[u] ^ 1;
}

int main() {
	read(n);
	for (int i = 1, u, v; i < n; ++i) {
		read(u); read(v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	puts(DFS(1, 0)? "First" : "Second");
	return 0;
}
