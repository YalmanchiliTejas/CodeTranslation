#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using Vi = vector<int>;
using Vl = vector<ll>;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

//===

int bs(Vi& vec, int x) {
	int left = -1, right = static_cast<int>(vec.size());
	while (right - left > 1) {
		int mid = (right + left) / 2;
		if (x < vec[mid]) {
			right = mid;
		}
		else {
			left = mid;
		}

	}
	return right;
}

int main() {
	int N;
	cin >> N;
	Vi a(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}

	int ans = 1;
	Vi c_min;
	c_min.push_back(a[N - 1]);

	for (int i = N - 2; i >= 0; --i) {
		int pos = bs(c_min, a[i]);
		if (pos == ans) {
			c_min.push_back(a[i]);
			++ans;
		}
		else {
			c_min[pos] = a[i];
		}
	}

	cout << ans << endl;
}