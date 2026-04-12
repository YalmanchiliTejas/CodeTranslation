#include <cstdio>
#include <algorithm>

#define RepG(i, x) for (int i = head[x]; i; i = edge[i].next)
#define Rep(i, n) for (int i = 1; i <= n; i ++)
#define v edge[i].to

using namespace std;

const int N = 100010;

struct Edge{ int to, next;} edge[N * 2];
int head[N], num;
void add_edge(int a, int b){ edge[++ num] = (Edge){b, head[a]}, head[a] =num;}

bool g[N], flag;

void dfs(int x, int f)
{
	int cnt = 0, tt = 0;
	RepG(i, x) if (v != f) {
		dfs(v, x); tt ++;
		if (g[v]) cnt ++;
	}
	if (cnt >= 2) flag = true;
	else if (!cnt) g[x] = true;
//	printf("%d %d\n", x, g[x]);
}

int main()
{
	int n;
	scanf("%d", &n);
	Rep(i, n - 1) {
		int a, b;
		scanf("%d%d", &a, &b);
		add_edge(a, b); add_edge(b, a);
	}
	dfs(1, 0);
	if (flag || g[1]) printf("First\n");
	else printf("Second\n");
	
	return 0;
}