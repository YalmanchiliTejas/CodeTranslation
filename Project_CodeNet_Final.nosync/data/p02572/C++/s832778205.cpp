#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
const unsigned int M = 1000000007;
 
int32_t main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin>>n;
	int a[n],sm=0,ans=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sm+=a[i];
	}
	for(int i=0;i<n-1;i++){
		sm=sm-a[i];
		ans= ans%M  + ((a[i]%M)*(sm%M))%M;
	}
	cout<<ans%M;
	return 0; 
} 
