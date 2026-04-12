#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define F first
#define S second
#define mod 1000000007
#define all(a) a.begin(),a.end()
#define dbg(n) cout<<#n<<' '<<n<<endl;
#define dbg_v(v) cout<<#v<<":";for(auto c:v) cout<<" "<<c; cout<<endl;
int power(ll x,ll y){ll res = 1;while(y>0){if(y&1)res = (res*x)%mod;y=y>>1;x=(x*x)%mod;}return res;}

void solve(){
	int n;
	cin>>n;
	ll a[n];
	for (int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	ll pre[n];
	pre[n-1]=a[n-1];
	for (int i = n-2; i >= 0; i--)
	{
		pre[i]=(pre[i+1]+a[i])%mod;
	}
	//dbg_v(pre);
	ll ans=0;
	for (int i = 0; i < n-1; i++)
	{
		ans=(ans+(a[i]*pre[i+1])%mod)%mod;
	}
	cout<<ans<<endl;
}

int main(){ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	int T=1;
	//cin>>T;
	while(T--)
		solve();
}

