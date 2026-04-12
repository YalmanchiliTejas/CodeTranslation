#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i : a) cin >> i;
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int k;
		cin >> k;
		cout << lower_bound(a.begin(), a.end(), k) - a.begin() << endl;
	}
}
