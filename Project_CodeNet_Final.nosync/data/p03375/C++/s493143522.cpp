#include <bits/stdc++.h>
using namespace std;

const int N=3005;
int n,P,C[N][N],S[N][N],ans;

int qpow(int b_,int p_,int mod=P)
{
    int r_=1;
    for(;p_;p_>>=1,b_=1LL*b_*b_%mod)
        if(p_&1) r_=1LL*b_*r_%mod;
    return r_;
}

int main()
{
    scanf("%d%d",&n,&P);
    C[0][0]=S[0][0]=1;
    for(int i=1;i<=n+1;++i)
    {
        C[i][0]=1;
        for(int j=1;j<=i;++j)
        {
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%P,
            S[i][j]=(1LL*S[i-1][j]*j%P+S[i-1][j-1])%P;
        }
    }
    for(int i=0;i<=n;++i)
    {
        int s1=1LL*C[n][i]*qpow(2,qpow(2,n-i,P-1))%P;
        int s2=0;
        for(int j=0;j<=i;++j)
            s2=(s2+1LL*S[i+1][j+1]*qpow(qpow(2,n-i),j)%P)%P;
        ans=(ans+(i&1?-1LL:1LL)*s1*s2%P)%P;
        ans=(ans+P)%P;
    }
    printf("%d",ans);
    return 0;
}