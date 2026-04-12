//%std
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
inline ll read()
{
	ll out = 0, fh = 1;
	char jp = getchar();
	while ((jp > '9' || jp < '0') && jp != '-')
		jp = getchar();
	if (jp == '-')
		fh = -1, jp = getchar();
	while (jp >= '0' && jp <= '9')
		out = out * 10 + jp - '0', jp = getchar();
	return out * fh;
}
const int N = 500 + 10;
ll a[N][N], ans[N][N], S[N], T[N], row[N], col[N];
int n, tot[N], sum[N];
int val(ll x, ll k)
{
	return x >> k & 1ULL;
}
bool solve(int k)
{
	for (int i = 1; i <= n; ++i)
	{
		tot[i] = sum[i] = 0;
		for (int j = 1; j <= n; ++j)
		{
			a[i][j] = val(row[i], k);
			tot[i] += a[i][j];
		}
	}
	for (int j = 1; j <= n; ++j)
	{
		if (T[j] == 0) // And
		{
			int x = 1;
			for (int i = 1; i <= n; ++i)
				x &= a[i][j];
			if (x != val(col[j], k))
			{
				if (val(col[j], k) == 1)
				{
					for (int i = 1; i <= n; ++i) 
						if (a[i][j] != 1)
						{
							a[i][j] = 1;
							++tot[i];
							if (S[i] == 1 && val(row[i], k) == 0)
								return false;
//							if (S[i] == 0 && val(row[i], k) == 0 && tot[i] == n)
//								return false;
						}
				}
				else
				{
					int pos = 0;
					for (int i = 1; i <= n; ++i)
						if (val(row[i], k) == 0)
						{
							pos = i;
							break;
						}
						else if (S[i] == 1)
						{
							if (!pos || tot[i] > tot[pos])
								pos = i;
						}
					if (!pos)
						return false;
					a[pos][j] = 0, --tot[pos];
				}
			}
		}
		else // Or
		{
			int x = 0;
			for (int i = 1; i <= n; ++i)
				x |= a[i][j];
			if (x != val(col[j], k))
			{
				if (val(col[j], k) == 0)
				{
					for (int i = 1; i <= n; ++i) 
						if (a[i][j] != 0)
						{
							a[i][j] = 0;
							--tot[i];
							if (S[i] == 0 && val(row[i], k) == 1)
								return false;
//							if (S[i] == 1 && val(row[i], k) == 1 && !tot[i])
//								return false;
						}
				}
				else
				{
					int pos = 0;
					for (int i = 1; i <= n; ++i)
						if (val(row[i], k) == 1)
						{
							pos = i;
							break;
						}
						else if (S[i] == 0)
						{
							if (!pos || tot[i] < tot[pos])
								pos = i;
						}
					if (!pos)
						return false;
					a[pos][j] = 1, ++tot[pos];
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		if (S[i] == 0)
		{
			int x = 1;
			for (int j = 1; j <= n; ++j)
				x &= a[i][j];
			if (x != val(row[i], k))
				return false;
		}
		else
		{
			int x = 0;
			for (int j = 1; j <= n; ++j)
				x |= a[i][j];
			if (x != val(row[i], k))
				return false;
		}
	}
	for (int j = 1; j <= n; ++j)
	{
		if (T[j] == 0)
		{
			int x = 1;
			for (int i = 1; i <= n; ++i)
				x &= a[i][j];
			if (x != val(col[j], k))
				return false;
		}
		else
		{
			int x = 0;
			for (int i = 1; i <= n; ++i)
				x |= a[i][j];
			if (x != val(col[j], k))
				return false;
		}
	}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			ans[i][j] |= (a[i][j]) << k;
	return true;
}
int main()
{
	ios::sync_with_stdio(false);
	n = read();
	for (int i = 1; i <= n; ++i)
		S[i] = read();
	for (int i = 1; i <= n; ++i)
		T[i] = read();
	for (int i = 1; i <= n; ++i)
		row[i] = read();
	for (int i = 1; i <= n; ++i)
		col[i] = read();
	for (int i = 0; i < 64; ++i)
		if (!solve(i))
			return puts("-1"), 0;
	for (int i = 1; i <= n; ++i, cout << '\n')
		for (int j = 1; j <= n; ++j)
			cout << ans[i][j] << ' ';
	return 0;
}
