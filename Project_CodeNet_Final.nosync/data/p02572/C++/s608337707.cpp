

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define int long long
#define w(t) int t;cin>>t;while(t--)
#define pb push_back
#define mk make_pair
#define ascSort(v) sort(v.begin(), v.end())
#define descSort(v) sort(v.begin(), v.end(), greater<int>())
#define ff first
#define ss second
#define pi pair<int,int>
#define vi vector<int>
//#define umapi umapi
const int mod=1e9+7;
const int m=998244353;
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>PBDS;

void FIO(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);	
}



int32_t main(){
	
	//FIO();
	
		int n;cin>>n;
		vi a(n);
		for(int i=0; i<n; i++)
			cin>>a[i];
		vi pref(n+1);
		pref[n]=0;
		for(int i=n-1; i>=0; i--)
			pref[i]=(pref[i+1]+a[i])%mod;
		

		int ans=0;
		for(int i=0; i<n; i++){
			ans+=(a[i]*pref[i+1])%mod;
			ans%=mod;
		}
		cout<<ans<<"\n";
		
	
	

	return 0;
		
}


	
			
	
