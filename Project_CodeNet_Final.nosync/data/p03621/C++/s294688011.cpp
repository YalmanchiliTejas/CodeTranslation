#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
#define ld long double
#define PI pair<int,int>
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
	ll x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){write(a); puts("");}
inline void wri(ll a){write(a); putchar(' ');}
inline ull rnd(){
	return ((ull)rand()<<30^rand())<<4|rand()%4;
}
const int N=10005,mod=998244353;
ll fac[N],ni[N];
int f[N][N],n,m,ans;
char a[N],b[N];
inline int ksm(ll a,int b){
	int ans=1;
	for(;b;b>>=1){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
	}
	return ans;
}
ll c(int a,int b){
	return fac[a]*ni[a-b]%mod*ni[b]%mod;
}
signed main(){
	scanf("%s%s",a,b);
	for(int i=0;i<10000;i++)if(a[i]=='1'){
		if(b[i]=='1')n++; else m++;
	}
	for(int i=fac[0]=1;i<N;i++)fac[i]=fac[i-1]*i%mod; ni[N-1]=ksm(fac[N-1],mod-2); for(int i=N-1;i;i--)ni[i-1]=ni[i]*i%mod;
	f[0][0]=1;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i)f[i][j]=(ll)f[i-1][j]*i*j%mod;
			if(j)f[i][j]=(f[i][j]+(ll)f[i][j-1]*j*j)%mod;
		}
		ans=(ans+c(n,i)*fac[n-i]%mod*c(n+m,i+m)%mod*fac[n-i]%mod*f[i][m])%mod;
	}
	cout<<ans<<endl;
	
}