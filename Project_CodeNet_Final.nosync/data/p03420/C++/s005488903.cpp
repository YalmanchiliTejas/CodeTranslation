#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    long long ans = 0;
    for (int b = K + 1; b <= N; b++) ans += (N + 1)/b*(b - K) + max(0, (N + 1)%b - K);
    if (!K) ans -= N;

    cout << ans << endl;
    return 0;
}