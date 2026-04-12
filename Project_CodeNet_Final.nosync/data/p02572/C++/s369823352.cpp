#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
    	cin>>arr[i];
	}
	long long int g=arr[n-1];
	long long int ans=0;
	long long int mod=1000000007;
	for(int i=n-2;i>=0;i--){
		ans=(ans%mod+((arr[i]%mod)*(g%mod))%mod)%mod;
		g=(g%mod+arr[i]%mod)%mod;
	}
	cout<<ans<<"\n";
    return 0;
}