#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, cnt = 0, cur = 0, m;
	cin >> n;
	while (n--) {
		cin >> m;
		if (m >= cur)
			++cnt;
		cur = max(cur, m);
	}
	cout << cnt << '\n';
}