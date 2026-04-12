#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int N, K;

int main() {
    cin >> N >> K;
    
    if (K == 0) {
        cout << 1ll * N * N << endl;
        return 0;
    }
    
    long long ans = 0;
    for (int b = K + 1; b <= N; b++) {
        int q = N / b;
        if (K == 0) q--;
        ans += (b - K) * q + max(0, N % b - K + 1);
    }
    cout << ans << endl;
}