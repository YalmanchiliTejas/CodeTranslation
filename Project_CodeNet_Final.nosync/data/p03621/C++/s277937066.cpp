#include <cstdio>
#include <cstring>
#define repu(i,x,y) for (int i=x; i<=y; ++i)
using namespace std;

typedef long long LL;
const int p=998244353;
int n,m,cnt,f[10010][10010],fac[10010],inv[10010],ans;
char a[10100],b[10100];

int c(int n,int m)
{
    return LL(fac[n])*inv[m]%p*inv[n-m]%p;
}

int main()
{
    scanf("%s%s",a+1,b+1),n=strlen(a+1);
    repu(i,1,n)
        if (a[i]=='1')
            cnt+=b[i]=='0',++m;
    fac[0]=fac[1]=inv[0]=inv[1]=1;
    repu(i,2,m)
        inv[i]=LL(p-p/i)*inv[p%i]%p;
    repu(i,2,m)
        fac[i]=LL(fac[i-1])*i%p,inv[i]=LL(inv[i-1])*inv[i]%p;
    f[0][cnt]=1;
    repu(i,0,m)
    {
        repu(j,1,m-i)
            if (f[i][j])
            {
                f[i+1][j]=(f[i+1][j]+LL(m-i-j)*j*f[i][j])%p;
                f[i+1][j-1]=(f[i+1][j-1]+LL(j)*j*f[i][j])%p;
            }
        ans=(ans+LL(f[i][0])*c(m,i)%p*fac[m-i]%p*fac[m-i])%p;
    }
    printf("%d\n",ans);
    return 0;
}