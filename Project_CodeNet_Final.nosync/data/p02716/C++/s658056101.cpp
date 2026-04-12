#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<stdio.h>
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef double db;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	vector<ll> ans(n);
	ans[0] = 0;
	if (n >= 2)
		ans[1] = max(a[1], a[0]);
	ll cur = a[0];
	for (int i = 2; i < n; ++i)
	{
		if (i & 1)
		{
			cur += a[i - 1];
			ans[i] = max(ans[i - 2] + a[i], cur);
		}
		else
			ans[i] = max(ans[i - 1], ans[i - 2] + a[i]);
	}
	cout << ans[n - 1];
	return 0;
}