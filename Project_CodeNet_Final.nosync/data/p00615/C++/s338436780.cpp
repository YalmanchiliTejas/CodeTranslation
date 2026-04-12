#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n, m, a[20001], i, r;
	while (cin >> n >> m, !(!n && !m))
	{
		a[0] = r = 0;
		for (i = 1; i <= n+m; i++)
			cin >> a[i];
		sort(a, a+n+m+1);
		for (i = 1; i <= n+m; i++)
			r = max(r, a[i] - a[i-1]);
		cout << r << endl;
	}
}