#include<bits/stdc++.h>
using namespace std;

//#define mod      1e9+7;
#define INF      1e9+9;
#define ps(x,y)  fixed<<setprecision(y)<<x
# define PI 3.14159265358979323846264338327950 L
typedef long long ll;
typedef unsigned long long ull;
ll mod=1e9+7;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n;
	cin>>n;
	ll a[n],pref[n+1];
	pref[0]=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		pref[i+1]=pref[i]+a[i];
	}
	ll ans=0;
	for(int i=0;i<n;i++){
		ll val=pref[n]-pref[i+1];
		val=val%mod;
		val=(val*a[i])%mod;
		ans+=val;
		ans=ans%mod;
	}
	cout<<ans<<endl;
	return 0;
}