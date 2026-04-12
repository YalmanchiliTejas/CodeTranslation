#include <bits/stdc++.h>
using namespace std;
const int N=110;
char s[N];
int dp[5][N][2],k,n;

int dfs(int now,int num,int flag){
    int ans=0;
    if(num>k)return 0;
    if(now==n+1)return(num==k);
    if(dp[num][now][flag]!=-1)return dp[num][now][flag];
    int lim=9;if(flag)lim=s[now]-'0';
    for(int i=0;i<=lim;i++){
        ans+=dfs(now+1,num+(i!=0),flag&&(i==lim));
    }
    return dp[num][now][flag]=ans;
}
int main(){
    scanf("%s",s+1);
    scanf("%d",&k);
    memset(dp,-1,sizeof(dp));
    n=strlen(s+1);
    cout<<dfs(1,0,1);
}