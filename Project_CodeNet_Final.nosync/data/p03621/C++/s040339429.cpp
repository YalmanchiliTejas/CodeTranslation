#include<bits/stdc++.h>
#define LL long long
#define vc vector<int>
#define db long double

using namespace std;
const int N=10000+10,M=(1<<16)+10,mod=998244353;
int rd()
{
    int x=0,w=1;char ch=0;
    while(ch<'0'||ch>'9'){if(ch=='-') w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+(ch^48);ch=getchar();}
    return x*w;
}
void ad(int &x,int y){x+=y,x-=x>=mod?mod:0;}
int fpow(int a,int b){int an=1;while(b){if(b&1) an=1ll*an*a%mod;a=1ll*a*a%mod,b>>=1;}return an;}
int ginv(int a){return fpow(a,mod-2);}
int rdr[M],W[20],iW[20],pu[M],pv[M];
void ntt(int *a,int n,int op)
{
    int l=0,y;
    while(1<<l<n) ++l;
    for(int i=0;i<n;++i)
    {
	rdr[i]=(rdr[i>>1]>>1)|((i&1)<<(l-1));
	if(i<rdr[i]) swap(a[i],a[rdr[i]]);
    }
    for(int i=1,p=0;i<n;i<<=1,++p)
    {
	int ww=op?W[p]:iW[p];
	for(int j=0;j<n;j+=i<<1)
	    for(int k=0,w=1;k<i;++k,w=1ll*w*ww%mod)
	    {
		y=1ll*a[j+k+i]*w%mod;
		a[j+k+i]=(a[j+k]-y+mod)%mod;
		a[j+k]=(a[j+k]+y)%mod;
	    }
    }
    if(!op) for(int i=0,w=ginv(n);i<n;++i) a[i]=1ll*a[i]*w%mod;
}
void polymul(int *a,int nn,int *b,int mm,int *c)
{
    int len=1;
    while(len<nn+mm) len<<=1;
    if(!nn||!mm) return;
    memcpy(pu,a,sizeof(int)*nn),memcpy(pv,b,sizeof(int)*mm);
    memset(c,0,sizeof(int)*(nn+mm-1));
    if(1ll*nn*mm<=1ll*len*40)
    {
	for(int i=0;i<nn;++i)
	    for(int j=0;j<mm;++j)
		ad(c[i+j],1ll*pu[i]*pv[j]%mod);
    }
    else
    {
	ntt(pu,len,1),ntt(pv,len,1);
	for(int i=0;i<len;++i) pu[i]=1ll*pu[i]*pv[i]%mod;
	ntt(pu,len,0);
	memcpy(c,pu,sizeof(int)*(nn+mm-1));
    }
    memset(pu,0,sizeof(int)*len),memset(pv,0,sizeof(int)*len);
}
char cc[N],ss[N];
int fac[M],iac[M],aa[M],bb[M],n,m,a1,b1;

int main()
{       
////////
    for(int i=1,p=0;p<=19;i<<=1,++p)
	W[p]=fpow(3,(mod-1)/(i<<1)),iW[p]=ginv(W[p]);
    fac[0]=1;
    for(int i=1;i<=M-5;++i) fac[i]=1ll*fac[i-1]*i%mod;
    iac[M-5]=ginv(fac[M-5]);
    for(int i=M-5;i;--i) iac[i-1]=1ll*iac[i]*i%mod;
    scanf("%s%s",cc+1,ss+1);
    m=strlen(cc+1);
    for(int i=1;i<=m;++i)
    {
	if((cc[i]=='1')^(ss[i]=='1')) ++b1;
	else if(cc[i]=='1'&&ss[i]=='1') ++a1;
    }
    b1/=2,n=a1+b1;
    for(int i=1;i<=n;++i) bb[i]=iac[i];
    aa[0]=1;
    int rbb=b1;
    while(rbb)
    {
	if(rbb&1)
	{
	    polymul(aa,n+1,bb,n+1,aa);
	    for(int i=n+1;i<=n+n+2;++i) aa[i]=0;
	}
	polymul(bb,n+1,bb,n+1,bb);
	for(int i=n+1;i<=n+n+2;++i) bb[i]=0;
	rbb>>=1;
    }
    int ans=0;
    for(int i=0;i<=n;++i) ad(ans,aa[i]);
    ans=1ll*ans*fac[n]%mod*fac[a1]%mod*fac[b1]%mod;
    printf("%d\n",ans);
    return 0;
}
