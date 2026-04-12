#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	long long a[n],f[n+1]={};
	cin>>a[0];
	for(int i=1;i<n;i++){
		cin>>a[i];
	}
	f[n-1]=a[n-1];
	for(int i=n-2;i>0;i--){
		f[i]=f[i+1]+a[i];
		f[i]%=1000000007;
	}
	long long s=0;
	//for(int i=0;i<n;i++) cout<<f[i]<<' ';
	for(int i=0;i<n;i++){
		s=(s+a[i]*f[i+1])%(1000000007);
	}
	cout<<s;
}