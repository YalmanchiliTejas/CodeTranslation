#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=40400,P=998244353;
int i,j,k,n,m,ans;
int A[N],B[N],a[N],b[N],Jc[N],Jc_[N],rev[N],W[2][N];
char s1[N],s2[N];
int ksm(int x,int y) {
	int z=1;
	for (;y;y>>=1,x=(ll) x*x%P) if (y&1) z=(ll) z*x%P;
	return z;
}
void pre(int n) {
	int i;
	Jc[0]=Jc_[0]=1;
	for (i=1;i<=n;i++) Jc[i]=(ll) Jc[i-1]*i%P;
	Jc_[n]=ksm(Jc[n],P-2);
	for (i=n-1;i;i--) Jc_[i]=(ll) Jc_[i+1]*(i+1)%P;
}
void Pre(int n,int m) {
	int i,j,k;
	for (i=0;i<n;i++) {
		k=i;
		for (j=0;j<m;j++) (rev[i]<<=1)|=k&1,k>>=1;
	}
	int w=ksm(3,(P-1)/n);
	W[0][0]=W[1][0]=1;
	for (i=1;i<n;i++) W[0][i]=(ll) W[0][i-1]*w%P;
	for (i=1;i<n;i++) W[1][i]=W[0][n-i];
}
void FFT(int *A,int n,int fg) {
	int i,j,k,l,t,u;
	for (i=0;i<n;i++) if (i<rev[i]) swap(A[i],A[rev[i]]);
	for (i=1;i<n;i<<=1)
		for (j=0;j<n;j+=i<<1)
			for (k=0,l=0;k<i;k++,l+=n/(i<<1)) {
				t=(ll) W[fg][l]*A[i+j+k]%P;
				u=A[j+k];
				A[j+k]=(u+t)%P;
				A[i+j+k]=(u+P-t)%P;
			}
	int inv=ksm(n,P-2);
	if (fg) for (i=0;i<n;i++) A[i]=(ll) A[i]*inv%P;
}
void Mul(int *A,int *B,int n) {
	int i;
	for (i=0;i<n;i++) a[i]=A[i],b[i]=B[i];
	FFT(a,n,0);FFT(b,n,0);
	for (i=0;i<n;i++) a[i]=(ll) a[i]*b[i]%P;
	FFT(a,n,1);
	for (i=0;i<=m;i++) A[i]=a[i];
}
int main() {
	scanf("%s",s1);
	scanf("%s",s2);
	int len=strlen(s1);
	for (i=0;i<len;i++) if (s1[i]=='1') {
		if (s2[i]=='1') m++;
		else n++;
	}
	pre(len+1);
	int nn=0;
	while ((1<<nn)<=m) nn++;
	nn++;
	Pre(1<<nn,nn);
	A[0]=1;
	for (i=0;i<=m;i++) B[i]=Jc_[i+1];
	for (k=n;k;k>>=1,Mul(B,B,1<<nn)) if (k&1) Mul(A,B,1<<nn);
	for (i=0;i<=m;i++) ans=(ans+A[i])%P;
	ans=(ll) ans*Jc[n]%P*Jc[m]%P*Jc[n+m]%P;
	printf("%d\n",ans);
}