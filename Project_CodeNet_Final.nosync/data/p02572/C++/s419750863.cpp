#include<iostream>
#include<algorithm>

using namespace std;
const int N=200010,mod=1000000007;

int n,a[N];
long long sum[N],ans;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) sum[i]=(sum[i-1]+a[i])%mod;
	for(int i=1;i<=n-1;i++){
		ans+=a[i]*(sum[n]-sum[i]);
		ans%=mod;
	}
	cout<<(ans%mod+mod)%mod;
	return 0;
}