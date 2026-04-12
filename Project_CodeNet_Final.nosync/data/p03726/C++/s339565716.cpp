#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <cstdlib>
#include <memory.h>
#include <ctime>
#include <bitset>

using namespace std;

#define ABS(a) ((a>0)?a:-(a))
#define MIN(a,b) ((a<b)?(a):(b))
#define MAX(a,b) ((a<b)?(b):(a))
#define FOR(i,a,n) for (int i=(a);i<(n);++i)
#define FI(i,n) for (int i=0; i<(n); ++i)
#define pnt pair <int, int>
#define mp make_pair
#define PI 3.1415926535897
#define MEMS(a,b) memset(a,b,sizeof(a))
#define LL long long
#define U unsigned

vector<vector<int>> g;
vector<vector<int>> d;
int ch[100100];
int removed[100100];
int par[100100];
void dfs(int v, int depth, int p) {
	d[depth].push_back(v);
	par[v] = p;
	FOR(i, 0, g[v].size()) {
		int to = g[v][i];
		if (to != p) {
			ch[v]++;
			dfs(to, depth + 1, v);
		}
	}
}

int used[100100];

int main()
{
#ifdef Fcdkbear
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	double beg = clock();
#endif

	int n;
	scanf("%d", &n);
	g.resize(n);
	FOR(i, 0, n - 1) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	if (n == 2) {
		cout << "Second" << endl;
		return 0;
	}
	d.resize(n);
	int root = -1;
	FOR(i, 0, n) {
		if (g[i].size() > 1) {
			root = i;
		}
	}
	dfs(root, 0, -1);
	for (int i = n - 1; i >= 0; --i) {
		FOR(j, 0, d[i].size()) {
			int v = d[i][j];
			if (used[v]) {
				continue;
			}
			if (v == root) {
				printf("First\n");
				return 0;
			}
			int children = ch[par[v]] - removed[par[v]];
			if (children > 1) {
				printf("First\n");
				return 0;
			}
			used[par[v]] = 1;
			if (par[v] != root) {
				removed[par[par[v]]]++;
			}
		}
	}
	printf("Second\n");

#ifdef Fcdkbear
	double end = clock();
	fprintf(stderr, "*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
#endif
	return 0;
}