/**
 *    author:  erekle
 *    created: 19.09.2020 13:26:02
**/
#include <bits/stdc++.h>

using namespace std;

#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define swap2(x,y) x=x^y; y=x^y; x=x^y;

int main() {
	fastIO
	
	long long n, x, m;
	cin >> n >> x >> m;

	vector<int> order, index(m); // index is one-based
	int repStart = -1; // repeat start value
	for (long long i = x; true; i = (i*i) % m) {
		if (index[i]) {
			repStart = i;
			break;
		}
		order.push_back(i);
		index[i] = order.size();
	}

	long long ans = 0;
	for (int i = 0; i < min(n, (long long)order.size()); ++i) ans += order[i];
	if (n <= order.size()) {
		cout << ans << endl;
		return 0;
	}

	int repLen = (int)order.size() + 1 - index[repStart];
	long long repCount = (n - order.size()) / repLen;
	for (int i = index[repStart] - 1; i < (int)order.size(); ++i) {
		ans += repCount * order[i];
	}
	
	long long pos = (int)order.size() + repCount*repLen + 1;
	for (long long i = repStart; pos <= n; ++pos, i = (i*i) % m) {
		ans += i;
	}
	cout << ans << endl;
	return 0;
}
