#include<bits/stdc++.h>
#define maxn 200010
#define ll long long
#define mod 1000000007
using namespace std;
char s[maxn];
int f[maxn], pre[maxn];
int main()
{
	int n, m, mx = 0, flag = 1;
	scanf("%d%d", &n, &m);
	scanf("%s", s + 1);
	for (int i = 2; i <= m; i++)
		if (s[i] != s[1]) flag = 0;
	if (flag == 0)
	{
		int st;
		for (int i = 1; i <= m; i++)
			if (s[i] != s[1])
			{
				st = i;
				mx = i - 1;
				if (mx % 2 == 0) mx++;
				break;
			}
		while (st <= m)
		{
			int cur = st;
			while (cur <= m && s[cur] == s[st]) cur++;
			if (cur != m + 1 && s[st] == s[1] && (cur - st) % 2) mx = min(mx, cur - st);
			st = cur;
		}
		if (n % 2) {puts("0"); return 0;}
		n /= 2;
		mx = (mx + 1) / 2;
	}
	else mx = n;
	f[0] = pre[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		f[i] = pre[i - 1];
		if (i - mx - 1 >= 0) f[i] = (f[i] - pre[i - mx - 1] + mod) % mod;
		if (flag) f[i] = (f[i] - f[i - 1] + mod) % mod;
		pre[i] = (pre[i - 1] + f[i]) % mod;
	}
	int res = flag;
	for (int i = flag + 1; i <= mx; i++)
		res = (res + (ll)i * f[n - i] % mod) % mod;
	if (flag == 0) res = (ll)res * 2 % mod;
	printf("%d\n", res);
	return 0;
}