#include<bits/stdc++.h>

using namespace std;

#define int64 long long 
const int mod = (int) 1e9 + 7;


int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	int64 ans = 0, sum = 0;
	for(int i=n-1; i>=0; i--){
		ans = (ans + (arr[i]*sum)%mod)%mod;
		sum = (sum + arr[i])%mod;
	}
	cout<<ans;
	
}
