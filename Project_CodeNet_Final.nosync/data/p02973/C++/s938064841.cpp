#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout << (x) << endl
#define Int int64_t
#define fi first
#define se second
 
Int INF = 1e18;
Int mod = 1e9+7;
//Int mod = 998244353;

int main() {
    Int n;
    cin >> n;
    vector<Int> a(n);
    for (Int i = 0; i < n; i++) {
        cin >> a[i];
    }
    reverse(a.begin(), a.end());
    vector<Int> dp(n, INF);
    for (Int i = 0; i < n; i++) {
        *upper_bound(dp.begin(), dp.end(), a[i]) = a[i];
    }
    dump(lower_bound(dp.begin(), dp.end(), INF) - dp.begin());
    return 0;
}