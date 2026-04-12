#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <array>
#include <vector>
#include <functional>
#include <numeric>
#include <limits>
using namespace std;

int main(void) {
	int n, i, j, k;
	cin >> n;
	vector<string> s(n);
	vector<string> ans(51);
	cin >> s[0];
	ans[0] = s[0];
	for (i = 1; i < n; i++) {
		cin >> s[i];
		for (j = 0; j < ans[i - 1].size(); j++) {
			for (k = 0; k < s[i].size(); k++) {
				if (ans[i - 1][j] == s[i][k]) {
					ans[i] += s[i][k];
					ans[i - 1].erase(ans[i - 1].begin() + j);
					s[i].erase(s[i].begin() + k);
					k = -1; j = 0;
				}
			}
		}
	}
	sort(ans[n - 1].begin(), ans[n - 1].end());
	cout << ans[n - 1] << endl;
	return 0;
}