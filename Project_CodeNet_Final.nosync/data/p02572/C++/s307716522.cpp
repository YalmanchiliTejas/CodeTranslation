#include<bits/stdc++.h>

#define ll long long
#define fi first
#define se second
#define mp make_pair

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;

int MOD = 1e9+7;

int main(){
	
	fastio();
	ll n,a[300000]={0};
	cin>>n;
	ll sum=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
		sum%=MOD;
	}
	ll ans=0;
	for(int i=0;i<n;i++){
		sum -=a[i];
		if(sum<0)sum+=MOD;
		ans += sum*a[i];
		ans%=MOD;
	}

	cout<<ans<<endl;
	
	
	
	
	return 0;
}