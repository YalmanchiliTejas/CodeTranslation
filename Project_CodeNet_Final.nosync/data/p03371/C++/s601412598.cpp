#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;
int dp[100010];
int main()
{
    int A,B,C,X,Y,n,m,ans;int flag=0;
    scanf("%d %d %d %d %d",&A,&B,&C,&X,&Y);
    if(X>Y){
        n=Y;flag=1;
        m=X;
    }
    if(X<Y){
        n=X;flag=2;
        m=Y;
    }
    if(X==Y){
        n=X;
    }
    for(int i=1;i<=n;i++){
        dp[i]=min(dp[i-1]+A+B,dp[i-1]+2*C);
    }
    if(flag!=0){
            if(flag==1){
        for(int j=n+1;j<=m;j++){
            dp[j]=min(dp[j-1]+A,dp[j-1]+2*C);
        }
        ans=dp[m];
     }
     if(flag==2){
        for(int j=n+1;j<=m;j++){
            dp[j]=min(dp[j-1]+B,dp[j-1]+2*C);
        }
        ans=dp[m];
     }
    }
    else ans=dp[n];
    printf("%d\n",ans);
    return 0;
}