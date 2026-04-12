#include<cstdio>
#include<cstring>
const int N=10007,P=998244353;
char s[N],t[N];int f[N][N],fac[N],ifac[N];
int inc(int a,int b){return a+=b-P,a+(a>>31&P);}
int mul(int a,int b){return 1ll*a*b%P;}
int pow(int a,int k){int r=1;for(;k;k>>=1,a=mul(a,a))if(k&1)r=mul(a,r);return r;}
int C(int n,int m){return mul(mul(fac[n],ifac[m]),ifac[n-m]);}
int main()
{
    scanf("%s%s",s+1,t+1),fac[0]=1;
    int n=strlen(s+1),p=0,q=0,ans=0;
    for(int i=1;i<=n;++i) p+=s[i]=='1'&&t[i]=='1',q+=s[i]=='1'&&t[i]=='0';
    for(int i=1;i<=n;++i) fac[i]=mul(fac[i-1],i);
    ifac[n]=pow(fac[n],P-2);
    for(int i=n;i;--i) ifac[i-1]=mul(ifac[i],i);
    for(int i=0;i<=q;++i) f[0][i]=mul(fac[i],fac[i]);
    for(int i=1;i<=p;++i) for(int j=1;j<=q;++j) f[i][j]=inc(mul(mul(j,j),f[i][j-1]),mul(mul(i,j),f[i-1][j]));
    for(int i=0;i<=p;++i) ans=inc(ans,mul(mul(mul(mul(f[p-i][q],fac[i]),fac[i]),C(p,i)),C(p+q,i)));
    printf("%d",ans);
}
