#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin>>n;
	long long int arr[n];
	long long int a[n];
	long long sum=0;
	long long prev=0;
	long long int ans=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		sum=sum+arr[i];
	}
for(int i=0;i<n-1;i++){
	a[i]=(1000000007 +sum%1000000007-arr[i]%1000000007)%1000000007;
	sum=a[i];
}
	for(int i=0;i<n-1;i++){
		ans=(ans%1000000007 + (arr[i]%1000000007 *(a[i])%1000000007)%1000000007)%1000000007;
	}
	cout<<ans;
	return 0;
}