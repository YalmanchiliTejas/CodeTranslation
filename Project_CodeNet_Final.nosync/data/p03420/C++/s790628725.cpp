//ITNOA
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
typedef long long ll;
const ll INF=1e9+10,MAX=2e5+1e4,MOD=1e9+7,MAXL=25;
typedef pair<ll,ll> pii;
typedef pair<pii,ll> piii;
void OUT(long double o,int x){
	 cout<<fixed<<setprecision(x)<<o;
	 return;
}
ll a[MAX];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n,k,ans=0;
	cin>>n>>k;
	for(int i=k+1;i<=n;i++){
		ll m=n;
		m-=i-1;
		ans+=i-k;
		ans+=(m/i)*(i-k);
		if(k==0)
			ans--;
		m%=i;
		ans+=max(ll(0),((m%i)-k));
		//cerr<<i<<" "<<ans<<'\n';
	}
	cout<<ans;
	return 0;
}
