#include<bits/stdc++.h>
#define ll long long
const int N=1e7+10,mod=998244353;
int n,mul,sum,fc[N],fi[N];
int main(){
	std::cin>>n;
	fc[0]=fc[1]=fi[0]=fi[1]=mul=1;
	for(int i=2;i<=n;i++)fc[i]=(ll)fc[i-1]*i%mod;
	for(int i=2;i<=n;i++)fi[i]=(ll)(mod-mod/i)*fi[mod%i]%mod;
	for(int i=2;i<=n;i++)fi[i]=(ll)fi[i-1]*fi[i]%mod;
	for(int i=1;i<=n;i++)mul=3ll*mul%mod;
	for(int i=n,s=1;i>=(n>>1)+1;i--,s=(s<<=1)>=mod?s-mod:s){
		sum=(sum+(ll)fc[n]*fi[i]%mod*fi[n-i]%mod*s)%mod;
		// std::cerr<<"> "<<i<<" "<<s<<" "<<std::endl;
	}
	// std::cerr<<mul<<" "<<sum<<std::endl;
	std::cout<<((ll)mul+(mod-sum<<1))%mod<<std::endl;
}