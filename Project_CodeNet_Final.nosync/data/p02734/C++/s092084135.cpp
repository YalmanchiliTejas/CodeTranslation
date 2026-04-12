#pragma GCC optimize(3,"Ofast","inline") 
#include <bits/stdc++.h>
using namespace std;
template<class t> inline t read(t &x){
	char c=getchar();bool f=0;x=0;
	while(!isdigit(c)) f|=c=='-',c=getchar();
	while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
	if(f) x=-x;return x;
}
template<class t> inline void write(t x){
	if(x<0) putchar('-'),write(-x);
	else{if(x>9) write(x/10);putchar('0'+x%10);}
}

const int N=3005,mod=998244353;
int n,m,ans,f[N];




signed main(){
	read(n);read(m);
	for(int i=1,x;i<=n;i++){
		read(x);
		for(int j=m;j>x;j--) f[j]=(f[j]+f[j-x])%mod;
		f[x]=(f[x]+i)%mod;
		ans=(ans+1ll*f[m]*(n-i+1)%mod)%mod;
		f[m]=0;
	}
	write(ans);
}