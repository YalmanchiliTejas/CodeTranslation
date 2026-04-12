#include<bits/stdc++.h>
using namespace std;
const int N=8005,M=205;
const int mo=998244353;
const int P=16500;
int n,m,f[M][N];
int fac[N],inv[N];
int A[P],B[P],R[P];
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
void FFT(int *a,int n,int f){
	for (int i=1;i<n;i++)
		if (i<R[i]) swap(a[i],a[R[i]]);
	for (int d=1;d<n;d<<=1){
		int wn=power(3,(mo-1)/(d<<1));
		if (f==-1) wn=power(wn,mo-2);
		for (int i=0;i<n;i+=(d<<1))
			for (int j=i,w=1;j<i+d;j++){
				int y=1ll*a[j+d]*w%mo;
				a[j+d]=(a[j]+mo-y)%mo;
				a[j]=(a[j]+y)%mo;
				w=1ll*w*wn%mo;
			}
	}
	if (f==-1){
		int v=power(n,mo-2);
		for (int i=0;i<n;i++)
			a[i]=1ll*a[i]*v%mo;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	fac[0]=inv[0]=inv[1]=1;
	for (int i=2;i<=n+2;i++)
		inv[i]=1ll*inv[mo%i]*(mo-mo/i)%mo;
	for (int i=1;i<=n+2;i++){
		fac[i]=1ll*fac[i-1]*i%mo;
		inv[i]=1ll*inv[i-1]*inv[i]%mo;
	}
	int c=1,L=0;
	for (;c<=2*n;c<<=1,L++);
	for (int i=1;i<=c;i++)
		R[i]=(R[i>>1]>>1)|((i&1)<<(L-1));
	for (int i=0;i<=n;i++) f[m][i]=1ll*fac[n]*inv[i]%mo*inv[n-i]%mo;
	for (int i=0;i<=n;i++) B[n-i]=inv[i+2];
	FFT(B,c,1);
	for (int i=m;i;i--){
		memset(A,0,sizeof(A));
		for (int j=0;j<=n;j++)
			A[j]=1ll*f[i][j]*fac[j+2]%mo;
		FFT(A,c,1);
		for (int j=0;j<c;j++)
			A[j]=1ll*A[j]*B[j]%mo;
		FFT(A,c,-1);
		for (int j=0;j<=n;j++)
			f[i-1][j]=1ll*A[n+j]*inv[j]%mo;
		for (int j=0;j<=n;j++)
			f[i-1][j]=(f[i-1][j]+mo-1ll*f[i][j]*j%mo)%mo;
	}
	printf("%d\n",f[0][0]);
}