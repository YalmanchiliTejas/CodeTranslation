#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);


main(){
	FIO
	int t;
	t=1;
	while(t--){
		int n;
		cin>>n;
		int arr[n],i,j,k;
		for(i=0;i<n;i++){
			cin>>arr[i];
		}
		
		int sum=0;
		k=arr[n-1];
		for(i=n-2;i>=0;i--){
			j = (k*arr[i])%mod;
			sum = (sum+j)%mod;
			k+=arr[i];
			k = k%mod;
		}
		cout<<sum<<endl;
	}
}