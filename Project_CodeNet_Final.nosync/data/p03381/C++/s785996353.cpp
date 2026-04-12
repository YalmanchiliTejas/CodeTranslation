#include <bits/stdc++.h>
#define range(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, a) range(i, 0, a)
using namespace std;

int main() {
	int n;
	cin >> n;
	vector <int> x(n);
	rep (i, n) cin >> x[i];
	vector <int> cp = x;
	sort(cp.begin(), cp.end());

	rep (i, n) {
		cout << (cp[n / 2] <= x[i] ? cp[n / 2 - 1] : cp[n / 2]) << endl;
	}

	return 0;
}