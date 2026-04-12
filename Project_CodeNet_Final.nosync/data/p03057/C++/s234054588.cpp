#include<bits/stdc++.h>
using namespace std;
const int N=200100,mod=1000000007;
typedef long long ll;
int f[N],sum[N],n,m;
char s[N];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>(s+1);
	int mn=max(n,m)+1,sz=0,flag=0;
	for(int i=1;i<=m;++i)	
		if(s[i]==s[1])++sz;
		else{
			if(sz&1)mn=min(mn,sz);
			else if(sz&&!flag)mn=min(mn,sz+1);
			sz=0;flag=1;
		}
	int L=0,R=0;
	if(flag){
		if(n&1){
			cout<<0<<'\n';
			return 0;
		}
		n/=2;L=1;R=min(n,(mn+1)/2);
	}else L=2,R=n;
	f[0]=sum[0]=1;
	for(int i=1;i<=n;++i){
		f[i]=sum[i-L];if(i>R)f[i]=(f[i]-sum[i-R-1]+mod)%mod;
		sum[i]=(sum[i-1]+f[i])%mod;
	}
	int ans=0;
	for(int i=L;i<=R;++i)ans=(ans+(ll)i*f[n-i])%mod;
	if(flag)ans=ans*2%mod;else ans=(ans+1)%mod;
	cout<<ans<<'\n';
	return 0;
}
