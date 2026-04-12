#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <numeric>
#include <utility>
#include <iomanip>

using namespace std;
using int64 = long long;

struct aaa{aaa(){cin.tie(nullptr); ios::sync_with_stdio(false); cout<<fixed<<setprecision(20);};}aaa;

int main() {
    int n;
    cin >> n;
    vector<int64> a(n);
    vector<int64> sum(n+1, 0);
    for (int i=0; i<n; i++) cin >> a[i];

    int64 mod = 1e9 + 7;
    for (int i=n-1; i>=0; i--)  {
        sum[i] = sum[i+1] + a[i];
        sum[i] %= mod;
    }

    int64 ans = 0;
    for (int i=0; i<n; i++) {
        ans += (sum[i] + mod - a[i]) % mod * a[i];
        ans %= mod;
    }
    cout << ans << endl;
}
