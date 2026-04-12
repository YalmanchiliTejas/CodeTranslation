#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, k, res = 0;
    cin >> n >> k;
    if (k == 0)
        cout << n * n;
    else {
        for (long long i = k + 1; i <= n; i++) {
            long long d = n / i;
            long long x = n % i;
            if(x >= k) res += x - k + 1;
            res += d * (i - k);
        }
        cout << res;
    }
    return 0;
}