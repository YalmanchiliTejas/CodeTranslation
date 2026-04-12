#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e4+5,mod=1e9+7;
int dp[105][N];
int num[N];
char s[N];
int dfs(int,int,bool);
int D;
int cal();
int main(){
    scanf("%s%d",s+1,&D);
    int ans=cal();
    ans--;
    ans=(ans%mod+mod)%mod;
    printf("%d",ans);
}
int cal(){
    int n=strlen(s+1);
    for(int i=1;i<=n;i++) num[i]=s[i]-'0';
    reverse(num+1,num+n+1);
    memset(dp,-1,sizeof(dp));
    return dfs(n,0,1);
}
int dfs(int pos,int sum,bool lim){
    if(pos==0) return sum==0;
    if(!lim&&dp[sum][pos]!=-1) return dp[sum][pos];
    int t=lim?num[pos]:9;
    int re=0;
    for(int i=0;i<=t;i++){
        re+=dfs(pos-1,(sum+i)%D,lim&&(i==t));
        re%=mod;
    }
    if(!lim) dp[sum][pos]=re;
    return re;
}

