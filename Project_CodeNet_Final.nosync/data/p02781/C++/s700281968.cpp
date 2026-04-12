#include <bits/stdc++.h>
using namespace std;

int num[105], k, n;
string s;

int f(int p, int k)
{
	if (k < 0)	return 0;
	if (k == 0) return 1;
	if (p <= 0)	return 0;
	return f(p-1, k) + 9*f(p-1,k-1);
}

int solve()
{
	int sum = 0;
	int kk = k;
	for (int i = n - 1; i; i--)
	{
		if (num[i] != 0)
		{
			sum += f(i, kk) + (num[i] - 1) * f(i, kk-1);
			kk--;
		}
	}
	if (kk == 0)	sum++;
	if (kk == 1)	sum += num[0];
	return sum;
}

int main()
{
	cin >> s >> k;
	n = s.size();
	for (int i = 0; i < n; i++)
		num[n - 1 - i] = s[i] - '0';
	cout << solve();
	return 0;
}