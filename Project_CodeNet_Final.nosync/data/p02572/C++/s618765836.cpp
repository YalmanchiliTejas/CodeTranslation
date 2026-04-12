#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n,m,i,j,k,ans,cur,mod=1000000007;
	cin >> n;
	vector<long long> a(n),s(n);
	for(i=0; i<n; i++){
		cin >> a[i];
	}
	s[0]=a[0];
	for(i=1; i<n; i++){
		s[i]=s[i-1]+a[i];
		s[i]%=mod;
	}
	
	ans=0;
	for(i=1; i<n; i++){
		ans+=a[i]*s[i-1];
		ans%=mod;
	}
	
	cout << ans << endl;
	return 0;
}