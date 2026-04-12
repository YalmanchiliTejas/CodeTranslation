#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=3010;
int p,n,S[N][N],C[N][N],H[N][N];
int qpow(int a,int b,int p)
{int ret=1;while(b){if(b&1)ret=1ll*ret*a%p;a=1ll*a*a%p;b>>=1;}return ret;}
int main()
{
    scanf("%d%d",&n,&p);
    C[0][0]=S[0][0]=1;
    for(int i=1;i<=n+1;i++)
    {
        C[i][0]=1,S[i][0]=0;
        for(int j=1;j<=n+1;j++)
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%p,S[i][j]=(S[i-1][j-1]+1ll*S[i-1][j]*j)%p;
    }
    int ans=0;
    for(int i=0;i<=n;i++)
    {
        int sum=0;
        for(int j=0;j<=i;j++)sum=(sum+1ll*S[i+1][j+1]*qpow(2,(n-i)*j,p))%p;
        ans=(ans+1ll*sum*C[n][i]%p*qpow(2,qpow(2,n-i,p-1),p)%p*(i&1?p-1:1))%p;
    }
    printf("%d\n",ans);
}
