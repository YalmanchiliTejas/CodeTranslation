#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n;vector<ll>a;
	cin>>n;
	for(ll i=0;i<n;i++){
		ll x;
		cin>>x;
		a.push_back(x);
	}
	sort(a.begin(),a.end());reverse(a.begin(),a.end());
	ll sum=0;
	if(n%2==0){
		ll m=n/2;
		for(ll i=0;i<n;i++){
			if(i==m-1){
				sum+=a[i];
			}
			else if(i==m){
				sum-=a[i];
			}
			else if(i<m-1){
				sum+=2*a[i];
			}
			else{
				sum-=2*a[i];
			}
		}
	}
	else{
		ll m=n/2;
		for(ll i=0;i<n;i++){
			if(i==m){
				sum+=a[i];
			}
			else if(i==m-1){
				sum+=a[i];
			}
			else if(i<m-1){
				sum+=2*a[i];
			}
			else {
				sum-=2*a[i];
			}
		}
		//cout << sum<<endl;
		ll sum2=0;
		for(ll i=0;i<n;i++){
			if(i==m){
				sum2-=a[i];
			}
			else if(i==m+1){
				sum2-=a[i];
			}
			else if(i<m){
				sum2+=2*a[i];
			}
			else{
				sum2-=2*a[i];
			}
		}
		//cout<<sum2<<endl;
		sum=max(sum2,sum);
	}
	cout <<sum;
	// your code goes here
	return 0;
}