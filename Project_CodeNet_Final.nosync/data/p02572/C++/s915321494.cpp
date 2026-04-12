#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define FAST  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define ll long long int 
#define ar array
#define pb push_back
#define fi(a,b) for(int i=a;i<(b);i++)
#define fj(a,b) for(int j=a;j<(b);j++)
#define fk(a,b) for(int k=a;k<(b);k++)
#define lb lower_bound
#define ub upper_bound
//hash base 177013

const int mod=1e9+7;

int main()
{
	FAST;
	//#ifndef ONLINE_JUDGE
	//	freopen("input.txt","r",stdin);
	//	freopen("output.txt","w",stdout);
	//#endif
	//ll testcase;
	//cin>>testcase;
	//while(testcase--)
	{
		int n;
		cin>>n;
		ll a[n];
		fi(0,n) cin>>a[i];
		ll pref[n];
		pref[0]=a[0];
		ll total=a[0];
		fi(1,n)
		{
			total=(total+a[i])%mod;
			pref[i]=(pref[i-1]+a[i])%mod;
		}
		ll ans=0;
		assert(pref[n-1]==total);
		fi(0,n)
		{
			ll first=(total-pref[i])%mod;
			if(first<0) first+=mod;	
			ans=(ans+(a[i]*first)%mod)%mod;
		}
		cout<<ans;
	}
}
























