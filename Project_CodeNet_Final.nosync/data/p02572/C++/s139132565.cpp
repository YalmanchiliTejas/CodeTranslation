#include <bits/stdc++.h>

using namespace std;
const long long mod =1e9+7; 
int main(){
	int n;
	cin>>n;
	long long a[n];
	long long sum=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	long long s=0;
	for(int i=n-1;i>=0;i--){
		sum-=a[i];
		s=(s+((a[i]%mod)*(sum%mod))%mod)%mod;
	}
	cout<<s<<"\n";
}