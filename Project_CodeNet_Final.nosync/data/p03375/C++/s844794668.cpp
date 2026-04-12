#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ch() getchar()
#define pc(x) putchar(x)
template<typename T>inline void read(T&x){
	int f;char c;
	for(f=1,c=ch();c<'0'||c>'9';c=ch())if(c=='-')f=-f;
	for(x=0;c<='9'&&c>='0';c=ch())x=x*10+(c&15);x*=f;
}
template<typename T>inline void write(T x){
	static char q[64];int cnt=0;
	if(!x)pc('0');if(x<0)pc('-'),x=-x;
	while(x)q[cnt++]=x%10+'0',x/=10;
	while(cnt--)pc(q[cnt]);
}
const int maxn=3005;
int mod;
int mo(const int x){
	return x>=mod?x-mod:x;
}
int s[maxn][maxn],c[maxn][maxn],_0[maxn*maxn],_1[maxn];
int main(){
	int n;
	read(n),read(mod);
	s[0][0]=c[0][0]=1;
	for(int i=1;i<=n+1;++i){
		s[i][0]=0;c[i][0]=1;
		for(int j=1;j<=i;++j){
			s[i][j]=mo(s[i-1][j-1]+1ll*j*s[i-1][j]%mod);
			c[i][j]=mo(mod-c[i-1][j-1]+c[i-1][j]);
		}
	}
	int tmp=n*n;_0[0]=1;
	for(int i=1;i<=tmp;++i)
		_0[i]=mo(_0[i-1]<<1);
	_1[0]=2;
	for(int i=1;i<=n;++i)
		_1[i]=1ll*_1[i-1]*_1[i-1]%mod;
	int ans=0;
	for(int i=0;i<=n;++i){
		tmp=0;
		for(int j=0;j<=i;++j){
			tmp=mo(tmp+1ll*_0[(n-i)*j]*_1[n-i]%mod*s[i+1][j+1]%mod);
		}
		ans=mo(ans+1ll*c[n][i]*tmp%mod);
	}
	write(ans),pc('\n');
	return 0;
}
