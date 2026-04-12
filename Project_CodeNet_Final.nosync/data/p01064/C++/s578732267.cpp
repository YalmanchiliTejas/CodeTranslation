#include <bits/stdc++.h>
using namespace std;

void rev(int &k, int y, int z) {
	k -= y;
	z -= y;
	k = z - k;
	k += y;
}

int main() {
	int n;
	cin >> n;

	int a, d;
	cin >> a >> d;

	int m;
	cin >> m;

	vector<tuple<int, int, int>> query;
	query.reserve(m);
	for(int i = 0; i < m; ++i) {
		int x, y, z;
		cin >> x >> y >> z;
		--y; --z;
		query.emplace_back(x, y, z);
	}

	int k;
	cin >> k;
	--k;

	for(int i = m - 1; i >= 0; --i) {
		int x, y, z;
		tie(x, y, z) = query[i];

		if(x == 0) {
			if(y <= k && k <= z) {
				rev(k, y, z);
			}
		}
	}

	int ans = a + k * d;
	for(int i = 0; i < m; ++i) {
		int x, y, z;
		tie(x, y, z) = query[i];

		if(!(y <= k && k <= z)) continue;

		switch(x) {
		case 0:
			rev(k, y, z);
			break;
		case 1:
			++ans;
			break;
		case 2:
			ans /= 2;
			break;
		default:
			assert(false);
		}
	}

	cout << ans << endl;

	return 0;
}