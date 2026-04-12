#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <unordered_map>
#include <numeric>
using namespace std;
using ll = long long;
#define rep(i, j, n) for(int i = (j); i < (n); ++i)
#define rrep(i, j, n) for(int i = (n) - 1; (j) <= i; --i)

constexpr ll MOD = 1000000007;
constexpr ll INF = 1LL << 60;


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n; cin >> n;
	vector<int> h(n);
	rep(i, 0, n) cin >> h[i];

	int mx = 0;
	int ans = 0;
	rep(i, 0, n) {
		if (mx <= h[i]) ++ans;
		mx = max(mx, h[i]);
	}
	cout << ans;

	return 0;
}
