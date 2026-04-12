#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=1e9+7;
signed main() {
	int n;
	cin>>n;
	int a[n+1],f[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]%=MOD;
		f[i]=a[i];
	}
	for(int i=n-1;i>=1;i--){
		f[i]+=f[i+1];
		f[i]%=MOD;
	}
	int s=0;
	for(int i=1;i<=n-1;i++){
		int t=a[i]*f[i+1];
		t%=MOD;
		s+=t;
		s%=MOD;
	}
	cout<<s;

	return 0;
}
