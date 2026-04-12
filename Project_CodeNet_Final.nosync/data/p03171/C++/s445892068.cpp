#include <bits/stdc++.h>

using namespace std;

long a[3333], d[3333][3333];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 1; i < n + 1; i++)
		for (int j = 0; j < n - i + 1; j++)
			d[j][i] = max(a[j] - d[j + 1][i - 1], a[j + i - 1] - d[j][i - 1]);
	cout << d[0][n] << endl;
	return 0;
}
