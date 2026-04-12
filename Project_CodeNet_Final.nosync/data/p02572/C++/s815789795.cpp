#include<bits/stdc++.h>
using namespace std;
vector<long long> arr;
#define mod 1000000007
int main(){
	long long n;
	cin>>n;
	long long sum=0;
	while(n--){
		long long a;
		cin>>a;
		arr.push_back(a);
	
	}
  	sum=arr[0];
	long long ans=0;
	for(long long x=1;x<arr.size();x++){
		long long temp=(sum*arr[x])%mod;
		ans=(ans+temp)%mod;
		sum=(sum+arr[x])%mod;
	}
	
		
	cout<<ans<<endl;

}