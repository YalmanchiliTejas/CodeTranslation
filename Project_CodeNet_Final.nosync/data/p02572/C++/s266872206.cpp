#include <iostream>
#include <vector>

using namespace std;

using int64 = long long;

const int MOD = 1000000007;
int main () {
    int n;
    cin >> n;
    vector a(n, 0LL);
    for (int i=0; i<n; i++) cin >> a[i];

    vector csum(n, 0LL);
    for (int i=n-1; i>0; i--) {
        csum[i-1] = csum[i] + a[i];
        csum[i-1] %= MOD;
    }

    int64 ans = 0;
    for (int i=0; i<n; i++) {
        ans += csum[i] * a[i];
        ans %= MOD;
    }

    cout << ans << endl;
}