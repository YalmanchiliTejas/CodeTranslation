#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <assert.h>
#include <math.h>
#include <stack>
#include <queue>
#include <list>
using namespace std;

// #define __DEBUG__

#ifdef __DEBUG__
bool debug_disabled = false;
#else
bool debug_disabled = true;
#endif

#define dbg if (debug_disabled) {} else cerr

const int MOD = 1000000007;

long long nums[200010];
long long suff_sums[200010];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> nums[i];
    for (int i = n - 2; i >= 0; --i) suff_sums[i] = (nums[i + 1] + suff_sums[i + 1]) % MOD;
    long long res = 0;
    for (int i = 0; i < n; ++i) {
        long long tres = (nums[i] * suff_sums[i]) % MOD;
        res = (res + tres) % MOD;
    }
    cout << res << endl;
}

int main() {
    cout.setf(ios::fixed, ios::floatfield);
    cout.setf(ios::showpoint);
    cout.precision(12);
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; ++i) {
        solve();
    }

    return 0;
}
