#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

const int mx=2e6;

int main(){
	int n,i;
	long long int ans=0,sum=0;
	cin>>n;
	vector<int> arr(n);
	for(i=0;i<n;i++){
		cin>>arr[i];
		sum+=arr[i];
	}

	for(i=0;i<n;i++){
		sum-=arr[i];
		//v = sum%mod;
		ans+=((sum%mod)*(arr[i]%mod)+mod)%mod;
	}
	cout<<ans%mod<<endl;
}