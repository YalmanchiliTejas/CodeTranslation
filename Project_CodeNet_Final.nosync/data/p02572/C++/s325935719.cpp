#include <bits/stdc++.h>
using namespace std;
long long modl=1e9+7;
long long sum,ans;
long long a[200005],n;
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	for(int i=0;i<n;i++)
	{
		sum-=a[i];
		ans+=sum%modl*a[i];
		ans%=modl;
	}
	cout<<ans<<endl;
	return 0;
}
