#include <bits/stdc++.h>

using namespace std;

long long prime = 998244353;

long long pow(long long a, long long r) {
    if (r == 0) return 1LL;
    long long y = pow(a, r/2);
    long long z = (y * y) % prime;
    if (r % 2 == 1) {
        return (a * z) % prime;
    }
    return z;
}

long long inv(long long a) {
    return pow(a, prime-2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> xs(n+1);
    xs[0] = 1;
    for (int i = 1; i <= n; ++i) {
        xs[i] = ((n-i+1) * xs[i-1]) % prime;
    }
    vector<long long> twos(n+1);
    twos[0] = 1;
    for (int i = 1;i <= n; ++i) {
        twos[i] = (twos[i-1] * 2) % prime;
    }
    long long sum = 0;
    for (int k = n/2 + 1; k <= n; ++k) {
        sum += xs[k] * xs[n-k] % prime * twos[n-k+1];
        sum %= prime;
    }
    sum = (sum * inv(xs[n])) % prime;
    long long result = (pow(3LL, (long long) n) - sum + prime) % prime;
    cout << result << endl;
    return 0;
}
