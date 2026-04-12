#include<bits/stdc++.h>
using namespace std;
#define ll long long
int D;
int len,a[10009];
ll dp[10009][130];
const ll mod=1e9+7;
ll dfs(int pos,int sum,int limit)
{
    if(pos>len) return sum?0:1;
    if(dp[pos][sum]!=-1&&!limit)return dp[pos][sum];
    ll ret=0;
    int res=limit?a[pos]:9;
    for(int i=0;i<=res;i++)
    {
        ret=(ret+dfs(pos+1,(sum+i)%D,limit&&(i==res)))%mod;
    }
    return (!limit)?dp[pos][sum]=ret:ret;
}
ll part(char s[])
{
    len=0;int lenn=strlen(s+1);
    for(int i=1;i<=lenn;i++)a[++len]=s[i]-'0';
    memset(dp,-1,sizeof dp);
    return dfs(1,0,1);
}
char str[10009];
int main()
{
    scanf("%s%d",str+1,&D);
    printf("%lld\n",(part(str)-1+mod)%mod);
    return 0;
}