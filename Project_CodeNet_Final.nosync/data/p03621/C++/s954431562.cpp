#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define forE(i,x) for(int i=head[x];i!=-1;i=ne[i])
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned u32;
typedef pair<int,int> pin;
#define mk(a,b) make_pair(a,b)
#define lowbit(x) ((x)&(-(x)))
#define sqr(a) ((a)*(a))
#define clr(a) (memset((a),0,sizeof(a)))
#define ls ((x)<<1)
#define rs (((x)<<1)|1)
#define mid (((l)+(r))>>1)
#define pb push_back
#define w1 first
#define w2 second
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
inline void judge(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
}
/*******************************head*******************************/
const int maxn=10005,mod=998244353;
int f[maxn][maxn];
int fac[maxn<<1],facinv[maxn<<1];
inline int powmod(int a,int b){
	int res=1;
	for(;b;b>>=1){
		if(b&1)res=1ll*res*a%mod;a=1ll*a*a%mod;
	}return res;
}
inline void prprpr(){
	fac[0]=1;
	rep(i,1,20000)fac[i]=1ll*fac[i-1]*i%mod;
	facinv[20000]=powmod(fac[20000],mod-2);
	per(i,19999,0)facinv[i]=1ll*facinv[i+1]*(i+1)%mod;
}
inline int C(int n,int m){
	return 1ll*fac[n]*facinv[m]%mod*facinv[n-m]%mod;
}
char s1[maxn],s2[maxn];
int len,n,m;
int main(){
	prprpr();
	scanf("%s",s1+1);
	scanf("%s",s2+1);
	len=strlen(s1+1);
	rep(i,1,len)n+=s1[i]=='1'&&s2[i]=='1',m+=s1[i]=='1'&&s2[i]=='0';
	f[0][0]=1;
	rep(i,0,n)rep(j,0,m){
		if(i==0&&j==0)continue;
		f[i][j]=(1ll*i*j*(i?f[i-1][j]:0)+1ll*j*j*(j?f[i][j-1]:0))%mod;
	}
	int ans=0;
	rep(k,0,n)ans=(ans+1ll*C(n,k)*fac[n-k]%mod*fac[n-k]%mod*f[k][m]%mod*C(n+m,k+m))%mod;
	printf("%d\n",ans);
	return 0;
}
