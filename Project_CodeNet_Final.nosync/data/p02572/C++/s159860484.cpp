#include<bits/stdc++.h>
using namespace std;
const long long Mod=1e9+7;
long long n,a[200010],sum[200010],ans;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=(sum[i-1]+a[i-1])%Mod;
	}
	for(int i=1;i<=n;i++)
		ans=(ans+sum[i]*a[i])%Mod;
	cout<<ans<<endl;
	return 0;
}