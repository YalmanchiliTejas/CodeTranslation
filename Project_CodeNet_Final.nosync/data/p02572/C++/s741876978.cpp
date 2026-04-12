#include<bits/stdc++.h>
using namespace std;
long long int a[200001];
const int mod=1000000007;
int  main() {
	long long int n,m=0,ma=0;
	cin>>n;
	for (int i=1; i<=n; i++) { 
		cin>>a[i];
		m+=a[i]%1000000007;
		m=m%1000000007;
	}
	
	for (int i=1; i<n; i++) {

		m=(m-a[i]+mod)%mod;

		ma=a[i]*m+ma;
		ma=ma%1000000007;
	}
	
	
	cout<<ma;
	return 0;
}