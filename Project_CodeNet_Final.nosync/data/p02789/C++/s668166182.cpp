#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <limits>

#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using namespace std;
using lint = long long;
using P = pair<int, int>;

int F, H, I, J, K, L, M, N, S, T, U;
// lint F, H, I, J, K, L, M, N, S, T, U;
// string S, T;
string ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	if (N == M) {
		ans = "Yes";
	} else {
		ans = "No";
	}

	cout << ans << endl;
	return 0;
}