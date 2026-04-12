#include <bits/stdc++.h>

using namespace std;

pair<int, int> x[222222];
int b[222222];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		x[i].second = i;
		scanf("%d", &x[i].first);
	}
	sort(x, x + n);
	for (int i = 0; i < n / 2; i++) {
		b[x[i].second] = x[n / 2].first;
		b[x[i + n / 2].second] = x[n / 2 - 1].first;
	}
	for (int i = 0; i < n; i++)
		cout << b[i] << '\n';
	cout << flush;
	return 0;
}
