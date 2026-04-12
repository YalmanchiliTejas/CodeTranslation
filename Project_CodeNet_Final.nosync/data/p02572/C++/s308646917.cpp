#include <bits/stdc++.h>
using namespace std;

long long mod = 1000000007;

int main() {
    int n;
    cin >> n;
    long long a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long sum = 0;
    long long acc = 0;
    for (int i = 0; i < n; ++i) {
        sum += (a[i] * acc) % mod;
        acc = (acc + a[i]) % mod;
    }
    cout << sum % mod << "\n";
    return 0;
}
