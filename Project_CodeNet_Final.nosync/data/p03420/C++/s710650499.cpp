#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	long r = 0;
	for (int b = k + 1; b <= n; b++)
		r += k ? n / b * (b - k) + max(0, n%b + 1 - k) : n;
	cout << r << endl;
	return 0;
}
