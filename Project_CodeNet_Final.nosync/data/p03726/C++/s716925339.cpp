#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <math.h>
using namespace std;

const int MAXN = 1e5 + 10;
int N;
int cnt = 1, Head[MAXN], Next[MAXN << 1], To[MAXN << 1];
int d[MAXN];
int ans;

inline void add_edge(int x, int y) {
	Next[++cnt] = Head[x], To[cnt] = y, Head[x] = cnt;
}

inline void insert_edge(int x, int y) {
	add_edge(x, y), add_edge(y, x);
}

inline void Dfs(int x, int fa = 0) {
	register int i; int s = 0;
	for(i = Head[x]; i; i = Next[i])
		if(To[i] != fa) {
			Dfs(To[i], x);
			s += d[To[i]] ^ 1;
		}
	if(s == 1) d[x] = 1;
	else if(s > 1) ans = 1;
}

int main() {
	register int i;
	int x, y;
	scanf("%d", &N);
	for(i = 1; i < N; ++i)
		scanf("%d%d", &x, &y),
		insert_edge(x, y);
	Dfs(1); ans |= d[1] ^ 1;
	puts(ans ? "First" : "Second");
	return 0;
}