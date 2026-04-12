#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3010;
const int MOD = 998244353;
int a[N],n,m,dp[N][N];

int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;++i) scanf("%d",&a[i]);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j) dp[i][j]=dp[i-1][j];
        dp[i][a[i]]=(dp[i][a[i]]+i)%MOD;
        for(int j=a[i]+1;j<=m;++j){
            dp[i][j]=(dp[i][j]+dp[i-1][j-a[i]])%MOD;
        }
    }
    int ans=0;
    for(int i=1;i<=n;++i) ans=(ans+dp[i][m])%MOD;
    printf("%d\n",ans);
}