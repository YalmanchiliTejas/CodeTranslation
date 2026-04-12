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
#define N (200010)
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
int n,m,f[N]; char s[N];
void spj(){
	int f[N][2];
	for(int i=1;i<=m;i++)if(s[i]=='R')return;
	int ans=0; f[1][0]=0,f[1][1]=1;
	for(int i=2;i<=n;i++){
		f[i][0]=f[i-1][1];
		f[i][1]=(f[i-1][0]+f[i-1][1])%P;
	}
	(ans+=(f[n][0]+f[n][1])%P)%=P;
	f[1][0]=1,f[1][1]=0,f[2][0]=0,f[2][1]=1;
	for(int i=3;i<=n;i++){
		f[i][0]=f[i-1][1];
		f[i][1]=(f[i-1][0]+f[i-1][1])%P;
	}
	(ans+=f[n][1])%=P;
	printf("%d\n",ans);
	exit(0);
}
int main(){
	read(n),read(m);
	for(int i=1;i<=m;i++)readc(s[i]);
	if(s[1]=='R'){for(int i=1;i<=m;i++)s[i]^='R'^'B';}
	spj(); int lst=m,lim=n,cnt=0; while(s[lst]=='B')lst--;
	for(int i=lst;~i;i--)
	if(!i||s[i]=='R'){
		if(cnt&1)lim=min(lim,cnt+1);
		else if((!i)&&cnt)lim=min(lim,cnt+2);
		cnt=0;
	}
	else cnt++;
//	cout<<lim<<endl; 
	f[0]=f[2]=1;
	for(int i=4;i<=n;i+=2){
		f[i]=1ll*f[i-2]*2%P;
		if(i-2>=lim)f[i]=(f[i]-f[i-lim-2]+P)%P;
	}
	int ans=0;
	for(int i=2;i<=lim;i+=2)
	(ans+=1ll*f[n-i]*i%P)%=P;
	cout<<ans;
}