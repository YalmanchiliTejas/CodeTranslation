#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<functional>
using namespace std;
int main() {
	int n, i, j, k;
	int z = 0;
	while (1) {
		cin >> n;
		if (n == 0) break;
		vector < pair < int,string  > > x(n);
		for (int q = 0; q < n; q++) {
			cin >> x[q].second;
			cin >> i >> j >> k;
			x[q].first = 3 * i + k;
		}
		for (int w = 0; w < n; w++) {
			for (int q = 0; q+1 < n; q++) {
				if (x[q].first < x[q + 1].first) {
					swap(x[q], x[q + 1]);
				}
			}
		}
		for (int q = 0; q < n; q++) {
			if (q == 0) {
				if (z != 0)	cout << endl;
			}
			cout << x[q].second << ',' << x[q].first << endl;
			z = 1;
		}
	}

	return 0;
}