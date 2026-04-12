#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int n, ok, cnt, b;
int a[100][30];
char ans[55];
int Min = 1000;
char s[55][55];
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%s", s[i]);
		b = strlen(s[i]);
		for(int j = 0; j < b; j++)
		a[i][s[i][j] - 'a']++;
	}
		for(int j = 0; j <= 26; j++)
		{
			Min = 100;
			for(int i = 1; i <= n; i++)
			{
				Min = min(Min, a[i][j]);
			}
			if(Min != 100)for(int k = 1; k <= Min; k++)ans[cnt++] = 'a' + j;
		}
	printf("%s\n", ans);
}