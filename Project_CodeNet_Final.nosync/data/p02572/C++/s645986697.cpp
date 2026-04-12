#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
#define ll long long int
#define ld long double
#define ff first
#define ss second  
#define endl '\n'
#define pb push_back
#define t_case ll tt; cin>>tt; while (tt--)
#define all(v) v.begin(),v.end()
#define ub(a,x) upper_bound(all(a),x)-a.begin()
#define lb(a,x) lower_bound(all(a),x)-a.begin()
#define fr(a,b,c) for (ll a=b;a<c;a++)
#define take(xx,n) for (int i=0;i<n;i++) cin>>xx[i];
#define take1(xx,n) for (int i=1;i<=n;i++) cin>>xx[i];
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
const auto inf=LLONG_MAX; 
ll mod=1e9+7;
int main() 
{
	fastio
	//t_case
	{
		ll sum=0,ans=0,n,m=0,mx=-inf,mn=inf,p,f ;cin>> n ;
		ll a[n+1],pref[n+2]={}; take1 (a,n);
		for(int i=n;i>0;i--){
			pref[i]=(pref[i+1]+a[i])%mod;
			//cout<<pref[i]<<endl;
		}
		fr(i,1,n) {
			ans=(ans+(a[i]*(pref[i+1]%mod))%mod) % mod;
			//cout<<ans<<" "<<a[i]<<" "<<pref[i+1]<<endl;
		}
		cout<<ans%mod;
		cout<<endl;
	}
	return 0;
}