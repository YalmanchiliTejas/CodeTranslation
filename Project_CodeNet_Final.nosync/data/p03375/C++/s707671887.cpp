#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
#define ll long long
#define db double
#define rint register int
#define re register
#define eps 1e-10
#define mk make_pair
#define fs first
#define pint pair<int,int>
#define sd second
#define inf 1ll<<58
#define N 3005
using namespace std;
inline char get(){const int TOP=1<<20;static char T[TOP],*x=T,*y=T;return x==y&&(y=(x=T)+fread(T,1,TOP,stdin),x==y)?EOF:*x++;}
inline int read (){register int num,sign=1;register char c;
while (((c=get())<'0'||c>'9')&&c!='-');c=='-'?num=sign=0:num=c-48;while ((c=get())>='0'&&c<='9')num=(num<<3)+(num<<1)+(c-48);return sign?num:-num;}
int n,mod,tmp,ans;
int s[N][N],c[N][N];
inline int power(rint x,rint k,rint mod){rint ans=1;while(k){if(k&1)ans=1ll*ans*x%mod;x=1ll*x*x%mod;k>>=1;}return ans;}
int main(){
	n=read();mod=read();c[0][0]=1;
	for(rint i=1;i<=n;++i){
		c[i][0]=c[i][i]=1;
		for(rint j=1;j<i;++j)c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
	}
	for(rint i=0;i<=n;++i){
		s[i][0]=1;
		for(rint j=1;j<=i;++j)s[i][j]=(s[i-1][j-1]+1ll*(j+1)*s[i-1][j]%mod)%mod;
	}
	for(rint i=0;i<=n;++i){
	 	int tmp=((i&1?-c[n][i]:c[n][i])+mod)%mod,res=power(2,power(2,n-i,mod-1),mod),sum=0;
		for(rint j=0,x=power(2,n-i,mod),now=1;j<=i;++j,now=1ll*now*x%mod){sum=(sum+1ll*s[i][j]*now%mod)%mod;}
		ans=(ans+1ll*sum*res%mod*tmp%mod)%mod;
	}printf("%d\n",ans);
}
