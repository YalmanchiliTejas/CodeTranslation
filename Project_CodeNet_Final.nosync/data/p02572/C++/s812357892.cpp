#include<bits/stdc++.h>
using namespace std;
long long arr[200005];
long long psum[200005];
long long moder = 1000000007;
int main(){
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) cin>>arr[i];
	for(int i=1; i<=n; i++) psum[i]=psum[i-1]+arr[i];
	long long ret = 0;
	for(int i=1; i<n; i++){
		ret+=(((psum[n]-psum[i])%moder)*arr[i])%moder;
		ret%=moder;
	}
	cout<<ret;
}