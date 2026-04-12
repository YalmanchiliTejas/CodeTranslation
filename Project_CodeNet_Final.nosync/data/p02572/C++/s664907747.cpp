
// Problem : C - Sum of product of pairs
// Contest : AtCoder - AtCoder Beginner Contest 177
// URL : https://atcoder.jp/contests/abc177/tasks/abc177_c
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

// Delete the dynamically allocated memory

#include<bits/stdc++.h>
using namespace std;
 
#define ff              first
#define ss              second
#define pb              push_back
#define pr              pair<long long,long long>
#define mp(a,b)         make_pair(a,b)
#define vr              vector<long long>
#define mod1            1000000007
#define mod2            998244353
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define fill(a,b)       memset(a, b, sizeof(a))
#define mk(arr,n,type)  type *arr=new type[n];
#define ll              long long
#define ld	            long double
#define w(x)            int x; cin>>x; while(x--)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	mk(a,n,ll)
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	mk(dp,n,ll)
	dp[n-1]=a[n-1];
	for(ll i=n-2;i>=0;i--){
		dp[i]=(a[i]+dp[i+1])%mod1;
	}
	vr ans;
	ll sum=0;
	for(ll i=0;i<n-1;i++){
		ll v=(a[i]*dp[i+1])%mod1;
		ans.pb(v);
	}
	if(ans.size()==1){
		cout<<ans[0]<<"\n";
	}else{
		sum=ans[0]%mod1;
		for(ll i=1;i<ans.size();i++){
			sum=(sum+(ans[i])%mod1)%mod1;
		}
		cout<<sum<<"\n";
	}
	delete[] a;
	delete[] dp;
	return 0;
	}