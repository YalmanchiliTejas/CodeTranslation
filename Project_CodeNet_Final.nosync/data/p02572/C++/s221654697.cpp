#include <bits/stdc++.h>
using namespace std;
# define ll  long long

	int mod =1e9+7;


	int main() {

		#ifndef ONLINE_JUDGE
	        freopen("input.txt","r",stdin);
	        // freopen("output.txt","w",stdout);
	    #endif
	    ios::sync_with_stdio(false);
	    cin.tie(0);
	    cout.tie(0);  
	    int n;
	    cin>>n;

	    int arr[n];
	    ll sum[n+1];
	    sum[0]=0;
	    for(int i=0;i<n;i++){
	    	cin>>arr[i];
	    	sum[i+1]=sum[i]+arr[i];
	    	
	    }

	    ll ans=0;
	    for(int i=0;i<n;i++){
	    	int check=(sum[n]-sum[i+1])%mod;
	    	ans = ans+ 1LL* check *arr[i];
	    	ans%=mod;
	    }

	    cout<<ans<<endl;
	}
