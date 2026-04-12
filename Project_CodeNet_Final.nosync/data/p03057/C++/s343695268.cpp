#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define pb push_back
#define fi first
#define se second
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
const int N=200005,mod=1000000007;
ll ksm(ll a,int b){
	int ans=1;
	for(;b;b>>=1){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
	}
	return ans;
}
ll fac[N],f[N],ni[N];
char ch[N];
int q[N];
ll c(int a,int b){
	return a>=b&&b>=0?fac[a]*ni[b]%mod*ni[a-b]%mod:0;
}
int main(){
	//freopen("std.in","r",stdin); freopen("my.out","w",stdout);
	For(i,fac[0]=1,N-1)fac[i]=fac[i-1]*i%mod; ni[N-1]=ksm(fac[N-1],mod-2);
	Rep(i,N-1,1)ni[i-1]=ni[i]*i%mod;
	int n=read(),m=read();
	scanf("%s",ch+1);
	if(ch[1]=='B')For(i,1,m)ch[i]='R'+'B'-ch[i];
	int fr=1;
	For(i,2,m)if(ch[i]!=ch[i-1])fr=0;
	if(fr){
		ll ans=0;
		For(i,1,n)ans=(ans+c(i-1,n-i)+2*c(i-1,n-i-1))%mod;
		writeln(ans);
		return 0;
	}
	int cnt=0,mx=1e9,fff=1;
	For(i,1,m){
		if(ch[i]=='B'){
			if(cnt&1)mx=min(mx,cnt); else if(fff)mx=min(mx,cnt+1);
			cnt=0; fff=0;
		}else cnt++;
	}
	if(n&1){
		puts("0"); return 0;
	}
	int t=mx; 
	mx/=2; mx+=2;  //cout<<mx<<endl;
	static ll ans[N];
	ans[0]=1;
	For(i,1,n){
		if(i==1)ans[i]=-1; else ans[i]=0;
		ans[i]=(ans[i]+(ll)ans[i-1]*2)%mod;
		if(i>=mx)ans[i]=(ans[i]-ans[i-mx])%mod;
	}
	//For(i,0,n)cout<<ans[i]<<" ";puts("");
	ll sum=0;
	for(int i=1;i<=t&&i<n;i+=2){
		sum=(sum+(i+1)*ans[(n-i-1)/2])%mod;// cout<<(i+1)<<" "<<ans[(n-i-1)/2]<<endl;
	}
	cout<<(sum+mod)%mod<<endl;
}
/*
200000 8
RRBRRRRB

*/