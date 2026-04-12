#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <iostream>
#include <utility>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <functional>
#include <stdlib.h>
#include <climits>
#include <iomanip>
#include <complex>
#include <cmath>
using namespace std;
signed main(void)
{
	int n, k;
	cin >> n >> k;
	long long ans = 0;
	for (int b = k + 1; b <= n; b++) {
		ans+=((n+1) / b)*(b-k) + max((n+1)%b - k, 0);
	}
	if (k == 0)ans -= n;
	cout << ans;
	return 0;
}
