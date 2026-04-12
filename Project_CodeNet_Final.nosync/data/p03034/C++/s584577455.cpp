#include <bits/stdc++.h>
using namespace std;

int s[111111];
int main() {
	int n;
	cin >> n;
	long m = 0;
	for (int i = 0; i < n; i++)
		scanf("%d", s + i);
	for (int d = 1; d < n; d++) {
		long t = 0;
		for (int j = d; j < ((n - 1) % d ? n - d : n - 1 - j); j += d)
			t += s[j] + s[n - 1 - j], m = max(m, t);
	}
	cout << m << endl;
	return 0;
}
