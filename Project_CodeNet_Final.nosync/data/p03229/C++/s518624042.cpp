#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<set>
#include<string>
#include<vector>
#include<ctime>
#include<stack>
using namespace std;
typedef long long ll;
#define mm(a,b) memset(a,b,sizeof(a))
const int maxn = 1e6 + 50;
int a[maxn], ans[maxn];
int vis[maxn];
int main()
{
	memset(vis, 0, sizeof(vis));
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);

	int mid = n / 2, turn = 1, l = 1, r = n - 1;
	ans[mid] = a[0];
	vis[0] = 1;
	int i = 1, sum = n - 1;
	while (l < r&&sum>1)
	{
		if (turn == 1 && !vis[r] && !vis[r - 1])
		{
			vis[r] = 1;
			vis[r - 1] = 1;
			ans[mid + i] = a[r];
			r--;
			ans[mid - i] = a[r];
			r--;
			sum -= 2;
			i++;
			turn = 0;
		}
		else if (turn == 0 && !vis[l] && !vis[l + 1])
		{
			vis[l] = 1;
			vis[l + 1] = 1;
			ans[mid + i] = a[l];
			l++;
			ans[mid - i] = a[l];
			l++;
			sum -= 2;
			i++;
			turn = 1;
		}
	}
	if (sum == 1)
	{
		if (abs(a[l] - ans[1]) > abs(a[l] - ans[n - 1]))
			ans[0] = a[l];
		else
			ans[n] = a[l];
	}

	if (ans[0] != 0)
	{
		if (abs(ans[0] - ans[1]) < abs(ans[0] - ans[n - 1]))
		{
			ans[n] = ans[0];
			ans[0] = 0;
		}
	}

	//for (int i = 0; i <= n; i++)
		//printf("%d ", ans[i]);
	//printf("\n");

	ll anssum = 0;
	for (int i = 0; i <= n; i++)
	{
		if (ans[i] == 0 || ans[i + 1] == 0) continue;
		anssum += abs(ans[i] - ans[i + 1]);
	}
	printf("%lld\n", anssum);
	return 0;
}

/*
5
10 10 5 5 50
*/