#include<bits/stdc++.h>
using namespace std;

const int N=100100,mod=1000000007;
typedef long long ll;
int ksm(ll a,int b,int c=1){
	for(;b;b/=2,a=a*a%mod)
		if(b&1)c=c*a%mod;
	return c;
}
int jc[N],f[N],g[N],jc2[N],n,A,B,C,D; 
void init(){
	jc[0]=1;
	for(int i=1;i<=n;++i)jc[i]=(ll)jc[i-1]*i%mod;
	jc2[n]=ksm(jc[n],mod-2);
	for(int i=n;i;--i)jc2[i-1]=(ll)jc2[i]*i%mod;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>A>>B>>C>>D;init();
	f[0]=1;
	for(int i=A;i<=B;++i){
		g[0]=1;
		for(int j=1;j<=n;++j)g[j]=(ll)g[j-1]*jc2[i]%mod;
		for(int j=n;j>=0;--j)if(f[j])
			for(int k=C;k<=D&&i*k+j<=n;++k)
				f[i*k+j]=(f[i*k+j]+(ll)f[j]*g[k]%mod*jc2[k])%mod;
	}
	cout<<((ll)f[n]*jc[n]%mod)<<'\n';
	return 0;
}
