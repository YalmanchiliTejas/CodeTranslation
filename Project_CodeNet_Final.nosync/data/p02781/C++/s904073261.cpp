#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>

using namespace std;

#define LL long long

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

vector<int> getInt() {
	char c = getchar();
	vector<int> res;
	while (c >= '0' && c <= '9') {
		res.push_back(c - '0');
		c = getchar();
	}
	return res;
}
int main() {
	vector<int> nn = getInt();
	int n = nn.size(); // n <= 100
	int k;
	cin >> k;
	LL **f = new LL*[n + 1];
	for (int i = 0; i <= n; ++i) {
		f[i] = new LL[4];
	}
	f[0][0] = f[0][1] = f[0][2] = f[0][3] = 0;
	for (int i = 1; i <= n; ++i) {
		f[i][1] = f[i - 1][1] + 9;
		f[i][2] = f[i - 1][2] + f[i - 1][1] * (LL)(9);
		f[i][3] = f[i - 1][3] + f[i - 1][2] * (LL)(9);
		// cout << f[i][1] << ' ' << f[i][2] << ' ' << f[i][3] << endl;
	}
	// f[1][...]: 1...9
	// f[2][...]: 1 ... 99
	// f[100][...] 1 ... 10^100 - 1
	// f[n - 1][k]: 1...10^[n - 1] - 1
	// then we need 10^(n - 1) ... nn
	LL res = f[n - 1][k];
	if (k == 1) {
		res += nn[0];
	}
	if (k == 2) {
		res += (nn[0] - 1) * f[n - 1][1];
		//if (n >= 2) {
		int kk = 1;
		while (kk < nn.size() && nn[kk] == 0) { 
			++kk;
		}
		if (kk != nn.size()) {
			res += (nn[kk] * 1 + f[n - kk - 1][1]);
		}
		//}
	}
	if (k == 3) {
		res += (LL)(nn[0] - 1) * f[n - 1][2];
		// cout << "res = " << res << endl;
		int k1, k2;
		k1 = 1;
		while (k1 < nn.size() && nn[k1] == 0) {
			++k1;
		}
		// cout << "k1 = " << k1 << endl;
		if (k1 != nn.size()) {
			res += ((LL)(nn[k1] - 1) * f[n - k1 - 1][1] + f[n - k1 - 1][2]);
			k2 = k1 + 1;
			while (k2 < nn.size() && nn[k2] == 0) {
				++k2;
			}
			if (k2 != nn.size()) {
				res += ((LL)(nn[k2]) * 1 + f[n - k2 - 1][1]);
			}
		}
	}
	cout << res << endl;
	return 0;
}