#include<bits/stdc++.h>
using namespace std;
int main(){
	long n;
	cin>>n;
	long a[n];
	const long mod=1e9+7;
	long long sum=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
		sum=sum%mod;
	}
	long ans=0;
	for(int i=0;i<n;i++){
		sum-=a[i];
		if(sum < 0){
			sum+=mod;
		}
		ans+=((a[i]%mod)*(sum%mod))%mod;
		ans=ans%mod;
	}
	cout<<ans%mod;
	
}