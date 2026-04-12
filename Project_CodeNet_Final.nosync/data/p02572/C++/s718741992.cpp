#include<iostream>
#include<stack>
#include<string>
using namespace std;
const int M=1e9+7;
int main(){
	long long int n;
	cin>>n;
	long long int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	long long int ans=0;
	long long int prefix[n];
	prefix[n-1]=a[n-1];
	for(long long int i=n-2;i>=0;i--){
		prefix[i]=a[i]+prefix[i+1];
	}
	for(int i=0;i<n-1;i++){
		ans+=((a[i]%M)*(prefix[i+1]%M))%M;
	}
	cout<<ans%M;
	return 0;
}