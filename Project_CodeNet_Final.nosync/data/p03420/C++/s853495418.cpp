#include <iostream>
using namespace std;

int main() {
    long long n, k, result = 0;
    cin >> n >> k;
    if (k == 0) {
        result += n * n;
    } else {
        for (long long j = k + 1; j <= n; j++) {
            result += (n + 1) / j * (j - k);
            if (n % j >= k && (n + 1) % j != 0) {
                result += n % j - k + 1;
            }
        }
    }
    cout << result;
    return 0;
}
