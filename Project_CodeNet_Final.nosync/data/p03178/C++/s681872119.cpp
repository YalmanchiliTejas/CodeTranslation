#include<bits/stdc++.h>
using namespace std;

const int N = 10050;
const int mod = 1000000007;
typedef long long  ll;

char str[N];
int d,len;
int dp[N][105][2][2][2];

int rec(int p,int md,int srt,int sm,int f)
{
    if(p==len) return (md==0 && f==1);
    int &ret=dp[p][md][srt][sm][f];
    if(ret!=-1) return ret;
    ret=0;
    int lo=0,hi=str[p]-'0';
    if(srt) lo=1;
    if(sm) hi=9;
    int v=str[p]-'0';
    if(srt) ret+=rec(p+1,md,srt,1,f);
    ret%=mod;
    for(int i=lo; i<=hi; i++)
    {
        ret+=rec(p+1,(md+i)%d,0,sm|i<v,1);
        ret%=mod;
    }
    return ret;
}

int main()
{
   scanf("%s %d",str,&d);
   len=strlen(str);
    memset(dp,-1,sizeof dp);
    printf("%d\n",rec(0,0,1,0,0));



}
