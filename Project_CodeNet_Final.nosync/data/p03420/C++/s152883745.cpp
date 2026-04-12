#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long n,k;
	cin>>n>>k;
	long long ans=0;
	if(k==0){
		cout<<n*n;
		return 0;
	}
	for(int i=k+1;i<=n;i++){
		long long t=n/i;
		ans+=(i-k)*t;
		ans+=max(0LL,n-t*i-k+1);
	}
	cout<<ans;
	return 0;
}