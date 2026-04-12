#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 110, MAX_K = 20;
ll dp0[MAX_N][MAX_K];
ll dp1[MAX_N][MAX_K];
int L, K;
char N[MAX_N];

int main()
{
    scanf("%s", N);
    L = strlen(N);
    for(int i = L; i > 0; --i) N[i] = N[i-1]; // 1-indexedにした
    N[0] = '0'; // 0番目を0にしても問題に影響はない
    scanf("%d", &K);

    dp1[0][0] = 1LL; // 0番目を0にしたとき、1～L番目の選び方次第でNより大きくなることがあるのでdp0[0][0] = 0
    for(int i = 1; i <= L; ++i) {
        ll k = N[i] - '0';
        dp0[i][0] = dp0[i-1][0] + (k > 0 ? dp1[i-1][0] : 0);
        dp1[i][0] = k > 0 ? 0 : dp1[i-1][0]; // k > 0のとき、dp1[i-1][0]から遷移しようにしてもかならずNより大きくなってしまうので0になる
        for(int j = 1; j <= K; ++j) {
            dp0[i][j] = 9LL*dp0[i-1][j-1] + dp0[i-1][j] 
                        + max(0LL, k-1)*dp1[i-1][j-1]
                        + (k > 0LL ? dp1[i-1][j] : 0LL);
            dp1[i][j] = k > 0 ? dp1[i-1][j-1] : dp1[i-1][j];
            
        }
    }
    printf("%lld\n", dp0[L][K] + dp1[L][K]);
    return 0;
}