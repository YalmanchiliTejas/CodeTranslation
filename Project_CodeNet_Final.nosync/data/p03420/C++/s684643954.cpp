#include <bits/stdc++.h>
using namespace std;
typedef long long int64;

int64 solve(int N, int K) {
    int64 res = 0;
    for(int b = K + 1; b <= N; ++b) {
        int t = N / b;
        int n = b - K;
        int r = N % b;
        int m = max(0, r - K + 1);
        if(b == N) t = 1, m = 0;
        res += (int64)t * n + m;
    }
    return res;
}

int main() {
    int N, K;
    cin >> N >> K;
    cout << (K == 0 ? (int64)N * N : solve(N, K)) << '\n';
    return 0;
}
