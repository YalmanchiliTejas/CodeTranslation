#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <algorithm>
#include <cmath>
#include <queue>
#include <bitset>
#include <iomanip>
#include <limits>
#include <chrono>
#include <random>
#include <array>
#include <unordered_map>
#include <functional>
#include <complex>
#include <numeric>
#include <cctype>
#include <map>
#include <set>
#include <cstdlib>
#include <bitset>
#include <tuple>
#include <assert.h>
#include <deque>


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

constexpr long long INF = 1LL << 60;
constexpr int inf = 1000000007;
//constexpr long long mod = 1000000007LL;
constexpr long long mod = 998244353LL;

using namespace std;
typedef long long ll;


using Tp = tuple<int, int, int>;
vector<Tp> update;
vector<vector<int>> dp;
vector<int> mx;
int allmax;
void st(int i, int j, int k) {
	update.emplace_back(i, j, k);
	update.emplace_back(j, i, k);
}

void upd() {
	for (auto [a, b, c] : update) {
		chmax(dp[a][b], c);
		chmax(mx[a], c);
		chmax(allmax, c);
	}
	update.clear();
}
int main()
{

	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n; cin >> n;
	vector<int> a(n * 3); for (int i = 0; i < n * 3; i++) cin >> a[i], a[i]--;
	dp.assign(n, vector<int>(n, -1));
	mx.assign(n, -1);
	dp[a[0]][a[1]] = dp[a[1]][a[0]] = mx[a[0]] = mx[a[1]] = 0;
	int pl = 0;
	for (int i = 2; i + 2 < 3 * n; i += 3) {
		if (a[i] == a[i + 1] and a[i + 1] == a[i + 2]) {
			pl++;
			continue;
		}
		for (int kkt = 0; kkt < 3; kkt++) {
			vector<int> v;
			int r = a[i + kkt];
			for (int j = 0; j < 3; j++) if (j != kkt) v.emplace_back(a[i + j]); 
			st(v[0], v[1], allmax);
			if(dp[r][r] != -1) st(v[0], v[1], dp[r][r] + 1);
			if (v[0] == v[1]) {
				for (int j = 0; j < n; j++) if (dp[v[0]][j] != -1) st(r, j, dp[v[0]][j] + 1);
			}
			for (int j = 0; j < n; j++) st(r, j, mx[j]);
		}
		upd();
	}
	int res = 0; 
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
		if (i == j and i == a.back()) {
			chmax(res, dp[i][j] + 1);
		}
		else {
			chmax(res, dp[i][j]);
		}
	}
	res += pl;
	cout << res << endl;
}
