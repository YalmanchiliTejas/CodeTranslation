#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
typedef long long ll;
const int Mod = 1000000007;
const int maxn = 1e4+10;
ll dp[maxn][105];
int d;
char str[maxn];
int a[maxn];
ll dfs(int pos,int left,bool limit)
{
    if(pos==-1) return (left==0);
    if(!limit && dp[pos][left]!=-1) return dp[pos][left];
    int up=limit ? a[pos] : 9;
    ll tmp=0;
    for(int i=0;i<=up;i++)
    {
        tmp=(tmp+dfs(pos-1,(left-i%d+d)%d,limit && i==a[pos]))%Mod;
    }
    if(!limit) dp[pos][left]=tmp;
    return tmp;
}
ll solve()
{
    int len=strlen(str);
    int pos=0;
    for(int i=len-1;i>=0;i--) a[pos++]=str[i]-'0';
    return dfs(pos-1,0,true);
}
int main()
{
    scanf("%s%d",str,&d);
    memset(dp,-1,sizeof(dp));
    printf("%lld\n",(solve()-1+Mod)%Mod);
    return 0;
}
