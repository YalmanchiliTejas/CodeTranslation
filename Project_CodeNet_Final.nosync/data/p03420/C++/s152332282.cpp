#include <iostream>

using namespace std;

int main()
{
    long long N, K;

    cin >> N >> K;

    long long cnt = 0;

    if (K == 0) {
        cout << N * N;
        return 0;
    }

    for (int i = 2; i <= N; i++) {
        if (i > K) {
            cnt += (N / i) * (i - K);
            long long tmp = (N % i) - K + 1;
            if (tmp > 0) cnt += tmp;
        }
    }

    cout << cnt;

    return 0;
}
