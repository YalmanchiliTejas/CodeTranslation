#include<bits/stdc++.h>
using namespace std;
const long long mod = 1000000000 + 7;
#define LL long long
LL N, M, K;
LL ny[200001], jc[200001];
int main(){
    cin>>N>>M>>K;
    ny[0] = ny[1] = 1;
    jc[0] = jc[1] = 1;
    for(int i = 2;i <= 200000; i++){
        ny[i] = (-1 * mod / i * ny[mod % i] % mod + mod) % mod;
        //printf("ny[%d]=%lld i*ny=%d\n", i, ny[i], 1LL * (i * ny[i]) % mod);
    }
    for(int i = 2;i <= 200000; i++){
        ny[i] = 1LL * (1LL * ny[i] * ny[i-1]) % mod;
        jc[i] = jc[i-1] * i % mod;
        //printf("ny[%d] = %lld, jc=%lld ji=%d\n", i, ny[i], jc[i], 1LL * (ny[i] * jc[i]) % mod);
    }
    LL ans = 0;
    LL C = jc[M*N-2] * ny[K-2] % mod * ny[M*N-K] % mod;
    //printf("c=%lld\n", C);
    for(LL i = 1;i <= N; i++){
        for(LL j = 1;j <= M; j++){
      //      cout<<ans<<"\n";
            (ans += ((M - j + 1) * (N - i + 1) * (N - i + M - j) / 2 % mod + (j - 1) * (N - i + 1) * (N - i) / 2 % mod + (N - i) * j * (j - 1) / 2 % mod) % mod * C % mod) %= mod;
            //printf("%lld\n", ans);
        }
    }
    cout<<ans<<endl;
    return 0;
}

