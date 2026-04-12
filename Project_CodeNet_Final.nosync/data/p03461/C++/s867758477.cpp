#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
int m[15][15];
void no()
{
	printf("Impossible\n");
	exit(0);
}
typedef pair<int, int>pii;
typedef pair<pii, int>pi3;
int main()
{
	int mx, my;
	scanf("%d%d", &mx, &my);
	for (int i = 1; i <= mx; i++)for (int j = 1; j <= my; j++)scanf("%d", &m[i][j]);
	set<pi3>se;
	for (int i = 1; i <= mx; i++)
	{
		for (int j = 1; j <= my; j++)
		{
			for (int k = 0; k <= 100; k++)
			{
				for (int l = 0; l <= 100; l++)
				{
					int c = m[i][j] - k*i - l*j;
					if (c < 0)continue;
					bool f = true;
					for (int p = 1; p <= mx; p++)
					{
						for (int q = 1; q <= my; q++)
						{
							if (c + k*p + l*q < m[p][q])f = false;
						}
					}
					if (f)
					{
						se.insert(make_pair(make_pair(k, l), c));
						goto l01;
					}
				}
			}
			no();
		l01:;
		}
	}
	printf("Possible\n");
	printf("%d %d\n", 222, 220 + se.size());
	for (int i = 1; i < 111; i++)printf("%d %d X\n", i, i + 1);
	for (int i = 112; i < 222; i++)printf("%d %d Y\n", i, i + 1);
	set<pi3>::iterator it = se.begin();
	for (;;)
	{
		if (it == se.end())break;
		pi3 z = *it;
		it++;
		printf("%d %d %d\n", 1 + z.first.first, 222 - z.first.second, z.second);
	}
	printf("%d %d\n", 1, 222);
}