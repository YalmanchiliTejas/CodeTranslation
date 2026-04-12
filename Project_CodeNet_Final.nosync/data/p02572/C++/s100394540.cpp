#include <bits/stdc++.h>
using namespace std;
long long a[200010];
int main(){
	int n;
	cin>>n;
	long long sum=0;
	long long ans=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		ans+=1LL*sum*a[i];
		sum+=a[i];
		ans%=(1000000000+7);
		sum%=(1000000000+7);
	}
	cout<<ans<<endl;
	return 0;
}