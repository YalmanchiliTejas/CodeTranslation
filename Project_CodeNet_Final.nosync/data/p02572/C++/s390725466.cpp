#include<bits/stdc++.h>
using namespace std;
long long n,pro,sum[200001],x;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>sum[i];
	}
	int s=0;
	for(int i=n-1;i>=1;i--){
		s=(s+sum[i+1])%1000000007;
		pro=(sum[i]*s+pro)%1000000007;
	}
	cout<<pro;
	return 0;
} 