#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> reverse_hash(int x, int b, int l) {
	vector<int> ret(l);
	int mul = 1;
	for (int i = 0; i < l; i++) {
		ret[i] = x / mul % b;
		mul *= b;
	}
	return ret;
}
int transform(int x, int f) {
	vector<int> v1 = reverse_hash(x, 5, 5);
	vector<int> v2 = reverse_hash(f, 4, 4);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 2; j++) {
			if (v1[i + j] != 0) v1[i + j] = (v1[i + j] - 1 + v2[i]) % 4 + 1;
		}
	}
	int ret = 0, mul = 1;
	for (int i = 0; i < 5; i++) {
		ret += v1[i] * mul;
		mul *= 5;
	}
	return ret;
}
int getscore(int x) {
	vector<int> v = reverse_hash(x, 5, 5);
	int ret = 0;
	for (int i = 0; i < 5; i++) {
		if (v[i] == 2) ret += 60;
		if (v[i] == 3) ret += 70;
		if (v[i] == 4) ret += 80;
	}
	return ret;
}
int Q, x;
int main() {
	cin >> Q;
	while (Q--) {
		vector<int> a(5);
		for (int i = 0; i < 5; i++) {
			int mul = 1;
			for (int j = 0; j < 5; j++) {
				cin >> x;
				a[i] += x * mul;
				mul *= 5;
			}
		}
		vector<vector<int> > dp(5, vector<int>(3125, -999999999));
		dp[0][a[0]] = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 3125; j++) {
				if (dp[i][j] == -999999999) continue;
				for (int l = 0; l < 256; l++) {
					int z = transform(a[i + 1], l);
					dp[i + 1][z] = max(dp[i + 1][z], dp[i][j] + getscore(transform(j, l)));
				}
			}
		}
		int ret = 0;
		for (int i = 0; i < 3125; i++) ret = max(ret, dp[4][i] + getscore(i));
		cout << ret << endl;
	}
	return 0;
}