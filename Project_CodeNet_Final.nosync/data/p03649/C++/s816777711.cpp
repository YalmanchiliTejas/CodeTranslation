#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n; cin >> n;
	vector<long long>a(n); for (auto&& x : a)cin >> x;
	bool done = false;
	long long ans = 0;
	while (!done) {
		done = true;
		for (int i = 0; i < n; i++) if (a[i] >= n) {
			done = false;
			long long del = a[i] / n;
			ans += del;
			a[i] -= del * n;
			for (int j = 0; j < n; j++) if (j != i) a[j] += del;
		}
	}
	cout << ans << endl;

	return 0;
}