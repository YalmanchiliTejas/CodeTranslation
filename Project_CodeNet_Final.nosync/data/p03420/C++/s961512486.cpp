#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N,K;
    cin >> N >> K;

    long long res = 0;
    for(long long b=K+1; b<=N; ++b) {
        long long p = N / b;
        long long r = N % b;
        res += p * max(0LL, b-K) + max(0LL, r - K + 1);
        if(K == 0) --res;
    }
    cout << res << endl;
}