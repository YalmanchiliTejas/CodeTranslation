#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 83333,mo=998244353;
int n,a,b,fac[N],ifac[N];char s[N],t[N];
int power(int a, int n){
	int res=1;
	while(n){
		if(n&1)res=1LL*res*a%mo;
		a=1LL*a*a%mo;n>>=1;
	}
	return res;
}
int g[N],f[N],w[N],x[N],y[N];
inline void fft(int *a, int n, int tp){
	for(int i=1,j=0;i<n;i++){
		for(int k=n>>1;!((j^=k)&k);k>>=1);if(i<j)swap(a[i],a[j]);
	}
	for(int j=2;j<=n;j<<=1){
		w[0]=1;w[1]=power(3,(mo-1)/j);if(tp==-1)w[1]=power(w[1],mo-2);
		rep(i,2,(j>>1)-1)w[i]=1LL*w[i-1]*w[1]%mo;
		for(int k=0;k<n;k+=j)rep(i,0,(j>>1)-1){
			int x=a[k+i],y=1LL*a[k+i+(j>>1)]*w[i]%mo;
			a[k+i]=x+y<mo?x+y:x+y-mo;a[k+i+(j>>1)]=x-y>=0?x-y:x-y+mo;
		}
	}
}
inline void mul(int *_a, int *_b, int *c, int m){
	int n;for(n=1;n<=m+m;n<<=1);
	rep(i,0,m)x[i]=_a[i],y[i]=_b[i];rep(i,m+1,n-1)x[i]=y[i]=0;
	fft(x,n,1);fft(y,n,1);
	rep(i,0,n-1)x[i]=1LL*x[i]*y[i]%mo;
	fft(x,n,-1);int ni=power(n,mo-2);rep(i,0,n-1)c[i]=1LL*x[i]*ni%mo;
}
inline void solve(int n){
	if(!n){g[0]=1;return;}
	if(n==1){rep(i,0,b)g[i]=ifac[i+1];return;}
	if(n&1){
		solve(n-1);rep(i,0,b)f[i]=ifac[i+1];mul(g,f,g,b);
	}
	else{
		solve(n>>1);mul(g,g,g,b);
	}
}
int main() {
	scanf("%s%s",s+1,t+1);n=strlen(s+1);
	fac[0]=1;rep(i,1,n)fac[i]=1LL*fac[i-1]*i%mo;
	ifac[n]=power(fac[n],mo-2);per(i,n-1,0)ifac[i]=1LL*ifac[i+1]*(i+1)%mo;
	rep(i,1,n)a+=s[i]=='1'&&t[i]=='0',b+=s[i]=='1'&&t[i]=='1';
	/*f[0][0]=1;
	rep(i,1,a)rep(j,0,b)rep(k,0,j)
		f[i][j]=(f[i][j]+1LL*f[i-1][k]*fac[b-k]%mo*ifac[b-j]%mo*ifac[j-k+1])%mo;*/
	solve(a);rep(i,0,b)g[i]=1LL*g[i]*fac[b]%mo*ifac[b-i]%mo;
	
	ll res=0;rep(j,0,b)res+=1LL*g[j]*fac[b-j]%mo;res=res%mo*fac[a+b]%mo*fac[a]%mo;cout<<res;
	return 0;
}
