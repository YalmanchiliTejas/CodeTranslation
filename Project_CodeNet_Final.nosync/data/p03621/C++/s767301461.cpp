#include<bits/stdc++.h>
#define mms(x,l) memset(x,0,sizeof(x[0])*(l))
#define mmp(x,y,l) memcpy(x,y,sizeof(y[0])*(l))

using namespace std;
typedef long long ll;

const int N=20,P=998244353,M=33005,g=3;

char A[M],B[M];
int l,n,m,k,fac[M],ifac[M],inv[M],f[M],a[M],ans;
int _w[N][M];

inline int fpow(int a,int t){static int r;for(r=1;t;a=(ll)a*a%P,t>>=1)if(t&1)r=(ll)r*a%P;return r;}
inline int lset(int x){int l=1;while(l<=x)l<<=1;return l;}
void make(int n){
	n++;n=lset(n);
	int l=2,p=1,w;
	while(l<=n){
		w=fpow(g,(P-1)/l);int*f=_w[p];f[0]=1;
		for(int j=1;j<(l>>1);j++)f[j]=(ll)f[j-1]*w%P;
		l<<=1,p++;
	}
	inv[1]=1;
	for(int i=2;i<=n;i++)inv[i]=P-(ll)inv[P%i]*(P/i)%P;
}
void ntt(int*a,int n,int d){
	int i,j=n>>1,k,t=0,l,u,v,*p;
	for(i=1;i<n-1;i++){
		if(i<j)swap(a[i],a[j]);
		for(k=n>>1;(j^=k)<k;k>>=1);
	}
	for(l=2;l<=n;l<<=1){
		i=l>>1,p=_w[++t];
		for(j=0;j<n;j+=l)for(k=0;k<i;k++){
			u=a[j+k],v=(ll)a[j+k+i]*p[k]%P;
			a[j+k]=(u+v)%P,a[j+k+i]=(u-v+P)%P;
		}
	}
	if(d==-1){
		for(i=0,v=fpow(n,P-2);i<n;i++)a[i]=(ll)a[i]*v%P;
		for(i=1;i<n/2;i++)swap(a[i],a[n-i]);
	}
}

void convol(int A[],int B[],int R[],int n){
	static int x[M],y[M],z[M];
	mms(x,n),mmp(x,A,n),mms(y,n),mmp(y,B,n);
	ntt(x,n,1),ntt(y,n,1);
	for(int i=0;i<n;i++)z[i]=(ll)x[i]*y[i]%P;
	ntt(z,n,-1),mmp(R,z,n);
}

void Inv(int A[],int R[],int n){
	if(n==1){*R=fpow(*A,P-2);return;}
	static int T[M],t1[M],t2[M],t3[M];
	int d=(n+1)/2;
	Inv(A,T,d);
	int m=lset(d*2+n-3);
	mms(t1,m),mms(t2,m),mms(t3,m);
	mmp(t1,T,d),mmp(t2,A,n);
	ntt(t1,m,1);ntt(t2,m,1);
	for(int i=0;i<m;i++)t3[i]=((2*t1[i]-(ll)t1[i]*t1[i]%P*t2[i])%P+P)%P;
	ntt(t3,m,-1);
	mmp(R,t3,n);
}

void Ln(int f[],int a[],int n){
	static int g[M],t[M],b[M];
	int m=lset(2*n-2);
	mms(g,m),mms(t,m),mms(b,m);
	for(int i=1;i<n;i++)g[i-1]=(ll)f[i]*i%P;
	Inv(f,t,n);
	convol(t,g,b,m);
	a[0]=0;
	for(int i=1;i<n;i++)a[i]=(ll)b[i-1]*inv[i]%P;
}

void Exp(int c[],int f[],int n){
	if(n==1){f[0]=1;return;}
	static int f0[M],g0[M],t1[M],t2[M],t3[M];
	int d=(n+1)/2,m=lset(n+d-2);
	Exp(c,f0,d);
	Ln(f0,g0,n);
	mms(t1,m),mms(t2,m),mms(t3,m);
	mmp(t1,f0,n);
	for(int i=0;i<n;i++)t2[i]=(c[i]-g0[i]+P)%P;
	t2[0]++;
	convol(t1,t2,t3,m);
	mmp(f,t3,n);
}

int main(){
	scanf("%s%s",A+1,B+1);
	l=strlen(A+1);
	for(int i=1;i<=l;i++){
		int j=(A[i]&1)+(B[i]&1);
		if(j==2)m++;else if(j)n++;
	}
	n>>=1;k=n+m;
	fac[0]=1;
	for(int i=1;i<=k;i++)fac[i]=(ll)fac[i-1]*i%P;
	ifac[k]=fpow(fac[k],P-2);
	for(int i=k;i>=1;i--)ifac[i-1]=(ll)ifac[i]*i%P;
	make(m<<1);
	for(int i=0;i<=m;i++)f[i]=ifac[i+1];
	Ln(f,a,m+1);
	for(int i=0;i<=m;i++)a[i]=(ll)a[i]*n%P;
	Exp(a,f,m+1);
	for(int i=0;i<=m;i++)ans=(ans+f[i])%P;
	ans=(ll)ans*fac[n+m]%P*fac[n]%P*fac[m]%P;
	printf("%d\n",ans);
	return 0;
}