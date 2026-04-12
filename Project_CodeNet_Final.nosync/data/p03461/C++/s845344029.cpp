#include <bits/stdc++.h>
using namespace std;

vector<pair<pair<int, int>, int> > ans;
map<pair<int, int>, int> res;
int d[15][15];
int a, b;

int main()
{
	scanf("%d%d", &a, &b);
	for (int i = 1;i <= a;i++) for (int j = 1;j <= b;j++) scanf("%d", d[i]+j);
	for (int i = 1;i <= a;i++) for (int j = 1;j <= b;j++)
	{
		bool done = false;
		int nA = 0, nB = 0, c = 0;
		for (;nA*i <= d[i][j];nA++)
		{
			for (nB=0;nA*i+nB*j <= d[i][j];nB++)
			{
				c = d[i][j]-nA*i-nB*j;
				bool ok = true;
				for (int x = 1;x <= a;x++)
				{
					for (int y = 1;y <= b;y++) if (nA*x+nB*y+c < d[x][y])
					{
						ok = false;
						break;
					}
					if (!ok) break;
				}
				if (ok)
				{
					done = true;
					break;
				}
			}
			if (done) break;
		}
		if (!done)
		{
			printf("Impossible\n");
			return 0;
		}
		res[make_pair(nA, nB)] = c;
	}
	a = 0, b = 0;
	for (auto u: res) a = max(a, u.first.first), b = max(b, u.first.second);
	for (int i = 1;i <= a;i++) ans.emplace_back(make_pair(i-1, i), -1);
	for (int i = 0;i <= a;i++) for (int j = 1;j <= b;j++) ans.emplace_back(make_pair((j-1)*(a+1)+i, j*(a+1)+i), -2);
	for (auto u: res) ans.emplace_back(make_pair(u.first.second*(a+1)+u.first.first, 299), u.second);
	printf("Possible\n300 %ld\n", ans.size());
	for (auto u: ans)
	{
		printf("%d %d ", u.first.first+1, u.first.second+1);
		if (u.second >= 0) printf("%d\n", u.second);
		else if (u.second == -1) printf("X\n");
		else printf("Y\n");
	}
	printf("1 300\n");
	return 0;
}
