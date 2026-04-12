#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int dp[1005][1005], f1[1005], f2[1005];
int pow2(int a, int b){
    int ans = 1;
    while(b){
        if(b%2 == 1) ans = ans*1ll*a%mod;
        a = a*1ll*a%mod;
        b/=2;
    }
    return ans;
}
int ncr(int a, int b){
    return f1[a]*1ll*f2[b]%mod*f2[a-b]%mod;
}
int main(){
    f1[0] = f2[0] = 1;
    for(int i=1;i<=1000;i++){
        f1[i] = f1[i-1]*1ll*i%mod;
        f2[i] = pow2(f1[i], mod-2);
    }
    int n, a, b, c, d;
    scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
    for(int j=a-1;j<=b;j++) dp[0][j] = 1;
    for(int i=1;i<=n;i++){
        for(int j=a;j<=b;j++){
            dp[i][j] = (dp[i][j] + dp[i][j-1])%mod;
            if(dp[i-1][j-1] == 0) continue;
            int cnt = 1;
            for(int k=i+j-1;k<=n;k+=j){
                if(c <= cnt && cnt <= d) dp[k][j] = (dp[k][j] + dp[i-1][j-1]*1ll*ncr(n-i+1, cnt*j)%mod*f1[cnt*j]%mod*pow2(f2[j], cnt)%mod*f2[cnt])%mod;
                cnt++;
            }
        }
    }
    printf("%d\n", dp[n][b]);
}