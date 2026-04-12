#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <iomanip>
using namespace std;
using ll = long long;
#define rep(i, j, n) for(int i = (j); i < (n); ++i)
#define rrep(i, j, n) for(int i = (n) - 1; (j) <= i; --i)
constexpr ll MOD = 1000000007;
constexpr ll INF = 1LL << 60;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(false);
	int n, k; string s;
	cin >> n >> s >> k;
	rep(i, 0, n) {
		if (s[i] != s[k - 1]) s[i] = '*';
	}
	cout << s;
	return 0;
}
