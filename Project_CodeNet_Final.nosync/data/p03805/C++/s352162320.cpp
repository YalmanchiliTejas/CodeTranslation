#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <cstdlib>
#include <bitset>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	
	int n, m;

	cin >> n >> m;
	vector<int> a,b;
	vector<int> c;

	int t=0;

	

	for (int i = 0; i < m; i++) {
		int d, e;
		cin >> d >> e;
		a.push_back(d);
		b.push_back(e);
	}

	for (int i = 1; i <= n; i++) {
		c.push_back(i);
	}

	do {
		vector<bool>f(m, 0);

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n-1; j++) {
				if (((a[i] == c[j] && b[i] == c[j + 1]) || (a[i] == c[j + 1] && b[i] == c[j])) && f[i] == 0) f[i] = 1;
			}

		}
	
		if (c[0] == 1) {
			int s = 0;
			for (int i = 0; i < m; i++) {
				if (f[i] == 1) s++;
			}

			if (s == n - 1) t++;

		}

	} while (next_permutation(c.begin(), c.end()));


	cout << t << endl;

	
	


	return 0;
}