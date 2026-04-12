#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n;
int ans[N];
deque<int> dque;

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	bool rev = false;
	for (int i=1; i<=n; ++i) {
		int x;
		cin >> x;
		if (!rev) dque.push_back(x);
		else dque.push_front(x);
		rev = !rev;
	}
	n = 0;
	for (auto x: dque) ans[++n] = x;
	if (rev) reverse(ans+1, ans+n+1);
	for (int i=1; i<=n; ++i) {
		cout << ans[i];
		if (i == n) cout << '\n';
		else cout << ' ';
	}
	return 0;
}
