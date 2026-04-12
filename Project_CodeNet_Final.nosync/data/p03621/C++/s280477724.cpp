#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
const int N=10005,mod=998244353;
char sa[N],sb[N];
typedef long long LL;
int n,m,len,bin[N<<2];
LL a[N<<2],b[N<<2],c[N<<2],G[N<<2],wn[15][50005],flv[N<<2],ans;
LL inva[N<<2],inv[N<<2],A[N<<2],_a[N<<2],f[N<<2],g[N<<2],h[N<<2];

LL getmi(LL a,LL x)
{
    LL rt=1;
    while(x)
    {
        if(x&1) rt=rt*a%mod;
        a=a*a%mod,x>>=1;
    }
    return rt;
}
 
void FFT(LL a[],int len,int tp)
{
    rep(i,0,len-1) bin[i]=bin[i>>1]>>1|((i&1)*(len>>1));
    rep(i,0,len-1) if(i<bin[i]) swap(a[i],a[bin[i]]);
    for(int i=1,cnt=0; i<len; ++cnt,i<<=1)
    {
        for(int j=0; j<len; j+=i<<1)
        {
            LL w=i,x,y;
            rep(k,0,i-1)
            {
                x=a[j+k],y=a[i+j+k]*wn[cnt][w],w+=tp;
                a[j+k]=(x+y)%mod,a[i+j+k]=(x-y)%mod;
            }
        }
    }
    if(tp==-1)
    {
        LL x=getmi(len,mod-2);
        rep(i,0,len-1) a[i]=a[i]*x%mod;
    }
}
 
void get_inv(LL a[],LL b[],int n)
{
    if(n==1)
    {
        b[0]=getmi(a[0],mod-2);
        return;
    }
    get_inv(a,b,n>>1);
    rep(i,0,n-1) G[i]=a[i];
    rep(i,n,2*n-1) G[i]=0;
    FFT(G,n<<1,1),FFT(b,n<<1,1);
    rep(i,0,2*n-1) b[i]=b[i]*(2-b[i]*G[i]%mod)%mod;
    FFT(b,n<<1,-1);
    rep(i,n,2*n-1) b[i]=0;
} 
 
void get_ln(LL a[],LL b[],int n)
{
    rep(i,0,2*n-1) inva[i]=_a[i]=0;
    get_inv(a,inva,n);
    rep(i,0,n-2) _a[i]=a[i+1]*(i+1)%mod;
    _a[n-1]=0,FFT(inva,n<<1,1),FFT(_a,n<<1,1);
    rep(i,0,2*n-1) b[i]=inva[i]*_a[i]%mod;
    FFT(b,n<<1,-1);
    rep(i,n,2*n-1) b[i]=0;
    repd(i,n-1,1) b[i]=b[i-1]*inv[i]%mod;
    b[0]=0;
}
 
void get_exp(LL a[],LL b[],int n)
{
    if(n==1)
    {
        b[0]=1;
        return;
    }
    get_exp(a,b,n>>1);
    rep(i,0,2*n-1) A[i]=0;
    get_ln(b,A,n);
    rep(i,0,n-1) A[i]=(a[i]-A[i])%mod;
    A[0]=(A[0]+1)%mod;
    FFT(b,n<<1,1),FFT(A,n<<1,1);
    rep(i,0,2*n-1) b[i]=b[i]*A[i]%mod;
    FFT(b,n<<1,-1);
    rep(i,n,2*n-1) b[i]=0;
}
 
void prepare()
{
	for(len=1; len<=n; len<<=1);
	flv[0]=1;
	int lim=max(len,n+m+1);
	rep(i,1,lim) flv[i]=flv[i-1]*i%mod;
	inv[lim]=getmi(flv[lim],mod-2);
	repd(i,lim,1) inv[i-1]=inv[i]*i%mod;   
	rep(i,0,14)
    {
        wn[i][1<<i]=1;
        LL w=getmi(3,(mod-1)/(1<<i+1));
        rep(j,1,(1<<i)-1) wn[i][(1<<i)+j]=wn[i][(1<<i)+j-1]*w%mod;
        w=getmi(w,mod-2);
        rep(j,1,(1<<i)-1) wn[i][(1<<i)-j]=wn[i][(1<<i)-j+1]*w%mod;
    }
}

int main()
{
	scanf("%s",sa+1);
	scanf("%s",sb+1);
	len=strlen(sa+1);
	rep(i,1,len) if(sa[i]=='1' && sb[i]=='1') ++n; else if(sa[i]=='1') ++m;
	prepare();
	rep(i,0,n) f[i]=inv[i+1];
	rep(i,0,len-1) inv[i]=getmi(i,mod-2);
	get_ln(f,g,len);
	rep(i,0,len-1) g[i]=g[i]*m%mod;
	get_exp(g,h,len);
	rep(i,0,n)
		ans=(ans+h[i])%mod;
	ans=ans*flv[n+m]%mod*flv[n]%mod*flv[m]%mod;
	printf("%lld\n",(ans+mod)%mod);
	return 0;
}	 