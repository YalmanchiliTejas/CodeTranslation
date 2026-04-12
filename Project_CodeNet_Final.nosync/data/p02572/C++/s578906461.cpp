#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){	if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
inline void print(int x){
	if(x<0) x=-x,putchar('-');
	if(x>=10) print(x/10);
	putchar(x%10+48);
}
int n;
int a[200010];
long long ans;
long long sum[200010];
const int mod=1e9+7;
int main(){
	n=read();for(int i=1;i<=n;++i) a[i]=read();
	for(int i=n;i>=1;--i) sum[i]=(sum[i+1]+a[i])%mod;
	for(int i=1;i<=n;++i){
		ans=(ans+1ll*sum[i+1]*a[i]%mod)%mod;
	}
	printf("%d\n",ans);
	return 0;
}