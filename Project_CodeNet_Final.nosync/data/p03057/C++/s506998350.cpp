#include<cstdio>
#define N 200002
#define p 1000000007
inline int mod(int x){return x<p?x:x-p;}
int f[N],g[N],i,j,m,n,t,x;char s[N];
int main()
{
    scanf("%d%d%s",&n,&m,s+1),f[0]=g[0]=1;
    if(s[1]=='B')for(i=1;i<=m;i++)s[i]=s[i]=='B'?'R':'B';
    while(s[m]=='R')s[m--]=0;
    for(i=0;s[i+1]=='R';i++);
    for(t=i++|1;s[i];t=(i-j&1)&&i-j<t?i-j:t)
    {
        while(s[i]=='B')i++;
        for(j=i;s[i]=='R';i++);
    }
    if(m)for(i=1;i<=n;f[i]=mod(f[i-1]+g[i]),i++)if(~i&1)g[i]=i<t+2?f[i-1]:mod(p+f[i-1]-f[i-t-2]);else;
    else for(g[1]=1,i=2;i<=n;i++)g[i]=mod(g[i-2]+g[i-1]);
    if(m)for(i=n-2;0<=i&&n-i<=t+1;i-=2)x=(x+(long long)g[i]*(n-i))%p;
    else x=mod(g[n]+g[n-2]);
    return 0*printf("%d\n",x);
}