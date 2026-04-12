#include<bits/stdc++.h>
using namespace std;
int n;
long long a[55];
int main() {
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	long long ans=0;
	while (true) {
		sort(a+1,a+1+n);
		if (a[n]<n) break;
		long long x=a[n]/n;
		ans+=x;
		for(int i=1;i<n;i++) a[i]+=x;
		a[n]%=n;
	}
	cout<<ans<<endl;
	return 0;
}