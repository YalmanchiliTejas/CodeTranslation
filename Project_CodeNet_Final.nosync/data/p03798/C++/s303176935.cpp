#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int MaxN = 1e5;

int n;
char s[MaxN + 5], ans[MaxN + 5];
bool check(int x, int y)
{
	if(x == 1 && y == 1) ans[1] = 'S', ans[2] = 'S';
	else if(x == 1 && y == 2) ans[1] = 'S', ans[2] = 'W';
	else if(x == 2 && y == 1) ans[1] = 'W', ans[2] = 'S';
	else if(x == 2 && y == 2) ans[1] = 'W', ans[2] = 'W';
	for(int i = 2; i < n; i++)
	{
		if(s[i] == 'o')
		{
			if(ans[i] == 'S') ans[i + 1] = ans[i - 1];
			else 
			{
				if(ans[i - 1] == 'S') ans[i + 1] = 'W';
				else ans[i + 1] = 'S';
			}
		}
		else 
		{
			if(ans[i] == 'W') ans[i + 1] = ans[i - 1];
			else
			{
				if(ans[i - 1] == 'S') ans[i + 1] = 'W';
				else ans[i + 1] = 'S';
			}
		}
	}
	if(ans[1] == 'S' && s[1] == 'o')
		if(ans[n] != ans[2])
			return 0;
	if(ans[1] == 'S' && s[1] == 'x')
		if(ans[n] == ans[2])
			return 0;
	if(ans[1] == 'W' && s[1] == 'o')
		if(ans[n] == ans[2])
			return 0;
	if(ans[1] == 'W' && s[1] == 'x')
		if(ans[n] != ans[2])
			return 0;
	if(ans[n] == 'S' && s[n] == 'o')
		if(ans[n - 1] != ans[1])
			return 0;
	if(ans[n] == 'S' && s[n] == 'x') 
		if(ans[n - 1]  == ans[1])
			return 0;
	if(ans[n] == 'W' && s[n] == 'o')
		if(ans[n - 1] == ans[1])
			return 0;
	if(ans[n] == 'W' && s[n] == 'x')
		if(ans[n - 1] != ans[1])
			return 0;
	return 1;
}
int main()
{
	while(scanf("%d", &n) != EOF)
	{
		bool flag = 0;
		for(int i = 1; i <= n; i++)
			scanf(" %c", &s[i]);
		for(int i = 1; i <= 2; i++)
		{
			for(int j = 1; j <= 2; j++)
			{
				memset(ans, 0, sizeof(ans));
				if(check(i, j))
				{
					flag = 1;
					i = j = 3;
				}
			}
		}
		if(flag)
		{
			for(int i = 1; i <= n; i++)
				printf("%c", ans[i]);
			printf("\n");
		}
		else printf("-1\n");
		memset(s, 0, sizeof(s));
		memset(ans, 0, sizeof(ans));
	}
}