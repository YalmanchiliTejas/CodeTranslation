#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int>a(n),Z; for (auto&& x : a)cin >> x;
	Z = a;
	sort(Z.rbegin(), Z.rend());
	int L = Z[n / 2 - 1], R = Z[n / 2];
	for (int i = 0; i < n; i++) {
		if (L > a[i])cout << L << endl;
		else cout << R << endl;
	}

	return 0;
}