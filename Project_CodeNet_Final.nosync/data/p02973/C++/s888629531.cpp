#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    int n; cin >> n;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    int dp[n+1];
    memset(dp, 1, sizeof(dp));
    for (int i = 0; i < n; i++) *upper_bound(dp, dp+n+1, -a[i]) = -a[i];
    cout << lower_bound(dp, dp+n+1, 1) - dp << endl;
}
