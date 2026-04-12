#include <bits/stdc++.h>

using namespace std;


int main() {
    long long N,K; cin >> N >> K;
    long long ans = 0ll;

    if(K==0) {
        cout << N*N << endl;
        return 0;
    }

    for(long long b=1ll;b<=N;b++) {
        long long res = N%b;
        long long p = N/b;
        ans += p * max(0ll, b-K) + max(0ll, res-K+1ll);
    }

    cout << ans << endl;
    return 0;
}
