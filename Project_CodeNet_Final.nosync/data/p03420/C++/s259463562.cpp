/* dsingh_24 */

#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define	endl		'\n'
#define pii         pair<ll ,ll>
#define vll          vector<ll>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define rep(i,a,b)	for(ll int i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define ios         ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

#define N  100005

int main()
{
	ios
	ll n,k,i,j;
	cin>>n>>k;
	if(k==0){cout<<n*n;return 0;}
	ll sum=0;
	for(i=k+1;i<=n;i++)
	{
		ll cy=(n/i);
		ll ans=0;
        ans+=(i-k)*cy;
        ll tt=i*cy+k;
     //   cout<<ans<<"\n";
        if(n-tt+1>0)ans+=n-tt+1;
        sum+=ans;
	}
	cout<<sum;
	return 0;
}