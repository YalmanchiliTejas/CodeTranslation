#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <utility>

using namespace std;

int main() {
    long N, K;
    cin >> N >> K;

    long res = 0;
    for (long d = N; d > K; d--)
        res += max(0l, N % d - K + 1) + (d - K) * (N / d);

    if (K == 0) res -= N;

    cout << res << endl;
    return 0;
}
