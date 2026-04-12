#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <utility>

using namespace std;

const int MAXN = 200005;

pair<int, int> X[MAXN];

int B[MAXN];

int n;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> X[i].first, X[i].second = i;
	sort(X + 1, X + n + 1);
	int m = n / 2;
	for (int i = 1; i <= m; i++)
		B[X[i].second] = X[m + 1].first;
	for (int i = m + 1; i <= n; i++)
		B[X[i].second] = X[m].first;
	for (int i = 1; i <= n; i++)
		cout << B[i] << endl;
	return 0;
}
