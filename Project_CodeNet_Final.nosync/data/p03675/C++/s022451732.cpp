#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <utility>
#include <cstdio>
#include <cmath>
#include <deque>

#define REP(i,n) for(int i = 0; i < (n); ++i)
#define REP1(i,n) for(int i = 1; i <= (n); ++i)
#define RREP(i, n) for(int i = (n) - 1; i >= 0; --i)
#define ALL(a) begin(a), end(a)
#define X first
#define Y second

using ll = long long;
using namespace std;
using vi = vector<int>;
using pii = pair<int, int>;

constexpr int INF = 1e9 + 1;
constexpr ll LLINF = 4 * 1e18 + 1;
// constexpr int INF = 2147483647; // 2 * 1e9
// constexpr ll LLINF = 9223372036854775807; // 9 * 1e18

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vi a(n + 1);
	REP1(i, n) cin >> a[i];
	deque<int> b;
	int amr = n  % 2;
	REP1(i, n) {
		if (i % 2 == amr) b.push_front(a[i]);
		else b.push_back(a[i]);
	}
	cout << b.front(); b.pop_front();
	while (!b.empty()) {
		cout << " " << b.front();
		b.pop_front();
	}
	cout << "\n";
	return 0;
}
