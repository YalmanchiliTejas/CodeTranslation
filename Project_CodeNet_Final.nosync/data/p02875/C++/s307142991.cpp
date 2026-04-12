#include<bits/stdc++.h>
using namespace std;
#define nn 10000008
#define int long long 
#define mod 998244353
int f[nn],rf[nn];
int qpow(int x,int y=mod-2){
	int res=1;
	while(y){
		if(y&1) res=res*x%mod;
		x=x*x%mod;y=y/2;
	}
	return res;
}
int n;int p2[nn];
int C(int x,int y){
	return f[x]*rf[y]%mod*rf[x-y]%mod;
}
signed main(){
	f[0]=1;for(int i=1;i<nn;i++) f[i]=f[i-1]*i%mod;
	rf[nn-1]=qpow(f[nn-1]);
	for(int i=nn-2;i>=0;i--) rf[i]=rf[i+1]*(i+1)%mod;
	
	p2[0]=1;for(int i=1;i<nn;i++) p2[i]=p2[i-1]*2%mod;
	
	cin>>n;
	
	int ans=qpow(3,n);
	for(int i=n/2+1;i<=n;i++){
		ans-=C(n,i)*p2[n-i+1];
		ans%=mod;
	}
	ans+=mod;ans%=mod;cout<<ans%mod;
	
	
	return 0;
} 