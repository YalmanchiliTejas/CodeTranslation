#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<long long int > a(n);
	for(int i=0;i<n;i++)
	cin>>a[i];
	long long int sum=0,mod=pow(10,9)+7,ans=0;
	for(int i=0;i<a.size();i++){
		ans=(ans%mod+((sum%mod)*(a[i]%mod))%mod)%mod;
		sum=(sum%mod+a[i]%mod)%mod;
	}
	cout<<ans<<endl;
}