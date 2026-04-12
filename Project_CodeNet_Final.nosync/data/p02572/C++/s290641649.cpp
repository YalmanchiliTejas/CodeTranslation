#include<bits/stdc++.h>
using namespace std;
#define int long long int
signed main()
 {
	int n; cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];

	int ans=0;
    int help[n];
    help[n-1]=0;
	for(int i=n-2;i>=0;i--){
	    help[i]=help[i+1]+arr[i+1];
	    help[i]%=1000000007;
	}
	for(int i=0;i<n-1;i++){
        int x=(arr[i]*help[i])%1000000007;
        ans+=x;
        ans%=1000000007;
	}
	cout<<ans;
	return 0;
}
