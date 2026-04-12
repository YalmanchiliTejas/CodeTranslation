#include <iostream>
using namespace std;

int main() {
    long long n, k, result = 0;
    cin >> n >> k;
    if (k == 0) {
        result += n * n;
    } else {
        for (long long j = k + 1; j <= n; j++) {
            result += (j - k) * (n / j) + max(n % j - k + 1, 0ll);
        }
    }
    cout << result;
    return 0;
}
