#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <iomanip>
#include <map>
#include <set>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <iterator>
#include <string>
#include <limits>

using namespace std;

using i64 = int64_t;
using P = pair<i64, i64>;
i64 mod = 1000000007;
//i64 mod = 998244353;
int int_max = 2147483647;
i64 INF = 1e16;
int max_n = 1e5;


int main(int argc, char **argv) {
    i64 n;
    cin >> n;
    vector<i64> a(n,0), a_sum(n,0);

    for (int i=0; i<n; ++i) {
        cin >> a[i];
    }
    a_sum[n-1] = a[n-1];
    for (i64 i = n-2; 0 <= i; --i) {
        a_sum[i] = a_sum[i+1] + a[i];
        a_sum[i] %= mod;
    }
    i64 ans{0};
    for (i64 i=0; i<n-1; ++i) {
        ans += (a[i] * a_sum[i+1] % mod);
        ans %= mod;
    }
    cout << ans << endl;

    return 0;
}