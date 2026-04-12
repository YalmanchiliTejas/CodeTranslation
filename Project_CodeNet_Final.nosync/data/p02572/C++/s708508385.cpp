#pragma GCC optimize(3,"Ofast","inline")
#pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;
template<class t> inline t read(t &x){
	char c=getchar();bool f=0;x=0;
	while(!isdigit(c)) f|=c=='-',c=getchar();
	while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
	if(f) x=-x;return x;
}
template<class t,class ...A> inline void read(t &x,A &...a){
	read(x);read(a...);
}
template<class t> inline void write(t x){
	if(x<0) putchar('-'),write(-x);
	else{if(x>9) write(x/10);putchar('0'+x%10);}
}

#define int long long

const int N=2e5+5,mod=1e9+7;
int a[N],sum[N],ans,n;

signed main(){
	read(n);
	for(int i=1;i<=n;i++) read(a[i]),sum[i]=(sum[i-1]+a[i])%mod;
	for(int i=1;i<=n;i++) ans=(ans+a[i]*((sum[n]-sum[i]+mod)%mod)%mod)%mod;
	write(ans);
}