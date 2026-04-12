#include<bits/stdc++.h>
using namespace std;
const long long inf=1e9+7;
int n;
long long a[200005];
long long lsum[200005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		lsum[i]=a[i]+lsum[i+1];
		lsum[i]%=inf;
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		ans+=a[i]*lsum[i+1];
		ans%=inf;
	}
	cout<<ans<<endl;
	return 0;
}