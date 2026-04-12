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
#define N (110)
#define P (1000000007)
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
int n,m,h[N],oth=1;
typedef pair<int,int> PII;
int ksm(int a,int p){
	int res=1;
	while(p){
		if(p&1)res=1ll*res*a%P;
		a=1ll*a*a%P,p>>=1; 
	}
	return res;
}
PII solve(int L,int R,int lim){
	//if(L>R)return;
	//cout<<L<<" "<<R<<endl;
	int mn=inf,cnt=0; PII cur;
	for(int i=L;i<=R;i++)if(h[i]<mn)mn=h[i],cnt=1;else if(h[i]==mn)cnt++;
	if(cnt==R-L+1){
		cur.first=(1ll*ksm(2,R-L+1)+P-2)%P;
		cur.second=ksm(2,mn-lim-1);
		return cur;
	}
	int l=R-L+1,s0=1,s1=1,lst=0;
	for(int i=L;i<=R+1;i++)
	if(!lst&&h[i]>mn)lst=i;
	else if(lst&&(h[i]<=mn||i>R)){
		l-=i-lst;
		PII ans=solve(lst,i-1,mn);
		s0=1ll*s0*(ans.first+4ll*ans.second%P)%P;
		s1=2ll*s1*ans.second%P; lst=0;
	}
	cur.first=1ll*(s0-s1+P)*ksm(2,l)%P;
	cur.first=(cur.first+1ll*s1*(ksm(2,l)+P-2)%P)%P;
	cur.second=1ll*s1*ksm(2,mn-lim-1)%P;
	return cur;
}
int main(){
	read(n);
	for(int i=1;i<=n;i++)read(h[i]);
	if(n==1)printf("%d\n",ksm(2,h[1])),exit(0);
	for(int i=1;i<=n;i++)
	if(h[i]>h[i+1]&&h[i]>h[i-1]){
		oth=1ll*oth*ksm(2,h[i]-max(h[i+1],h[i-1]))%P;
		h[i]=max(h[i-1],h[i+1]);
	}
	PII ans=solve(1,n,0);
	printf("%lld\n",1ll*oth*(0ll+ans.first+ans.second+ans.second)%P);
}