#define _USE_MATH_DEFINES

#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <unordered_set>
#include <climits>
#include <ctime>

using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

void solve() {
	string s;
	getline(cin, s);
	for (int i = 1; i < s.size(); ++i) {
		if (s[i - 1] == 'A' && s[i] == 'C') {
			cout << "Yes";
			return;
		}
	}
	cout << "No";
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	solve();

#ifdef LOCAL
	cerr << double(clock()) / CLOCKS_PER_SEC << " sec" << endl;
#endif
	return 0;
}