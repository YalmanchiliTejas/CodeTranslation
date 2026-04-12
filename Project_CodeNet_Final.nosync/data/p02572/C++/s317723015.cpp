#include <bits/stdc++.h>
using namespace std;
const long long N = 1e9+7;
int main() {
	// your code goes here
	int n;
	cin>>n;
	int arr[n+1];
	long long ans=0;
	long long sum[n+1];
	sum[0]= 0;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		sum[i] = (sum[i-1] + arr[i]) % N;
	}
	
	for(int i=1;i<=n-1;i++){
		ans = ans + ((arr[i])*(((sum[n]-sum[i]) + N )% N))%N;	
		ans =(ans+ N)%N;	
	}
	ans = (ans + N)%N;
			cout<<ans<<endl;
	return 0;
}