#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define int long long
const int mod = 1e9 + 7;
void test_case(){
	int n; cin>>n;
	int a[n], sum = 0;
	for(int i=0;i<n;i++) {
		cin>>a[i];
		sum += a[i];
		sum %= mod;
	}
	int ans = 0;
	for(int i=0;i<n;i++){
		sum -= a[i];
		sum = (sum + mod) % mod;
		int t = sum * a[i];
		t%=mod;
		ans += t;
		ans %= mod;
	}
	cout<<ans<<endl;
	
	
}
		
 
signed main(){
	IOS;
	int t=1, i=1; 
	//cin>>t;
	while(t--){
		//cout<<"Case #"<<i<<": ";
		test_case();
		i++;
	}
}
