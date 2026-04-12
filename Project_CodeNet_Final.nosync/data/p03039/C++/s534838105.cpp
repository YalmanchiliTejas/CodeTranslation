#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
inline int inv(int x){
	return modpow(x,mod-2,mod);
}
inline int C(int x,int y){
	int ret=1;
	for(int i=x;i>x-y;i--)ret=((ll)ret*i)%mod;
	for(int i=y;i>=1;i--)ret=((ll)ret*inv(i))%mod;
	return ret;
}
int n,m,k;
int ans,ans1,ans2,mul;
int main(){
	cin>>n>>m>>k;
	mul=C(n*m-2,k-2);
	for(int i=1;i<m;i++){
		ans1=(ans1+(ll)i*(m-i)%mod)%mod;
	}
	ans1=(ll)ans1*n%mod*n%mod;
	for(int i=1;i<n;i++){
		ans2=(ans2+(ll)i*(n-i)%mod)%mod;
	}
	ans2=(ll)ans2*m%mod*m%mod;
	ans=(ans1+ans2)%mod;
	cerr<<ans<<" "<<mul<<endl;
	ans=(ll)ans*mul%mod;
	cout<<ans<<endl;
	return 0;
}