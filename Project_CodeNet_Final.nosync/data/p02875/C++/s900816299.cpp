#include <bits/stdc++.h>
using namespace std;
#define ref(i,x,y)for(int i=x;i<=y;++i)
#define def(i,x,y)for(int i=x;i>=y;--i)
const int mod=998244353;
const int N=10000010;
typedef long long LL;
int n;
int ft[N+1],Ft[N+1],mi2[N+1];
int C(int n,int m){
	return (LL)ft[n]*Ft[m]%mod*Ft[n-m]%mod;
}
int mi(int a,int b){
	int s=1;
	for(;b;b>>=1,a=(LL)a*a%mod)
		if(b&1)s=(LL)s*a%mod;
	return s;
}
int main(){
	scanf("%d",&n);
	ft[0]=1;
	ref(i,1,n)ft[i]=(LL)ft[i-1]*i%mod;
	Ft[n]=mi(ft[n],mod-2);
	def(i,n,1)Ft[i-1]=(LL)Ft[i]*i%mod;
	mi2[0]=1;
	ref(i,1,n)mi2[i]=(LL)mi2[i-1]*2%mod;
	int ans=mi(3,n);
	int s=0,nn=n/2;
	ref(i,nn+1,n)s=((LL)C(n,i)*mi2[n-i+1]+s)%mod;
	ans=(ans+mod-s)%mod;
	cout<<ans<<endl;
}