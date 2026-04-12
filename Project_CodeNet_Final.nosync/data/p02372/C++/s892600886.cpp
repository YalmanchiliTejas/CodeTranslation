#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<numeric>
#include<iostream>
#include<array>
#include<string>
#include<sstream>
#include<stack>
#include<queue>
#include<list>
#include<functional>
#define _USE_MATH_DEFINES

#include<math.h>
#include<map>

#define SENTINEL 1000000001

#define min(a,b) ((a)>(b)?(b):(a))
#define max(a,b) ((a)>(b)?(a):(b))

#define INF 200000000

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;

vector<pii> G[10000];
int d1[10000], d2[10000];
pii farestNode;


void visit(int n, int p, int w, int opt)
{
	switch (opt)
	{
	case 1:
		d1[n] = w;
		break;
	case 2:
		d2[n] = w;
		break;
	}
	if (G[n].size() == 1 && G[n][0].first == p)
	{
		if (w > farestNode.second)
		{
			farestNode = pii(n, w);
		}
		return;
	}
	for (auto& m : G[n])
	{
		if (m.first != p)
		{
			visit(m.first, n, w + m.second, opt);
		}
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	farestNode = pii(-1, 0);

	int V;
	scanf("%d", &V);

	for (int i = 0; i < V - 1; i++)
	{
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);

		G[u].push_back(pii(v, w));
		G[v].push_back(pii(u, w));
	}

	visit(0, -1, 0, 0);
	int t = farestNode.first;
	farestNode = pii(-1, 0);
	visit(t, -1, 0, 1);
	t = farestNode.first;
	farestNode = pii(-1, 0);
	visit(t, -1, 0, 2);

	for (int i = 0; i < V; i++)
	{
		printf("%d\n", max(d1[i], d2[i]));
	}

	return 0;
}
