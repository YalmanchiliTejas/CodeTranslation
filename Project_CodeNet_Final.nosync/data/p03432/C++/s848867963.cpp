#include<cstdio>
#define M 16384
#define p 998244353
#define ll long long
inline int mod(int x){return x<p?x:x-p;}
inline int calc(int x,int y)
{
    int z=1;
    for(;y;x=(ll)x*x%p,y>>=1)if(y&1)z=(ll)x*z%p;
    return z;
}
int i,j,k,f[M],o,q,w[M|1],x,y,z;
inline void swap(int&u,int&v){z=u,u=v,v=z;}
inline void NTT(int*a,int s)
{
    for(i=0;i<q;i++)if(f[i]>i)swap(a[f[i]],a[i]);
    for(i=1;i<q;i<<=1)for(j=0,k=i,s>>=1;k<q;j+=i,k+=i)for(z=q&s;k&i;z+=s)x=a[j],y=(ll)a[k]*w[z]%p,a[j++]=mod(x+y),a[k++]=mod(p+x-y);
    if(s<0)for(i=0;i<q;i++)a[i]=(ll)a[i]*o%p;
}
int a[M],b[M],c[M],d[M],e[M],m,n;
int main()
{
    for(scanf("%d%d",&n,&m),q=1;q<=n<<1;q<<=1)o++;
    for(z=calc(3,p>>o--),i=*w=w[q]=1;i<q;i++)f[i]=f[i>>1]>>1|(i&1)<<o,w[i]=(ll)w[i-1]*z%p;
    for(*a=a[1]=*b=b[1]=1,i=2;i<=n+2;i++)a[i]=(ll)a[i-1]*i%p,b[i]=(ll)(p-p/i)*b[p%i]%p;
    for(i=2,o=calc(q,p-2);i<=n+2;i++)b[i]=(ll)b[i-1]*b[i]%p;
    for(i=0;i<=n;i++)c[i]=b[i+2];
    for(NTT(c,q),*d=1;m;m--)
    {
        for(i=0;i<=n;i++)e[i]=(ll)d[i]*b[i]%p,d[i]=(ll)d[i]*(p-i)%p;
        for(NTT(e,q),i=0;i<q;i++)e[i]=(ll)c[i]*e[i]%p;
        for(NTT(e,-q),i=0;i<=n;i++)d[i]=(d[i]+(ll)e[i]*a[i+2])%p,e[n+i+1]=0;
    }
    for(i=x=0;i<=n;i++)x=(x+(ll)b[i]*b[n-i]%p*a[n]%p*d[i])%p;
    return 0&printf("%d\n",x);
}