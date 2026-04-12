#include <iostream>

using namespace std;

int main(void) {
    long long N, K;
    cin >> N >> K;

    if (K == 0) {
        cout << N * N << endl;
        return 0;
    }
    long long ans = 0;
    for (long long i = 1; i <= N; ++i) {
        if (i - 1 >= K) {
            ans += (i - K) * (N / i);
            ans += max(0LL, (N % i) - K + 1);
        }
    }

    cout << ans << endl;
    return 0;
}