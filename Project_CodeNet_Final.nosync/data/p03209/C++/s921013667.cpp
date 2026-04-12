#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

long long len(long long n) {
    if (n == 0) return 1;
    return 3 + 2 * len(n - 1);
}

long long pati(long long n) {
    if (n == 0) return 1;
    return 1 + 2 * pati(n - 1);
}

long long f(long long n, long long x) {
    if (x <= 0) return 0;
    if (n == 0) return x == 1;
    if (x == 1) return 0;
    if (x == 1 + len(n - 1) + 1 + len(n - 1) + 1) return pati(n);
    if (x == 1 + len(n - 1) + 1) return pati(n - 1) + 1;
    if (x <= 1 + len(n - 1)) return f(n - 1, x - 1);
    if (x <= 1 + len(n - 1) + 1 + len(n - 1)) return pati(n - 1) + 1 + f(n - 1, x - 1 - len(n - 1) - 1);
    return 0;
}

int main() {
    long long n, x;
    cin >> n >> x;
    cout << f(n, x) << endl;
}

