#include<bits/stdc++.h>
using namespace std;
int main(){
	long int n;
	cin>>n;
	long long int ar[n];
	for(int i=0;i<n;i++){
		cin>>ar[i];
	}
	long long int ans=0;
	long long int fr[n];
	fr[0]=ar[0];
	for(long int i=1;i<n;i++){
		fr[i]=fr[i-1]+ar[i];
		
	}
	for(long int i=0;i<n-1;i++){
		
		ans+=((fr[i]%1000000007)*ar[i+1])%1000000007;
	}
	ans=ans%1000000007;
	cout<<ans;
}
