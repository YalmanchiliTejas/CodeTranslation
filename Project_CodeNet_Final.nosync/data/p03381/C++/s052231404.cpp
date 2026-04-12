#include <bits/stdc++.h>
using namespace std;

vector<int> v, t;
int n;

int main() {
#ifdef HOME
	freopen("arc95c.in", "r", stdin);
	freopen("arc95c.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);


	cin >> n;
	v.resize(n);
	for (auto &i: v)
		cin >> i;

	t = v;
	sort(begin(t), end(t));

	for (int i = 0; i < n; ++i) {
		if (v[i] < t[n / 2])
			cout << t[n / 2] << '\n';
		else
			cout << t[n / 2 - 1] << '\n'; }

	return 0; }

