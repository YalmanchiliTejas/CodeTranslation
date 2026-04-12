#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
int MOD = 1000000007;
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int H, W;
	cin >> H >> W;
	int res = 0;
	string S;

	int mx1 = -100000;
	int mn1 = 100000;
	int mx2 = -100000;
	int mn2 = 100000;
	for (int i = 0; i < H; i++) {
		cin >> S;
		for (int j = 0; j < W; j++) {
			if (S[j] == 'B') {
				mx1 = max(mx1, i + j);
				mn1 = min(mn1, i + j);
				mx2 = max(mx2, i - j);
				mn2 = min(mn2, i - j);
			}
		}
	}

	res = max(res, mx1 - mn1);
	res = max(res, mx2 - mn2);

	cout << res << endl;
}
