#include <iostream>
#include<math.h>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include <algorithm>
#include<string.h>
#define ll long long
#define ull unsigned long long
using namespace std;
/* 
struct edge{
	int to, nxt;
}e[100005];
int head[100005], tot = 1, x, num[100005];
void add(int v, int u)
{
	e[tot].to = u, e[tot].nxt = head[v], head[v] = tot++;
}*/
char s[105];
int k, ans, pos[3], num, len;
signed main() 
{
	while (~scanf("%s %d", s, &k))
	{
		len = strlen(s);
		memset(pos, -1, sizeof(pos));
		num = 0;
		for (int i = 0; i < len; i++)
		{
			if (s[i] > '0')
				pos[num++] = i;
			if (num == 3)	break;
		}
		if (k > len);
		else if (k == 1)
		{
			ans = s[0] - '0';
			ans += 9 * (len - 1);
		}
		else if (k == 2)
		{
			ans = (len - 1) * (len - 2) / 2 * 81;
			ans += (s[0] - '1') * (len - 1) * 9;
			if (pos[1] != -1 && pos[1] <= len - 1)
			{
				ans += (len - 1 - pos[1]) * 9 + s[pos[1]] - '0';
			}
		}
		else if (k == 3)
		{
			ans = (len - 1) * (len - 2) * (len - 3) / 6 * 81 * 9;
			ans += (s[0] - '1') * (len - 1) * (len - 2) / 2 * 81;
			if (pos[1] != -1 && pos[1] <= len - 2)
			{
				ans += (s[pos[1]] - '1') * (len - 1 - pos[1]) * 9;
				if (pos[1] <= len - 3)
					ans += (len - 1 - pos[1]) * (len - 2 - pos[1]) / 2 * 81;
				if (pos[2] != -1 && pos[2] <= len - 1)
				{
					ans += (len - 1 - pos[2]) * 9 + s[pos[2]] - '0';
				}
			}
		}
		printf("%d\n", ans);
	}
}
