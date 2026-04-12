#include<bits/stdc++.h>
using namespace std;
const int N=3000+10;
int p=998244353,dp[N],n,s,x,ans;
int main(){
    scanf("%d%d",&n,&s);
    for(int i=1;i<=n;++i){
        scanf("%d",&x);
        dp[0]=i;
        for(int j=s;j>=x;--j)dp[j]=(dp[j]+dp[j-x])%p;
        ans=(ans+dp[s])%p;
    }
    printf("%d",ans);
    return 0;
}
