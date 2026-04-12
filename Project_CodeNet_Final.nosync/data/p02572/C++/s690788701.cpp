#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	long long ans=0,s=0;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		ans=ans+s*a;
		ans=ans%1000000007;
		s+=a;
		s=s%1000000007;
	}
	cout<<ans;
} 