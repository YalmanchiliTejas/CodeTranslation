#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
ll mem[3005][3005];
int n,s;
int a[3005];
int p[3005];
ll dp(int x, int sum){
    if (x == 0) return (sum == 0);
    if (sum == 0) return x+1;
    if (sum < 0) return 0;
    if (mem[x][sum] != -1) return mem[x][sum];
    ll ans = dp(x-1,sum) + dp(x-1,sum-a[x]);
    return mem[x][sum] = ans%mod;
}
int main(){
    scanf("%d%d",&n,&s);
    for (int i = 1; i <= n; i++){
        scanf("%d",&a[i]);
    }
    memset(mem,-1,sizeof(mem));
    ll ans = 0;
    for (int i = n; i >= 1; i--){
        ans += dp(i,s);
        ans %= mod;
    }
    printf("%lld",ans);
}
