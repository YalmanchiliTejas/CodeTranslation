#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    int N, K;
    ll ret = 0;
    cin >> N >> K;

    if(K == 0) ret -= N;
    for(int k=K; k<N; k++) {
        ret += N - k;
        int i=1;
        for(int b=N-k; b>=k+1; b=(N-k)/i) {
            ret += b - k;
            i++;
        }
    }

    return !printf("%lld\n", ret);
}