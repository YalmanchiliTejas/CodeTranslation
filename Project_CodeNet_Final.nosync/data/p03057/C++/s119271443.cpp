#include<bits/stdc++.h>
using namespace std;
#define M 200005
#define mo 1000000007
#define ll long long
int n,m,L;
char s[M];
ll ans,f[M],g[M];
ll dp[M][2];
void work() {
    while(s[m]==s[1]) m--;
    L=1e9;
    char ch=s[1];
    for(int i=2,l=1,tp=1;i<=m;i++)
	{
	    if(s[i]==ch) l++;
	    else
		{
		    if(l&1) L=min(L,l);
		    else if(tp) L=min(L,l+1);
		    l=tp=0;
		}
	}
    if(L==1e9)
	{
	    dp[1][0]=1;
	    for(int i=2;i<=n;i++)
		{
		    dp[i][0]=(dp[i-1][0]+dp[i-1][1])%mo;
		    dp[i][1]=dp[i-1][0];
		}
	    ans=(dp[n][1]+dp[n][0])%mo;
	    memset(dp,0,sizeof(dp));
	    dp[1][1]=1;
	    for(int i=2;i<=n;i++)
		{
		    dp[i][0]=(dp[i-1][0]+dp[i-1][1])%mo;
		    dp[i][1]=dp[i-1][0];
		}
	    ans=(ans+dp[n][0])%mo;
	    cout<<ans<<'\n';
	}
    else
	{
	    f[1]=g[1]=1;
	    for(int i=2;i<=n;i++)
		{
		    if(i<=L&&(i&1)) f[i]=1;
		    //for(int j=i-2;j>=max(i-L-1,0);j-=2) f[i]=(f[i]+f[j])%mo;
		    f[i]=(f[i]+g[i-2]-(i-L-3>=0?g[i-L-3]:0)+mo)%mo;
		    g[i]=(g[i-2]+f[i])%mo;
		}
	    for(int i=3;i<=L+2&&i<=n;i+=2) ans=(ans+f[n-i]*(i-1)%mo)%mo;
	    if(n-1<=L&&((n-1)&1)) ans=(ans+n)%mo;
	    cout<<ans<<'\n';
	}
}
int main()
{
    cin>>n>>m;
    scanf("%s",s+1);
    work();
    return 0;
}