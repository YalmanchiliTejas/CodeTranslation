#include<iostream>

using namespace std;

int main() {
    int n, k;

    cin >>n >>k;

    if (k == 0) {
        cout << 1LL * n * n << endl;
    } else {
        long long ans = 0;
        for (int i = k + 1; i <= n; i++) {
            ans += (n / i) * (i - k);
            if (n % i >= k) {
                ans += n % i - k + 1;
            }
        }

        cout << ans << endl;
    }

    return 0;
}