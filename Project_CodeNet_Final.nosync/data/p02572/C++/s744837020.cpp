#include <iostream>

using namespace std;

int mod=1000000000+7;

int main(){

	int n;
	cin>>n;
	long long int a[n];
	long long int ans=0;
	long long int sum=0;
	for(int i=0;i<n;i++){
	
		cin>>a[i];
		sum+=a[i];
		sum%=mod;
	}
	for(int i=0;i<n;i++){	

		sum-=a[i];
		if(sum<0){
			sum+=mod;
		}
		ans+=(a[i]*sum)%mod;
		ans%=mod;
	}
	cout<<ans;
	return 0;
}
