	#include<bits/stdc++.h>
	using namespace std;
	#define int long long int
	#define pb push_back
	const int mod=1e9+7;
	#define all(x) x.begin(),x.end()
	#define endl '\n'
	#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

	
	int32_t main(){
		IOS;
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		int sum=arr[0];
		int ans=0;
		
		for(int i=1;i<n;i++){
			ans=(ans+(sum*arr[i])%mod)%mod;
			sum=(sum+arr[i])%mod;
		}
		cout<<ans<<endl;
		return 0;
	}
