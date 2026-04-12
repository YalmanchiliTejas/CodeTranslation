#include <bits/stdc++.h>
using namespace std;
typedef long long i64;

int main(void) {
	i64 n, m = 0, c = 0;
	cin >> n;
	for (i64 i = 0; i < n; i++) {
		i64 h;
		cin >> h;
		if (h >= m) c++;
		m = max(m, h);
	}
	cout << c << endl;
}