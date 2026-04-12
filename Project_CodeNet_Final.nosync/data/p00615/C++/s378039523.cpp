#include<iostream>
#include<algorithm>
using namespace std;
int x[1000000], n, m, maxn;
int main() {
	while (true) {
		cin >> n >> m; maxn = 0;
		if (n == 0 && m == 0) { break; }
		x[0] = 0;
		for (int i = 1; i <= n + m; i++) { cin >> x[i]; }
		sort(x, x + n + m + 1);
		for (int i = 0; i < n + m; i++) {
			maxn = max(maxn, x[i + 1] - x[i]);
		}
		cout << maxn << endl;
	}
}