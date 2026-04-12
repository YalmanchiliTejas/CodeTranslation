#include <bits/stdc++.h>

using namespace std;

long d[11111][111], e[11111][111];
int p = 1e9 + 7;
int main() {
	string k;
	int D;
	cin >> k >> D;
	d[k.length()][0] = e[k.length()][0] = 1;
	for (int i = k.length(); i--;) {
		for (int j = 0; j < D; j++) {
			int m = k[i] - '0';
			d[i][(j + m) % D] = (d[i][(j + m) % D] + d[i + 1][j]) % p;
			while (m--)
				d[i][(j + m) % D] = (d[i][(j + m) % D] + e[i + 1][j]) % p;
			for (m = 10; m--;)
				e[i][(j + m) % D] = (e[i][(j + m) % D] + e[i + 1][j]) % p;
		}
	}
	cout << (d[0][0] - 1 + p) % p << endl;
	return 0;
}
