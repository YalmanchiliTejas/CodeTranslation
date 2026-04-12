#include <bits/stdc++.h>
using namespace std;
int a, b;
int v[20][20];
bool taken[20][20];
vector<pair<int, int> > adj[110];
bool taken2[101][101];
int main()
{
	scanf("%d%d", &a, &b);
	for (int i = 1; i <= a; i++)
	{
		for (int j = 1; j <= b; j++)
		{
			scanf("%d", &v[i][j]);
		}
	}
	for (int i = 0; i <= 100; i++)
	{
		for (int j = 0; j <= 100; j++)
		{
			for (int k = 0; k <= 100; k++)
			{
				if (taken2[i][j]) break;
				if (i + j + k > 100) break;
				bool works = true;
				bool canhelp = false;
				for (int x = 1; x <= a && works; x++)
				{
					for (int y = 1; y <= b; y++)
					{
						if (i * x + j * y + k < v[x][y])
						{
							works = false;
							break;
						}
						else if (i * x + j * y + k == v[x][y] && !taken[x][y]) canhelp = true;
					}
				}

				if (!works) continue;
				if (!canhelp) continue;
				for (int x = 1; x <= a; x++)
				{
					for (int y = 1; y <= b; y++)
					{
						if (i * x + j * y + k == v[x][y])
						{
							taken[x][y] = true;
						}
					}
				}
				taken2[i][j] = true;
				adj[i].emplace_back(j, k);
			}
		}
	}
	for (int i = 1; i <= a; i++)
	{
		for (int j = 1; j <= b; j++)
		{
			if (!taken[i][j])
			{
				printf("Impossible\n");
				return 0;
			}
		}
	}
	int constant = 10*10;
	// 1 = sink
	// 2 - 101 = that many xs
	// 102 - 201 = that many ys
	// 202 (2*constant + 2) sink
	printf("Possible\n");
	vector<pair<pair<int, int> , char> > out;
	vector<pair<pair<int, int> , int> > out2;
	printf("%d ", 2*constant+2);
	for (int i = 1; i <= constant; i++)
	{
		out.emplace_back(make_pair(i, i+1), 'X');
	//	printf("%d %d X\n", i, i+1);
		out.emplace_back(make_pair(i+constant+1, i+constant+2), 'Y');
	//	printf("%d %d Y\n", i+constant+1, i + constant+2);
	}
	for (int i = 0; i <= constant; i++)
	{
		for (auto a : adj[i])
		{
			int y = a.first;
			y = constant-y;
			// 0 if 100
			y += constant+2;
			int wei = a.second;
			out2.emplace_back(make_pair(i+1, y), wei);
		}
	}
	printf("%lu\n", out.size() + out2.size());
	for (auto a : out) printf("%d %d %c\n", a.first.first, a.first.second, a.second);
	for (auto a : out2) printf("%d %d %d\n", a.first.first, a.first.second, a.second);
	printf("%d %d\n", 1, 2*constant+2);
}