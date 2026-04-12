#include <iostream>
#include <cassert>

#define DVSR  1'000'000'007
#define DVSRA 1'000'000'005

long long int add(long long int a, long long int b) {
    return (a % DVSR + DVSR + b % DVSR) % DVSR;
}

long long int multiply(long long int a, long long int b) {
    return (a * b) % DVSR;
}

long long int power(long long int a, long long int b) {
    if (b == 0) return 1;
    if (b == 1) return a % DVSR;
    int s = power(a, b/2);
    int ss = multiply(s, s);
    if (b % 2 == 0) return ss;
    return multiply(ss, a);
}

long long int divide(long long int a, long long int b) {
    return multiply(a, power(b, DVSRA));
}

long long int choose(int n, int k) {
    assert(k >= 0);
    if (k > n) return 0;
    if (k > n - k) return choose(n, n - k);

    long long int x = 1;

    for (int i=1; i<=k; i++)
        x = divide(multiply(x, n-i+1), i);

    return x;
}

long long int f(int N, int M) {
    long long int sum = 0;
    sum = add(sum, +multiply(power(N, 3), power(M, 2)));
    sum = add(sum, +multiply(power(N, 2), power(M, 3)));
    sum = add(sum, -multiply(power(N, 2), power(M, 1)));
    sum = add(sum, -multiply(power(N, 1), power(M, 2)));
    sum = divide(sum, 6);
    return sum;
}


long long int g(int n, int k) {
    long long int v = choose(n-2, k-2);
    return v;
}

int main() {
    // Given values
    int N; // # of rows
    int M; // # of columns
    int K; // # of pieces
    std::cin >> N >> M >> K;

    // Bounds
    assert(2 <= N * M && N * M <= 200'000); // the grid size
    assert(2 <= K && K <= N * M);           // # of piece

    // Computation
    long long int sum = multiply(
            f(N, M),  // the sum of the grid cost
            g(N*M, K) // # of combinations
            // choose(N*M-2, K-2) // # of combinations
            );

    std::cout << sum << std::endl;

    return 0;
}
