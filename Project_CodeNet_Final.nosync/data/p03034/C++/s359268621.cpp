#include <bits/stdc++.h>
using namespace std;
template<typename T1, typename T2>
inline bool cmx (T1& a, T2 b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
int main() {
	cin.tie(0); cin.sync_with_stdio(false);
	int n;
	cin >> n;
	vector<long long> s(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	long long ret = 0;
	for (int C = 1; C < n; C++) {
		long long tmp = 0;
		set<int> ckd;
		for (int i = 0; i <= n - 3; i += C) {
			if (ckd.count(i)) break;
			int A = n - 1 - i;
			int B = A - C;
			if (A <= C) break;
			if (A <= B) break;
			if (i == n - 1 - i) break;
			ckd.insert(i);
			ckd.insert(n - 1 - i);
			tmp += s[i] + s[n - 1 - i];
			cmx(ret, tmp);
		}
	}
	cout << ret << endl;
	return 0;
}