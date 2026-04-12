#include <bits/stdc++.h>
#define pb push_back
#define cmin(a,b) (a>b?a=b:a)
#define cmax(a,b) (a<b?a=b:a)
#define lop(i,s,t) for(int i=s;i<(t);++i)
#define rep(i,s,t) for(int i=s;i<=(t);++i)
#define dec(i,s,t) for(int i=s;i>=(t);--i)
#define fore(i,v) for(int i=g[v],d=es[i].d;i;i=es[i].nxt,d=es[i].d)
using namespace std;

typedef long long ll;

const int N=1<<14,M=205,P=998244353,G=3;

int mul(int a,int b){ return 1ll*a*b%P; }
int add(int a,int b){ a+=b; return a>=P?a-P:a; }
int sub(int a,int b){ a-=b; return a<0?a+P:a; }
void upd(int &x,int k){ x=add(x,k); }
int pwr(int a,int k){ 
	int res=1;
	for(;k;k>>=1,a=mul(a,a))
		if(k&1)res=mul(res,a);
	return res;
}

int n,m,ans,fac[N],inv[N];

int C(int n,int m){
	if(n<0||m>n)return 0;
	return mul(fac[n],mul(inv[m],inv[n-m]));
}

void ntt(int n,int *x,int f){
	for (int i=0,j=0;i<n;++i){
		if(i<j)swap(x[i],x[j]);
		for(int l=n>>1;(j^=l)<l;l>>=1);
	}
	for(int s=2;s<=n;s<<=1){
		int m=s>>1;
		for(int j=0;j<n;j+=s){
			int wn=pwr(G,(P-1)/s),w=1;
			if(f==-1)wn=pwr(wn,P-2);
			lop(k,0,m){
				int z=mul(x[j+m+k],w);
				x[j+m+k]=sub(x[j+k],z);
				x[j+k]=add(x[j+k],z);
				w=mul(w,wn);
			}
		}
	}
	if(f==-1){
		int y=pwr(n,P-2);
		lop(i,0,n)x[i]=mul(x[i],y);
	}
}

void mul(int n,int *a,int m,int *b,int *c){
	static int A[N],B[N];
	int p=1;
	while(p<n+m-1)p<<=1;
	lop(i,0,n)A[i]=a[i]; lop(i,n,p)A[i]=0;
	lop(i,0,m)B[i]=b[i]; lop(i,m,p)B[i]=0;
	ntt(p,A,1),ntt(p,B,1);
	lop(i,0,p)c[i]=mul(A[i],B[i]);
	ntt(p,c,-1);
}
	
int f[N],ff[N],tr[N],g[N];

void dp(){
	rep(i,0,n){
		tr[i]=inv[i+2];
		ff[i]=mul(f[i],inv[i]);
	}
	tr[0]=0;
	mul(n+1,ff,n+1,tr,g);
	rep(i,0,n)g[i]=mul(g[i],fac[i+2]);
	rep(i,0,n)g[i]=add(g[i],mul(f[i],add(1,C(i+1,2))));
	rep(i,0,n)f[i]=g[i];
}

int main(int argc,char *argv[]){
#ifdef CURIOUSCAT
	freopen("dat.in","r",stdin);
	freopen("my.out","w",stdout);
#endif
	cin>>n>>m;
	fac[0]=1; lop(i,1,N)fac[i]=mul(fac[i-1],i);
	inv[1]=1; lop(i,2,N)inv[i]=mul(P-P/i,inv[P%i]);
	inv[0]=1; lop(i,1,N)inv[i]=mul(inv[i],inv[i-1]);

	f[0]=1;
	lop(k,0,m)dp();

	rep(k,0,n)ans=add(ans,mul(C(n,k),f[k]));
	cout<<ans<<endl;
	return 0;
}
