#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<bitset>
#include<set>
#define N (10000010)
#define P (998244353)
#define M ()
#define inf (0x7f7f7f7f)
#define rg register int
#define Label puts("NAIVE")
#define spa print(' ')
#define ent print('\n')
#define rand() (((rand())<<(15))^(rand()))
#define file(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
typedef long double ld;
typedef long long LL;
typedef unsigned long long ull;
using namespace std;
namespace fastIO1{
	inline char read(){
		static const int IN_LEN=1000000;
		static char buf[IN_LEN],*s,*t;
		return (s==t?t=(s=buf)+fread(buf,1,IN_LEN,stdin),(s==t?-1:*s++):*s++);
	}
	template<class T>
	inline void read(T &x){
		static bool iosig;
		static char c;
		for(iosig=false,c=read();!isdigit(c);c=read()){
			if(c=='-')iosig=true;
			if(c==-1)return;
		}
		for(x=0;isdigit(c);c=read())x=((x+(x<<2))<<1)+(c^'0');
		if(iosig)x=-x;
	}
	inline char readc(char &c){
		for(c=read();!isalpha(c)&&!isdigit(c);c=read())
		if(c==-1)return 0;
	}
	const int OUT_LEN = 10000000;
	char obuf[OUT_LEN],*ooh=obuf;
	inline void print(char c){
		if(ooh==obuf+OUT_LEN)fwrite(obuf,1,OUT_LEN,stdout),ooh=obuf;
		*ooh++=c;
	}
	template<class T>
	inline void print(T x){
		static int buf[30],cnt;
		if(x==0)print('0');
		else{
			if(x<0)print('-'),x=-x;
			for(cnt=0;x;x/=10)buf[++cnt]=x%10+48;
			while(cnt)print((char)buf[cnt--]);
		}
	}
	inline void flush(){fwrite(obuf,1,ooh-obuf,stdout);}
}
namespace fastIO2{
	template<class T>
	inline void read(T &x){
		static bool iosig;
		static char c;
		for(iosig=false,c=getchar();!isdigit(c);c=getchar()){
			if(c=='-')iosig=true;
			if(c==-1)return;
		}
		for(x=0;isdigit(c);c=getchar())x=((x+(x<<2))<<1)+(c^'0');
		if(iosig)x=-x;
	}
}
using namespace fastIO1;
int n,jc[N],inv[N],pw[N],ans;
int ksm(int a,int p){
	int res=1;
	while(p){
		if(p&1)res=1ll*res*a%P;
		a=1ll*a*a%P,p>>=1;
	}
	return res;
}
int C(int n,int m){
	return 1ll*jc[n]*inv[m]%P*inv[n-m]%P;
}
int main(){
	read(n); inv[0]=jc[0]=pw[0]=1;
	for(int i=1;i<=n;i++)jc[i]=1ll*jc[i-1]*i%P,pw[i]=2ll*pw[i-1]%P;
	inv[n]=ksm(jc[n],P-2);for(int i=n-1;i;i--)inv[i]=1ll*inv[i+1]*(i+1)%P;
	for(int i=n/2+1;i<=n;i++)(ans+=1ll*C(n,i)*pw[n-i]%P)%=P;
	printf("%lld\n",(0ll+ksm(3,n)-ans+P-ans+P)%P);
}