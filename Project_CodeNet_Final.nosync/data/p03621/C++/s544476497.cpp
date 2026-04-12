#include <bits/stdc++.h>
#define pb push_back
#define cmin(a,b) (a>b?a=b:a)
#define cmax(a,b) (a<b?a=b:a)
#define lop(i,s,t) for(int i=s;i<(t);++i)
#define rep(i,s,t) for(int i=s;i<=(t);++i)
#define dec(i,s,t) for(int i=s;i>=(t);--i)
#define fore(i,v) for(int i=g[v],d=es[i].d;i;i=es[i].nxt,d=es[i].d)
#define use(x) using std::x
use(swap); 

#define Pr(f,...) //printf(f,##__VA_ARGS__),fflush(stdout)

typedef long long ll;

const int N=50005,G=3,P=998244353;

int mul(int a,int b){ return 1ll*a*b%P; }
int add(int a,int b){ a+=b; return a>=P?a-P:a; }
int sub(int a,int b){ a-=b; return a<0?a+P:a; }
int pwr(int a,int k){
	int res=1;
	for(;k;k>>=1,a=mul(a,a))
		if(k&1)res=mul(res,a);
	return res;
}
void upd(int &a,int b){ a=add(a,b); }

int n,X,Y,fac[N],inv[N],f[N],tr[N],ans;
char A[N],B[N]; 

void fft(int n,int* x,int f){
	for(int i=0,j=0;i<n;++i){
		if(i<j)swap(x[i],x[j]); 
		for(int l=n>>1;(j^=l)<l;l>>=1);
	}
	for(int s=2;s<=n;s<<=1){
		int m=s>>1;
		int wn=pwr(G,(P-1)/s);
		if(f==-1)wn=pwr(wn,P-2);
		for(int j=0;j<n;j+=s){
			int w=1;
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
	static int p,A[N],B[N];
	for(p=1;p<n+m-1;p<<=1);
	lop(i,0,p)A[i]=B[i]=0;
	lop(i,0,n)A[i]=a[i];
	lop(i,0,m)B[i]=b[i];
	fft(p,A,1),fft(p,B,1);
	lop(i,0,p)A[i]=mul(A[i],B[i]);
	fft(p,A,-1);
	lop(i,0,n+m-1)c[i]=A[i];
}

int main(int argc,char *argv[]){
#ifdef CURIOUSCAT
	freopen("dat.in","r",stdin);
	freopen("my.out","w",stdout);
#endif
	scanf("%s%s",A,B); 
	n=strlen(A); 
	lop(i,0,n){
		if(A[i]!=B[i])++X;
		if(A[i]=='1'&&B[i]=='1')++Y;
	}
	X/=2;
	fac[0]=1; rep(i,1,n)fac[i]=mul(fac[i-1],i); 
	inv[1]=1; rep(i,2,n)inv[i]=mul(P-P/i,inv[P%i]);
	inv[0]=1; rep(i,1,n)inv[i]=mul(inv[i-1],inv[i]); 
	f[0]=1;
	rep(k,0,Y)tr[k]=inv[k+1];
	for(int k=X;k;k>>=1,mul(Y+1,tr,Y+1,tr,tr)){
		if(k&1)mul(Y+1,f,Y+1,tr,f);
	}
	rep(fre,0,Y){
		int z=mul(fac[X],mul(fac[Y],mul(fac[X+Y],f[Y-fre])));
		ans=add(ans,z);  
	}
	printf("%d\n",ans); 
	return 0;
}