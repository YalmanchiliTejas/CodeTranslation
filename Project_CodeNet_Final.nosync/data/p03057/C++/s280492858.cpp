#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5,mod=1e9+7;
int Mn(int a,int b){return a<b?a:b;}
int upt(int x){while(x>=mod)x-=mod;while(x<0)x+=mod;return x;}
int n,m,lm,dp[N],sm[N],ans,g[N];
char s[N];
void solve()
{
  g[0]=sm[0]=1;
  for(int i=1;i<=n;i++)
  {
    if(i>=2)g[i]=sm[i-2];
    sm[i]=upt(sm[i-1]+g[i]);
  }
  int ans=1;//ans=1 for all one color
  for(int i=2;i<=n;i++)
    ans=(ans+(ll)i*g[n-i])%mod;
  printf("%d\n",ans);
}
int main()
{
  scanf("%d%d",&n,&m);
  scanf("%s",s+1); bool fg=0;
  for(int i=1;i<=m;i++)if(s[i]!=s[1]){fg=1;break;}
  if(!fg){solve();return 0;}
  if(n&1){puts("0");return 0;}
  lm=n+1;
  for(int i=1;i<=m;i++)if(s[i]==s[1])//== not !=
  {
    int j=i;
    while(j+1<=m&&s[j+1]==s[j])j++;
    swap(i,j); j=i-j+1;
    if(i-j==0) lm=Mn(lm,j+((j&1)==0));
    else if((j&1)&&i!=m)lm=Mn(lm,j);//i!=m not lst
    //else if((j&1)&&i!=lst)lm=Mn(lm,j);
  }
  n>>=1; lm=(lm+1)>>1; dp[0]=sm[0]=1;
  for(int i=1;i<=n;i++)
  {
    dp[i]=sm[i-1]; if(i>lm)dp[i]=upt(dp[i]-sm[i-lm-1]);
    sm[i]=upt(sm[i-1]+dp[i]);
  }
  int ans=0;
  for(int i=1;i<=lm;i++)//lm not n
    ans=(ans+(ll)i*2*dp[n-i])%mod;
  printf("%d\n",ans);
  return 0;
}
