#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>

using namespace std;

#define int long long

string s;
int n, k;

int ans = 0;

void rec(int pos, int fl, int cnt, int c) {
	if (pos == n) {
		if (cnt == k) ans += c;
	} else {
		int v = s[pos] - '0';
		if (cnt < k) {
			if (fl) {
				rec(pos + 1, fl, cnt + 1, c * 9);
			} else if (v > 0) {
				rec(pos + 1, 1, cnt + 1, c * (v - 1));
				rec(pos + 1, 0, cnt + 1, c);
			}
		}
		rec(pos + 1, fl | (v > 0), cnt, c);
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> s >> k;
	n = (int)s.size();
	rec(0, 0, 0, 1);
	cout << ans << endl;
}
