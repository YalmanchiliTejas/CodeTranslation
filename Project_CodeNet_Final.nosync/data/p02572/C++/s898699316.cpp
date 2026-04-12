#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int modulo= 1000000007;
int main(){
	int n;
	cin>>n;
	int arr[n];
	ll sum=0;
	for(int i=0; i<n; i++){
		cin>>arr[i];
		sum+=arr[i];
		sum%=modulo;
	}
		ll ans=0;
		for(int i=0; i<n; i++){
			sum-=arr[i];
			if(sum<0) sum+=modulo;
			ans+=sum*arr[i];
			ans%=modulo;
		}
		cout<<ans;
}