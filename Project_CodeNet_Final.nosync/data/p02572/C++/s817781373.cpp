#include<iostream>
using namespace std;
const int  N=2e5+7;
const int  mod=1e9+7;
long long  arr[N];
long long  num[N];
int  main(){
	long long  n;
	cin>>n;
	for(int  i=1;i<=n;i++){
		cin>>num[i];
	}
	for(int  i=n;i>=1;i--){
		arr[i]=(arr[i+1]+num[i])%mod;
	}
	long long  ans=0;
	for(int  i=1;i<=n;i++){
		ans=(ans+num[i]*arr[i+1])%mod;
	}
	cout<<ans<<endl;
	return 0;
}