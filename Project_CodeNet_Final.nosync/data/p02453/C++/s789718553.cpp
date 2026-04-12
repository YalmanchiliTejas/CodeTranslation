#include <bits//stdc++.h>
using namespace std;
int main() {
	int n,q,k,i; cin >> n;
	vector<int> a(n);
	for (int& i : a) cin >> i;
	cin >> q;
	for (i = 0; i < q; ++i) {
		cin >> k;
		cout << lower_bound(a.begin(), a.end(), k) - a.begin() << endl;
	}
}
