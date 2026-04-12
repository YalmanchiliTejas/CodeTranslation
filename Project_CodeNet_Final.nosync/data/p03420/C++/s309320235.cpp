#include <bits/stdc++.h>
#include <math.h>

using namespace std;

long long inf=1000000007;

long long modpow(long long n,long long p,long long mod);

int main(){
	long long n,k;
	cin>>n>>k;
	long long ans=0;
	for(long long i=k+1;i<=n;i++){
		ans+=(n/i)*(i-k);
		long long hoge=n%i;
		if(k!=0) hoge++;
		ans+=max((long long)0,hoge-k);
	}

	cout<<ans<<endl;

	return 0;
}

long long modpow(long long n,long long p,long long mod){
	if(p==0) return 1;
	if(p%2==0) return (modpow(n,p/2,mod)*modpow(n,p/2,mod))%mod;
	if(p%2==1) return (modpow(n,p-1,mod)*n)%mod;
	cerr<<"ERROR"<<endl;
	return 1;
}
