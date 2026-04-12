#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> xs(n);
	for (int& x : xs) {
		cin >> x;
	}
	reverse(xs.begin(), xs.end());

	int ans = 0;
	vector<int> s;
	for (int x : xs) {
		if (s.empty() || s.back() <= x) {
			s.push_back(x);
			ans = max(ans, (int) s.size());
		} else {
			int i = upper_bound(s.begin(), s.end(), x) - s.begin();
			s[i] = x;
		}
	}

	cout << ans << endl;
	return 0;
}

