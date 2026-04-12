#include <bits/stdc++.h>
using namespace std;

const int maxN = 2005, INF = 1e9;

struct Node
{
	int x, y, v;
	Node(int X = 0, int Y = 0, int Z = 0) { x = X; y = Y; v = Z; }
};

int n, ans, mx;
int A[maxN * 3 + 1];
int f[maxN + 1][maxN + 1], g[maxN + 1];

inline void chkmx(int a, int b, int v)
{
	f[a][b] = f[b][a] = max(f[a][b], v);
	g[a] = max(g[a], f[a][b]);
	g[b] = max(g[b], f[b][a]);
	mx = max(mx, f[a][b]);
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= 3 * n; i++) scanf("%d", &A[i]);

	if(n == 1) return puts(A[1] == A[2] && A[2] == A[3] ? "1" : "0"), 0;

	for(int i = 0; i <= n; i++)
	{
		g[i] = -INF;
		for(int j = 0; j <= n; j++)
			f[i][j] = -INF;
	}

	if(3 * n >= 5)
	{
		for(int i = 1; i <= 5; i++)
			for(int j = i + 1; j <= 5; j++)
			{
				int lst = 0;
				bool flag = true;
				for(int k = 1; k <= 5; k++)
					if(k != i && k != j)
					{
						if(lst && A[k] != lst) flag = false;
						lst = A[k];
					}
				if(flag) chkmx(A[i], A[j], 1);
				else chkmx(A[i], A[j], 0);
			}
	}

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			mx = max(mx, f[i][j]);

	for(int i = 6; i < 3 * n; i += 3)
	{
		int a = A[i], b = A[i + 1], c = A[i + 2];
		
		if(a == b && b == c) { ans ++; continue; }
		
		vector<Node> res; 
		
		res.push_back( Node(a, b, max(mx, f[c][c] + 1)) );
		res.push_back( Node(a, c, max(mx, f[b][b] + 1)) );
		res.push_back( Node(b, c, max(mx, f[a][a] + 1)) );

		for(int j = 1; j <= n; j++)
		{
			if(b == c) res.push_back( Node(a, j, max(g[j], f[j][c] + 1)) );
			else res.push_back( Node(a, j, g[j]) );
			if(a == c) res.push_back( Node(b, j, max(g[j], f[j][a] + 1)) );
			else res.push_back( Node(b, j, g[j]) );
			if(a == b) res.push_back( Node(c, j, max(g[j], f[j][b] + 1)) );
			else res.push_back( Node(c, j, g[j]) );
		}

		for(int i = 0; i < res.size(); i++)
			chkmx(res[i].x, res[i].y, res[i].v);
	}

	int res = -INF;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
		{
			int t = f[i][j];
			if(i == j && j == A[3 * n]) t ++;
			res = max(res, t);
		}
	
	printf("%d\n", res + ans);
	return 0;
}
