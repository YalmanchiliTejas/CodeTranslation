// 累積和くんｗ
// map でやればおしまい！ｗ
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;

	ll sum = 0;
	map<ll, int>mi; mi[sum] = -1;
	map<ll, int>ma; ma[sum] = -1;
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		sum += x;
		if (mi.find(sum) == mi.end())mi[sum] = i;
		ma[sum] = i;
	}

	int ret = 0;
	for (auto x : mi) {
		ret = max(ret, ma[x.first] - mi[x.first]);
	}
	cout << ret << endl;
	return 0;
}
