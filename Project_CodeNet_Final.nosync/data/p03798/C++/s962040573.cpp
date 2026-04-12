#include <iostream>
#include <vector>
using namespace std;

long long mod(long long a, long long m) {
	a %= m;
	return a >= 0 ? a : a+m;
}

int main() {
	int n;
	string s;
	cin >> n >> s;
	vector<int> ans(n);
	for (int bits = 0; bits < 4; bits++) {
		bool ok = true;
		if ((bits>>1) & 1) ans[n-1] = 0;
		else ans[n-1] = 1;
		if (bits & 1) ans[0] = 0;
		else ans[0] = 1;
		for (int i = 0; i < n; i++) {
			int a = s[i]=='o' ? 0 : 1;
			int next = a ^ ans[mod(i-1, n)] ^ ans[i];
			if (i == n-2 || i == n-1) {
				if (next != ans[mod(i+1, n)]) ok = false;
			}
			else ans[i+1] = next;
		}
		if (ok) {
			for (int i = 0; i < n; i++) {
				if (ans[i] == 0) cout << 'S';
				else cout << 'W';
			}
			cout << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}