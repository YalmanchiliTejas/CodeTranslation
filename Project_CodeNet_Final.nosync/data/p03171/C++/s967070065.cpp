#include <memory.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

#define mod 1000000007

int n;
long long int a[3000];
long long int result[3010][3010][2];
static const long long int INIT = (long long int)mod * 3000;

long long int solve(int l, int r, int nowPlayer) {
	if (l == r) return 0;
	if (result[l][r][nowPlayer] != INIT) return result[l][r][nowPlayer];
	if (nowPlayer == 0) {
		long long int res1 = a[l] + solve(l + 1, r, 1);
		long long int res2 = a[r - 1] + solve(l, r - 1, 1);
		return result[l][r][nowPlayer] = max(res1, res2);
	} else {
		long long int res1 = -a[l] + solve(l + 1, r, 0);
		long long int res2 = -a[r - 1] + solve(l, r - 1, 0);
		return result[l][r][nowPlayer] = min(res1, res2);
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			result[i][j][0] = result[i][j][1] = INIT;
		}
	}
	cout << solve(0, n, 0) << endl;
}