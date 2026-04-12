#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef long double ld;
#define fr first
#define sc second
#define pb push_back
const ll mod = 998244353;
const int N = 1e6+205;
ll a[N];
ll b[N];
int vis[N];
void solve(){
	ll n,x,m; 
	cin>>n>>x>>m;	
	if(n<=m){
		ll ans = x;
		for(int i=2;i<=n;i++){
			x = (x*x)%m;
			ans+=x;
		}
		cout<<ans<<endl;
		return ;
	}
	a[1] = x;
	ll sum = 0;
	vis[x] = 1;
	b[1] = x;
	ll len = -1;
	ll idx = -1;
	for(int i=2;i<=m+12;i++){
		a[i] = (a[i-1]*a[i-1])%m;
		b[i]=b[i-1]+a[i];
		if(vis[a[i]]){
			sum = b[i]-b[vis[a[i]]];
			len = i-vis[a[i]];
			idx= i;
			break;
		}
		vis[a[i]] = i;
	}
	if(n<=idx){
		cout<<b[n]<<endl;
		return ;
	}
	assert(idx!=-1);
	assert(len>0);
	ll ans = b[idx-1];
	n-=idx;
	ll div = n/len;
	ans+=div*sum;
	n%=len;
	x = a[idx];
	for(int i=0;i<=n;i++){
		ans+=x;
		x = (x*x)%m;
	}
	cout<<ans<<endl;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t=1; 
//	cin>>t; 
	while(t--){
		solve();
	}
	return 0;
}
