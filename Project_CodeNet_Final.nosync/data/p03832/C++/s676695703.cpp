#include <bits/stdc++.h>
using namespace std;

const int len = 1005, mod = 1e9+7;
int per[len], inv[len], dp[len][len];

int add(int a, int b){
    return (a+b)%mod;
}

int mul(int a, int b){
    return (a*1LL*b)%mod;
}

int po(int a, int b){
    if (b == 0)
        return 1;
    if (b%2 == 0)
        return po(mul(a, a), b/2);
    return mul(a, po(mul(a, a), b/2));
}

int main(){
    int n, a, b, c, d;
    scanf("%d %d %d %d %d", &n, &a, &b, &c, &d);

    per[0] = inv[0] = 1;
    for (int i = 1; i <= n; i++){
        per[i] = mul(per[i-1], i);
        inv[i] = po(per[i], mod-2);
    }

    dp[a-1][0] = 1;
    for (int x = a; x <= b; x++){
        for (int i = 0; i <= n; i++){
            int cur = 1;
            for (int j = 1; j < c && j*x <= i; j++){
                cur = mul(cur, per[i-(j-1)*x]);
                cur = mul(cur, inv[i-j*x]);
                cur = mul(cur, inv[x]);
            }

            dp[x][i] = dp[x-1][i];
            for (int j = c; j <= d && j*x <= i; j++){
                cur = mul(cur, per[i-(j-1)*x]);
                cur = mul(cur, inv[i-j*x]);
                cur = mul(cur, inv[x]);

                //printf("x = %d, i = %d, j = %d, cur = %d\n", x, i, j, cur);

                dp[x][i] = add(dp[x][i], mul(mul(cur, inv[j]), dp[x-1][i-j*x]));
            }

            //printf("dp(%d, %d) = %d\n", x, i, dp[x][i]);
        }
    }

    printf("%d\n", dp[b][n]);
    return 0;
}
