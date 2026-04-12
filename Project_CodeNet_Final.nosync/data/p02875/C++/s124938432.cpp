#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<ll,ll>
#define poly vector<ll>
#define mem(a) memset((a),0,sizeof(a))
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define pb push_back
#define fi first
#define se second
#define SZ(x) ((int)(x.size()))
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
const int N=10000004,mod=998244353;
ll fac[N],pw[N/2],ni[N];
ll c(int a,int b){
	return fac[a]*ni[b]%mod*ni[a-b]%mod;
}
ll ksm(ll a,int b){
	int ans=1;
	for(;b;b>>=1){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
	}
	return ans;
}
int main(){
	#ifdef Brollan
		freopen("1.in","r",stdin);
	#endif
	int n=read(),ans=0;
	For(i,fac[0]=1,n)fac[i]=fac[i-1]*i%mod;
	ni[n]=ksm(fac[n],mod-2);
	Rep(i,n,1)ni[i-1]=ni[i]*i%mod;
	For(i,pw[0]=1,n/2)pw[i]=pw[i-1]*2%mod;
	For(i,n/2+1,n)ans=(ans+c(n,i)*pw[n-i+1])%mod;
	cout<<(ksm(3,n)-ans+mod)%mod<<endl;
}
