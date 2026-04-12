#include <bits/stdc++.h>
#define ll long long
#define Start ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define fr first
#define sc second
#define PI 3.14159265
#define ullt unsigned long long int
using namespace std;
const int MOD=1e9+7;
ll mod (ll x){
	return (x%MOD+MOD)%MOD;
}
ll add(ll x,ll y){
	return mod(y)+mod(x);
}
ll mul(ll x,ll y){
	return mod(x)*mod(y);
}
void solve(){
	ll n;
	cin>>n;
	vector<ll>a(n+1);
	for(int i=0;i<n;i++)cin>>a[i];
	vector<ll>pre(n+1);
	pre[0]=a[0];
	for(int i=1;i<n;i++)pre[i]=pre[i-1]+a[i];
	ll ans=0;
	for(int i=0;i<n;i++)
		ans=add(ans,mul(a[i],pre[n-1]-pre[i]));
	cout<<ans;
	

}
int main()
{
	Start;

	int t = 1;
	//cin>>t;
	while (t--)
	{
		solve();
		cout << "\n";
	}
	return 0;
} 
