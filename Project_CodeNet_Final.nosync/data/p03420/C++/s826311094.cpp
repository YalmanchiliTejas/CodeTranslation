#include <iostream>
using namespace std;

using int64 = long long;

int main() {
    int64 N, K;
    cin >> N >> K;

    if (K == 0) {
        cout << N * N << endl;
        return 0;
    }

    int64 ans = 0;
    for (int64 b = K + 1; b <= N; b++) {
        int64 cycle = N / b;  // cycle回[K, b-1]が登場する
        int64 rem = N % b;

        ans += cycle * (b - K);
        ans += max(0LL, rem - K + 1);
    }

    cout << ans << endl;

    return 0;
}