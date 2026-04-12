#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mxn=2*1e5,M=1e9+7;
int a[mxn],n;
	void solve(){
		cin>>n;	ll sum=0;

		for(int i=0;i<n;i++){
			cin>>a[i];
			sum+=a[i];
			sum%=M;
		}
					ll ans=0;
		for(int i=0;i<n;i++){
			sum-=a[i];
			if(sum<0)sum+=M;
					ans+=sum*a[i];
			ans%=M;
		}
	cout<<ans;	
	}
int main(){
	solve();
}
