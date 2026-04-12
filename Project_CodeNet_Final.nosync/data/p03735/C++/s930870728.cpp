#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, mny = 1e9, mxy, res;
pair<int, int>p[200007];
int read()
{
	int num = 0;
	char c = getchar();
	while (c < '0' || c>'9')c = getchar();
	while (c >= '0' && c <= '9')num = num * 10 + c - '0', c = getchar();
	return num;
}
signed main()
{
	n = read();
	for (int i = 1; i <= n; i++)
	{
		p[i].first = read();
		p[i].second = read();
		if (p[i].first > p[i].second)
			swap(p[i].first, p[i].second);
		mny = min(mny, p[i].second);
		mxy = max(mxy, p[i].second);
	}
	sort(p + 1, p + n + 1);
	int tmp = mxy - p[1].first;
	res = min((p[n].first - p[1].first) * (mxy - mny), tmp * (p[n].first - p[1].first));
	mny = 1e9, mxy = 0;
	for (int i = 1; i <= n; i++)
	{
		mny = min(mny, p[i].second);
		mxy = max(mxy, p[i].second);
		res = min(res, tmp * (max(mxy, p[n].first) - min(mny, i == n ? (int)1e9 : p[i + 1].first)));
	}
	cout << res << endl;
	return 0;
}