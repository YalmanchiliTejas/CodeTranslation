#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e6+10,mod=1e9+7;
long long a[N],d[N];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=n;i>=1;i--)
		d[i]=(d[i+1]+a[i])%mod;
	long long ans=0;
	for(int i=1;i<n;i++)
		ans=(ans+a[i]*d[i+1]%mod)%mod;
	cout<<ans<<'\n';
}