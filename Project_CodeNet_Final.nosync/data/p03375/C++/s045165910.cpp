#include<bits/stdc++.h>
using namespace std;
#define reg register
#define ll long long
#define maxn 3005
inline ll read()
{
	ll x=0,w=0;char ch=getchar();
	while(!isdigit(ch))w|=ch=='-',ch=getchar();
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return w?-x:x;
}
int n,mo;
inline int ksm(int x,int y,int mo=::mo)
{
    int a=1;
    while(y)
    {
        if(y&1)a=1ll*a*x%mo;
        x=1ll*x*x%mo;y>>=1;
    }return a;
}
inline void Add(int &x,int y){x+=y;x-=(x>=mo?mo:0);}
inline int add(int x,int y){x+=y;return x>=mo?x-mo:x;}
int C[maxn][maxn],S[maxn][maxn];
int main()
{
    n=read(),mo=read();
    reg int i,j;
    for(i=0;i<=n;++i)
        for(C[i][0]=S[i][0]=1,j=1;j<=i;++j)
        {
            C[i][j]=add(C[i-1][j],C[i-1][j-1]);
            S[i][j]=add(S[i-1][j-1],1ll*(j+1)*S[i-1][j]%mo);
        }
    reg int res,ans=0;
    for(i=0;i<=n;++i)
    {
        res=0;
        for(j=0;j<=i;++j)Add(res,1ll*S[i][j]*ksm(ksm(2,n-i),j)%mo);
        res=1ll*res*ksm(2,ksm(2,n-i,mo-1))%mo*C[n][i]%mo;
        if(i&1)Add(ans,mo-res);else Add(ans,res);
    }
    printf("%d\n",ans);
	return 0;
}