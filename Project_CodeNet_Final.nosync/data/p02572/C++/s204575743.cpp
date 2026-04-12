#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n;
	cin>>n;
	long long a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long p[n+1];
	for(int i=1;i<=n;i++){
		p[i]=0;
	}
	p[n]=a[n];
	long long s=0;
	for(int i=n-1;i>=1;i--){
		p[i]=p[i+1]+a[i];
		p[i]%=1000000007;
		s+=(p[i+1]*a[i])%1000000007;
		s%=1000000007;
	}
	cout<<s<<endl;
	return 0;
}