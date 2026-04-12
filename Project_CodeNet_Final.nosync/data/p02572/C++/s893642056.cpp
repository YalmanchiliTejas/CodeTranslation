#include<bits/stdc++.h>
#include<iomanip>
#define fast {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define mxn 19
#define mod 1000000007
#define ld long double
#define pb push_back
#define inf 1e18
#define fi first
#define se second
typedef long long int ll;
using  namespace std;
int main(void){
	#ifndef ONLINE_JUDGE
	freopen("input1.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	fast;
	ll n,i;
	cin>>n;
	ll a[n],s=0,ans=0;
	for(i=0;i<n;i++){
		cin>>a[i];
		ans+=(s*a[i]);
		ans%=mod;
		s+=a[i];
		s%=mod;
	}
	cout<<ans;
}
