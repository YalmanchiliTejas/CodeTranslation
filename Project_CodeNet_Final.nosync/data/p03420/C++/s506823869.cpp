#include <iostream>
using namespace std;
int n, k;
int main() {
    cin >> n >> k;
    if (k == 0) {
        return !printf("%lld\n", (long long)n*n);
    }
    long long ans = 0;
    for (int b = k+1; b <= n; b ++) {
        int t = (n+1)/b;
        if (t*b-1<n) t ++;
        ans += t*(b-k) - min(t*b-1 - n, b-k);
    }
    cout << ans << endl;
}