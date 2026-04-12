#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

signed main() {
    int n;
    long long a[200000], ans, sum;
    
    cin >> n;
    sum = 0;
    for (int i=0 ;i<n ;i++ ) {
        cin >> a[i];
        sum += a[i];
        sum = sum % MOD;
    }
    
    ans = 0;
    for (int i=0 ;i<n ;i++ ) {
        sum -= a[i];
        if (sum < 0) {
            sum += MOD;
        }
        ans += a[i] * sum;
        ans = ans % MOD;
    }
    
    cout << ans << endl;
    return (0);
}