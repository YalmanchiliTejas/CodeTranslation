#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define ll long long
#define M 1000000007
#define N 100010
#define D 110
using namespace std;

ll n,d,l,dg[N],dp[N][D];
string k;

ll solve(int pos,int cnt,bool lmt)
{
    if(!lmt && dp[pos][cnt]!=-1) return dp[pos][cnt];
    if(pos==l) return dp[pos][cnt]=(cnt==0);
    ll up=lmt?dg[pos]:9;
    ll ret=0;
    for(int i=0;i<=up;i++)
    {
        ret+=solve(pos+1,(cnt+i)%d,(i==dg[pos])&&lmt);
        ret%=M;
    }
    if(!lmt) dp[pos][cnt]=ret;
    return ret;
}

int main()
{
    cin>>k>>d; l=k.length(); 
    FOR(i,0,k.length()) dg[i]=k[i]-'0';
    memset(dp,-1,sizeof(dp));
    cout<<(solve(0,0,1)-1+M)%M<<'\n';

    return 0;
}