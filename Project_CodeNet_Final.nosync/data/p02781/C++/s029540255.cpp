#include <bits/stdc++.h>
#define MAX 123
using namespace std;

int len;
int K;
int ans;
char str[MAX];
char N[MAX];

void dfs(int k, int start)
{
	if (K == k)
	{
		int flag = 1;
		for (int i = 0; i < len; i++)
		{
			if (N[i] > str[i]) flag = 0;
			else if (N[i] < str[i]) break;
		}
		ans += flag;
		return;
	}
	int flag = 1;
	for (int i = 0; i < start; i++)
	{
		if (N[i] > str[i])
		{
			flag = 0;
			break;
		}
		else if (N[i] < str[i])
		{
			flag = 2;
			break;
		}
	}

	if (flag == 0)
	{
		return;
	}
	if (flag == 2)
	{
		if (K - k == 2)
		{
			ans += 1LL * (len - start) * (len - start - 1) / 2 * 81;
			return;
		}
		if (K - k == 1)
		{
			ans += (len - start) * 9;
			return;
		}
	}
	for (int i = start; i < len; i++)
	{
		if (N[i] != '0') continue;
		for (int j = 1; j < 10; j++)
		{
			N[i] = '0' + j;
			dfs(k + 1, i + 1);
			N[i] = '0';
		}
	}
}

int main(void)
{
	cin >> str >> K;
	len = strlen(str);
	for (int i = 0; i < len; i++) N[i] = '0';
	dfs(0, 0);
	cout << ans << endl;
	return 0;
}
