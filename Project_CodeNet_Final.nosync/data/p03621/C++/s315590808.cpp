#include<bits/stdc++.h>
#define N 32769
#define LL long long
using namespace std;
const int mo=998244353;
int n,m,k,g[2][N],fc[N],xf[N],f[N],h[N],z[N],v[N],e,ep,ie,ans,R[N];
char A[N],B[N];
LL fpm(LL x,LL y){ LL s=1; while(y){ if(y&1) s=(s*x)%mo; y>>=1,x=(x*x)%mo;} return s;}
void FFT(int *x,int o)
{
	int i,j,k,w,wn,p,q;
	for(i=0;i<e;i++) if(R[i]>i) swap(x[i],x[R[i]]);
	for(i=1;i<=e;i<<=1)
		for(j=0,wn=g[o][i];j<e;j+=i)
			for(k=0,w=1;k<i/2;k++){
				p=x[j+k],q=1LL*x[j+k+i/2]*w%mo;
				x[j+k]=p+q,x[j+k+i/2]=p-q;
				if(x[j+k]>=mo) x[j+k]-=mo;
				if(x[j+k+i/2]<0) x[j+k+i/2]+=mo;
				w=1LL*w*wn%mo;
			  }
}
void mult(int *x,int *y)
{
	int i;
	for(i=0;i<e;i++) v[i]=y[i],z[i]=x[i];
	FFT(z,0),FFT(v,0);
	for(i=0;i<e;i++) z[i]=1LL*z[i]*v[i]%mo;
	FFT(z,1);
	for(i=0;i<=m;i++)	x[i]=1LL*z[i]*ie%mo;
}
int main()
{
	int i;
	scanf("%s",A+1);
	scanf("%s",B+1);
	n = strlen(A+1);
	fc[0]=xf[0]=1;
	for(i=1;i<N;i++){
		fc[i]=(1LL*fc[i-1]*i)%mo;
		xf[i]=fpm(fc[i],mo-2);
	  }
	for(i=1;i<=n;i++){
		if(A[i]=='1') k++;
		if(A[i]=='1'&&B[i]=='1') m++;
	  }
	for(e=1,ep=0;e<=2*m;e<<=1,ep++);
	ie=fpm(e,mo-2);
	for(i=1;i<e;i++) R[i]=(R[i>>1]>>1)|((i&1)<<(ep-1));
	for(i=0;i<=ep;i++){
		g[0][1<<i]=fpm(3,((mo-1)>>i));
		g[1][1<<i]=fpm(g[0][1<<i],mo-2);
	  }
	k-=m,f[0]=1;
	for(i=0;i<=m;i++) h[i]=xf[i+1];
	for(i=k;i;){
		if(i&1) mult(f,h);
		i>>=1 , mult(h,h);
	  }
	for(i=0;i<=m;i++)
		ans=(ans+1LL*fc[m]*xf[m-i]%mo*f[i]%mo*fc[m-i])%mo;
	ans=1LL*ans*fc[k+m]%mo*fc[k]%mo;
	cout<<ans;
	return 0;
}
