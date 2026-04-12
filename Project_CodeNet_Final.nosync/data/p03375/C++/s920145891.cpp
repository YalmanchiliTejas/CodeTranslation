#include<bits/stdc++.h>
#define maxn 3001

using namespace std;
typedef long long ll;
ll dp[maxn],n,M,P,p2[maxn*maxn],C[maxn][maxn],ans,f,fc[maxn],fi[maxn];

ll pow_(ll x,ll y,ll z)
{
    ll rt=1;
    while (y){
        if (y&1) rt=rt*x%z;
        y/=2;
        x=x*x%z;
    }
    return rt;
}

int main()
{
    cin >> n >> M;
    p2[0]=1; for (int i=1;i<=n*n;i++) p2[i]=p2[i-1]*2%M;
    fc[0]=fi[0]=1; for (int i=1;i<=n;i++) fc[i]=fc[i-1]*i%M,fi[i]=pow_(fc[i],M-2,M);
    C[0][0]=1;
    for (int i=1;i<=n;i++)
    {
        C[i][0]=0;C[i][i]=1;
        for (int j=1;j<i;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j]*j)%M;
    }
    dp[0]=1; f=1;
    for (int i=1;i<=n;i++)
        for (int j=0;j<=i;j++)
            (dp[i]+=(C[i][j]+C[i][j+1]*(j+1))%M*p2[(n-i)*j])%=M;
    for (int i=0;i<=n;i++)
        (ans+=dp[i]*pow_(2ll,pow_(2ll,n-i,M-1),M)%M*fc[n]%M*fi[i]%M*fi[n-i]%M*f)%=M,f=-f;
    cout << (ans+M)%M << endl;
}
