#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define mp make_pair
typedef pair<int,int> pii;
char str[110];
int a[110];
int k;
ll dp[110][4];int len;
ll dfs(int pos,int limit,int lead,int k)
{
    if(pos>len&&!k)return 1;
    else if(pos>len)return 0;
    if(!limit&&!lead&&dp[pos][k]!=-1&&k>=0)return dp[pos][k];
    int cnt=limit?a[pos]:9;
    ll ret=0;
    for(int i=0;i<=cnt;i++)
    {
        if(!lead&&i&&k<=0)continue;
        if(lead&&!i)ret+=dfs(pos+1,limit&&(i==cnt),1,k);
        else if(lead&&i&&k>0)ret+=dfs(pos+1,limit&&(i==cnt),0,k-1);
        else if(!lead&&!i)ret+=dfs(pos+1,limit&&(i==cnt),0,k);
        else if(!lead&&i&&k>0)ret+=dfs(pos+1,limit&&(i==cnt),0,k-1);
    }
    return (!limit&&!lead&&k>=0)?dp[pos][k]=ret:ret;
}
ll solve(int k)
{
    memset(dp,-1, sizeof(dp));
    for(int i=1;i<=len;i++){
        a[i]=str[i]-'0';
    }
    return dfs(1,1,1,k);
}
int main()
{
    scanf("%s%d",str+1,&k);
    len=strlen(str+1);
    printf("%lld\n",solve(k));
}