#include <bits/stdc++.h>
using namespace std;
//#define int long long
const int MAX_N = 100100;
const long long INF = 1e18;

signed main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    vector<long long> dp(MAX_N, INF);
    for (int i = 0; i < n; i++) cin >> a[i];
    reverse(a.begin(), a.end());
    
    for (int i = 0; i < n; i++) {
        *upper_bound(dp.begin(), dp.end(), a[i]) = a[i];
    }
    int ans = lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
    cout << ans << endl;
    return 0;
}