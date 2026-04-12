#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
long long A[int(2e5)+5];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	int n;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>A[i];
	}
	long long alsum=0,sum=0;
	for(int i=1;i<=n;++i){
		alsum+=A[i];
	}
	long long less=0; 
	for(int i=1;i<=n-1;++i){
		less+=A[i];
		sum+=A[i]%mod*((alsum-less)%mod);
		sum%=mod;
	} 
	cout<<sum<<endl;
	return 0;
}