/* ****GT_18**** */

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
#define ll          long long
#define pb          push_back
#define	endl		'\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define INF			1000000000000000
#define rep(i,a,b)	for(ll int i=a;i<b;i++)
#define repr(i,a,b) for(ll int i=a;i>=b;i--)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 

using namespace std;
using namespace __gnu_pbds;

#define N  100005

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int TESTS=1;
//	cin>>TESTS;
	while(TESTS--)
	{
		ll n;
		cin>>n;
		ll x,m;
		cin>>x>>m;
		vi mods;
		mods.pb(x);
		bool used[m+1];
		memset(used,0,sizeof(used));
		used[x]=1;
		ll ans=x;
		rep(i,2,n+1){
			ll curr = mods.back();
			ll newval = (curr*curr) %m;
			if(used[newval]){
				ll len = 0;
				ll cyclesum = 0;
				bool f=0;
				rep(j,0,sz(mods)){
					if(mods[j]==newval){
						len = sz(mods)-j;
						f=1;
					}
					if(f)cyclesum+=mods[j];
				}
				ll rem = n-i+1;
				ll fullcycles = rem/len;
				ll left  = rem%len;
				ans+=fullcycles*cyclesum;
				ll st = sz(mods)-len;
				while(left--){
					ans+=mods[st++];
				}
				break;

			}
			else{
				mods.pb(newval);
				used[newval]=1;
				ans+=newval;
			}
		}	
		cout<<ans<<endl;
	}
	return 0;
}