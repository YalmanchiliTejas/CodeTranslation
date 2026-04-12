#include "bits/stdc++.h"

using namespace std;
using LL = long long;

constexpr int N = 105;

LL cache[N][2][10];

int n, req;
int arr[N];


LL dp(int k, int small, int cnt) {
	if (cnt > req) return 0;
	if (k == n) {
		return (cnt == req);
	}

	LL &rv = cache[k][small][cnt];
	if (~rv) return rv;
	rv = 0;

	if (small == 0) {
		for (int i = 0; i <= min(arr[k], 9); i++) {
			rv += dp(k + 1, i < arr[k], cnt + (i > 0));
		}
	}
	else {
		for (int i = 0; i <= 9; i++) {
			rv += dp(k + 1, 1, cnt + (i > 0));
		}
	}
	return rv;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    string s;
    cin >> s >> req;
    n = s.size();

    for (int i = 0; i < n; i++) arr[i] = s[i] - '0';

    memset(cache, -1, sizeof cache);
    LL result = dp(0, 0, 0);
	cout << result << "\n";
}