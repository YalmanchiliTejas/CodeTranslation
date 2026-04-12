#include "bits/stdc++.h"
using namespace std;
long p[10];
bool cm(const long l, const long r) {
	return p[l] > p[r];
}
int main() {
	long n, i, w, l, d, id[10], f = 0;
	string s[10];
	while (cin >> n) {
		if (n == 0)
			break;
		if (f > 0)
			cout << endl;
		f = 1;
		for (i = 0; i < n; i++)
			p[i] = 0;
		for (i = 0; i < n; i++) {
			cin >> s[i] >> w >> l >> d;
			p[i] += 3 * w + d;
			id[i] = i;
		}
		sort(id, id + n, cm);
		for (i = 0; i < n; i++) {
			cout << s[id[i]] << "," << p[id[i]] << endl;
		}
	}
	return 0;
}