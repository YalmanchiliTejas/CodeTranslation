#include <iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	long long suf[n],a[n],s=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	long long sum=0,mod=1e9+7;
	for(int i=n-1;i>=0;i--){
		s+=a[i];
		suf[i]=s%mod;
	}
	
	for(int i=0;i<n-1;i++){
	sum+=(a[i]*(suf[i+1])) % mod;
	}
	cout<<sum%mod;
	return 0;
}