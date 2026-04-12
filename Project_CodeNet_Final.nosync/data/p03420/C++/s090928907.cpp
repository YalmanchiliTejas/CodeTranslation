#include<bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    long long ans = 0;
    for (long long b = 1; b <= N; b++)
    {
        long long p = N / b, r = N % b;
        ans += p * max(0ll, b - K) + max(0ll, r - K + 1);
        if(K == 0) ans--;
    }

    cout << ans << endl;
}