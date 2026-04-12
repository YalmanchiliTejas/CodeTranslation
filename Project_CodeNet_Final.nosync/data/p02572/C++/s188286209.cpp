#include<bits/stdc++.h>

using namespace std;

long long int mod=1e9+7;

long long int arr[200006];

int main(){
	long long n;
	cin>>n;
	long long int sum=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		sum+=arr[i]%mod;
	}
	long long int ans=0;
	for(int i=0;i<n-1;i++){
		sum=(sum-arr[i]+mod)%mod;
		ans+=(arr[i]*(sum))%mod;
	}
	cout<<ans%mod<<endl;
}