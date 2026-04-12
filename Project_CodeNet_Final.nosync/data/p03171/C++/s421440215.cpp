#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<deque>
#include<string>
#include<stdio.h>
using namespace::std;
#define int long long
int  v[3001][3001][2];
vector<int> d;
int dp(int l, int r, int f)
{
	if (l == r)
		return d[r];
	if (v[l][r][f] == 0)
		v[l][r][f] = max(-dp(l + 1, r, f ^ 1) + d[l], -dp(l, r - 1, f ^ 1) + d[r]);
	return v[l][r][f];

 }
signed main()
{
	int n;
		cin >> n;
	d.resize(n);

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		d[i] = x;
	}

cout << dp(0, n - 1, 1);
}
/*
2 3

0 - 0
1 - 0
2 - 1
3 - 1
4 - 1
5 - 0

*/




