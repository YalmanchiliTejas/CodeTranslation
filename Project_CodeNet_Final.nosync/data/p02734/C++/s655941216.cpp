#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
int GM(int x){
    return x >= mod? x-mod : x;
}

int main()
{
    int n ,s ,ans = 0 ,dp[3001] = {0};
    scanf("%d%d",&n,&s);
    for(int a,i=0; i<n; i++){
        scanf("%d",&a);
        for(int j=s; j>=a; j--)
            dp[j] = GM(dp[j]+dp[j-a]);
        dp[a] = GM(dp[a]+i+1);
        ans = GM(ans+dp[s]);
    }
    printf("%d\n",ans);
}
