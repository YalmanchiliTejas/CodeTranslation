#include <bits/stdc++.h>
using namespace std;

string s;
int k, l;

int count(int i, bool equal, int nzero) {
	if (nzero > k)
		return 0;
	if (nzero == k)
		return 1;
	if (i == l)
		return 0;

	int ans = 0;
	for (int d = 0; d < 10; ++d) {
		if (equal) {
			if (d > s[i] - '0')
				continue;
			if (d < s[i] - '0')
				ans += count(i + 1, false, nzero + (d > 0));
			else
				ans += count(i + 1, true, nzero + (d > 0));
		} else
			ans += count(i + 1, false, nzero + (d > 0));
	}
	return ans;
}

int main() {
	cin >> s >> k;
	l = s.length();

	cout << count(0, 1, 0) << '\n';

	return 0;
}
