#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

int a[MAXN], b[MAXN];

int n;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i], b[i] = a[i];
	sort(a + 1, a + n + 1);
	int x = a[n / 2], y = a[n / 2 + 1];
	for (int i = 1; i <= n; i++)
	{
		if (b[i] <= x)
			cout << y << endl;
		else
			cout << x << endl;
	}
	return 0;	
}
