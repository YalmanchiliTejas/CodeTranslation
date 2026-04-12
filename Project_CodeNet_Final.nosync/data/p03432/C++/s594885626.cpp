#include<bits/stdc++.h>
using namespace std;
#define mo 998244353
#define M 8005
#define N 205
int ksm(int a,int k) {
    int s=1;
    while(k)
	{
	    if(k&1) s=1ll*s*a%mo;
	    a=1ll*a*a%mo;
	    k>>=1;
	}
    return s;
}
int n,m,ans;
int f[N][M],jc[M],nc[M];
int C(int n,int m) {
    if(n<0||m<0||n<m) return 0;
    return 1ll*jc[n]*nc[m]%mo*nc[n-m]%mo;
}
int lim,r[M*4],l,A[M*4],B[M*4];
void NTT(int *x,int k) {
    for(int i=0;i<lim;i++) if(i<r[i]) swap(x[i],x[r[i]]);
    for(int i=1;i<lim;i<<=1)
	{
	    int y=ksm(3,(mo-1)/(2*i));
	    if(k==-1) y=ksm(y,mo-2);
	    for(int j=0;j<lim;j+=i<<1)
		{
		    int z=1;
		    for(int l=0;l<i;l++,z=1ll*z*y%mo)
			{
			    int d1=x[j+l],d2=1ll*z*x[i+j+l]%mo;
			    x[j+l]=(d1+d2)%mo;
			    x[i+j+l]=(d1-d2+mo)%mo;
			}
		}
	}
    if(k==-1)
	{
	    int inv=ksm(lim,mo-2);
	    for(int i=0;i<lim;i++) x[i]=1ll*x[i]*inv%mo;
	}
}
void work() {
    f[0][0]=1;
    for(int t=1;t<=m;t++)
	{
	    lim=1,l=0;
	    while(lim<=n+n) lim<<=1,l++;
	    for(int i=1;i<=lim;i++) r[i]=(r[i>>1]>>1)|((i&1)<<(l-1));
	    for(int i=0;i<=n;i++) A[i]=1ll*f[t-1][i]*nc[i]%mo;
	    for(int i=1;i<=n;i++) B[i]=nc[i+2];
	    NTT(A,1),NTT(B,1);
	    for(int i=0;i<lim;i++) A[i]=1ll*A[i]*B[i]%mo;
	    NTT(A,-1);
	    for(int i=1;i<=n;i++) f[t][i]=(1ll*A[i]*jc[i+2]%mo+1ll*(C(i+1,2)+1)*f[t-1][i]%mo)%mo;
	    f[t][0]=1;
	    for(int i=0;i<lim;i++) A[i]=B[i]=0;
	}
    for(int i=0;i<=n;i++) ans=(ans+1ll*f[m][i]*C(n,i)%mo)%mo;
    cout<<ans<<'\n';
}
int main()
{
    jc[0]=1;
    for(int i=1;i<M;i++) jc[i]=1ll*jc[i-1]*i%mo;
    nc[M-1]=ksm(jc[M-1],mo-2);
    for(int i=M-2;i>=0;i--) nc[i]=1ll*nc[i+1]*(i+1)%mo;
    cin>>n>>m;
    work();
    return 0;
}