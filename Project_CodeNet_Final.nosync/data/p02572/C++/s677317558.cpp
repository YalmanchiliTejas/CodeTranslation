#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int main(){
	int n;
	cin>>n;
	vector<long long> a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	long long sum=0;
	for(int i=1;i<n;i++){
		sum+=a[i];
		sum%=mod;
	}
	long long ans=0;
	for(int i=0;i<n-1;i++){
		long long temp=a[i]*sum;
		temp%=mod;
		ans+=temp;
		ans%=mod;
		sum=((sum%mod)-(a[i+1]%mod)+mod)%mod;
	}
	cout<<ans<<'\n';
}