#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    int N, K;
    cin >> N >> K;

    int64_t ans = 0;
    for(int b=K+1; b<=N; b++) {
        ans += (b-K) * (N/b) + max(N%b-max(K-1, 0), 0);
    }

    cout << ans << endl;
    return 0;
}
