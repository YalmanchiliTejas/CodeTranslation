#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // Another formulation: Given a random placement what is the expected value of:
    // \sum_{i < j} dist(p[i], p[j])
    // and then multiply with \binom{n*m}{k}.
    // The same as:
    // \sum_{p_1 < p_2} dist(p_1, p_2) \cdot P(p_1 and p_2 chosen)
    // We have P(p_1 and p_2) chosen = \binom{n*m-2}{k-2}/\binom{n*m}{k}
    // So the final sum we are looking at is:
    // \binom{nm-2}{k-2} \cdot \sum_{p_1 < p_2} dist(p_1, p_2)
    // Now what is \sum_{p_1 < p_2} dist(p_1, p_2)? It's the same as:
    // \frac{1}{2} \sum_{(x_0, y_0) != (x_1, y_1)} \abs{x_0-x_1} + \abs{y_0-y_1}
    // Which is the same as:
    // \frac{1}{2} \sum_{x_0, x_1, y_0, y_1} (\abs{x_0-x_1} + \abs{y_0-y_1})
    // Now we have:
    // \frac{1}{2} \sum_{x_0, x_1, y_0, y_1} \abs{x_0-x_1}
    // =
    // \frac{m^2}{2} \sum_{x_0, x_1} \abs{x_0-x_1}
    // Now let f(n) = \sum_{0 <= x_0, x_1 < n} \abs{x_0-x_1}
    // Then f(n+1) = f(n) + (1 + ... + n)*2 = f(n) + n*(n+1)
    // This fits since:
    // f(0) = 0
    // f(1) = 0
    // f(2) = 2 = 0 + 1*2
    // f(3) = 8 = 2 + 2*3, etc.
    // So we have that f(n) = 2\binom{n}{2} + ... + 2\binom{2}{2} = 2\binom{n+1}{3}
    // This also fits since:
    // f(2) = 2 = 2\binom{3}{3}
    // f(3) = 8 = 2\binom{4}{3}, etc.
    // So the final formula is:
    // \binom{nm-2}{k-2} \cdot \left ( m^2 \binom{n+1}{3} + n^2 \binom{m+1}{3} \right )
    long long prime = 1000000007;
    function<long long (long long, long long)> pow = [&](long long a, long long r) {
        if (r == 0) {
            return 1LL;
        }
        long long y = pow(a, r/2);
        long long z = (y*y) % prime;
        return r % 2 == 1 ? (a*z) % prime : z;
    };
    auto inv = [&](long long a) {
        return pow(a, prime-2);
    };
    auto down_to = [&](long long n, long long r) {
        // Calculates n(n-1)...(n-r+1)
        long long product = 1;
        while (r > 0) {
            product = (product * n) % prime;
            --n;
            --r;
        }
        return product;
    };
    auto binom = [&](long long n, long long k) {
        return (down_to(n, k) * inv(down_to(k, k))) % prime;
    };
    long long N, M, K;
    cin >> N >> M >> K;
    long long result = binom(N*M-2, K-2) * ( M * M % prime * binom(N+1, 3) % prime + N * N % prime * binom(M+1, 3) % prime) % prime;
    cout << result << endl;
    return 0;
}
