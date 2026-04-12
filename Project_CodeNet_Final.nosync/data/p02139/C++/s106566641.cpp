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
	int N, Q;
	cin >> N >> Q;
	int X = 0;
	int t, a;
	for (int i = 0; i < Q; i++) {
		cin >> t >> a;
		if (t == 0) {
			int res = (X + a) % N;
			if (res == 0)res = N;
			cout << res << endl;
		}
		else {
			X = (X + a) % N;
		}
	}
}
