#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int>x(n), y(n); for (auto&& i : x)cin >> i;
	y = x;
	sort(y.rbegin(), y.rend());
	int L = y[y.size() / 2 - 1], R = y[y.size() / 2];
	for (auto&& cur : x) {
		if (cur < L)cout << L << endl; else cout << R << endl;
	}

	return 0;
}