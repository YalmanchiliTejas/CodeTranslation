#include<bits/stdc++.h>
#define ll long long int
#define M 1000000007
#define mod 998244353
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define pi pair<ll,ll>
using namespace std;
const ll N=500010;

ll n,s;
ll ar[N];

ll dp[3010][3010];

ll func(ll idx,ll s)
{
    if(idx<0){
        if(s==0){return 1;}
        else{return 0;}
    }

    if(dp[idx][s]==-1){
        ll ways=0;
        if(s==0){ways=1;}
        ways=(ways+func(idx-1,s))%mod;
        if(s-ar[idx]>=0)
        {ways=(ways+func(idx-1,s-ar[idx]))%mod;}
        dp[idx][s]=ways;
    }
    return dp[idx][s];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>s;
	for(ll i=0;i<n;++i){cin>>ar[i];}

	ll ans=0;
	memset(dp,-1,sizeof(dp));
	for(ll i=0;i<n;++i)
    {
        ans=(ans+func(i,s))%mod;
    }
    cout<<ans<<endl;

	return(0);
}
