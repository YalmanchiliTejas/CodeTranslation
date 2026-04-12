#include <bits/stdc++.h>
using namespace std;

int main() {
    long long ans = 0;
    int N, K; scanf("%d%d",&N,&K);
    if(K == 0) return !printf("%lld", 1LL*N*N);
    for(int b=K+1; b<=N; b++) {
        ans += ((N - (b-1)) / b + 1) * (b-K);
        if((N - (b-1)) % b != 0) ans += max(N%b - K + 1, 0);
    }
    printf("%lld", ans);
    return 0;
}
