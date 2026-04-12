#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define mod 1000000007
#define vll vector<ll>
#define pll vector<pair<ll,ll>>
#define debug(x) cout<<x<<endl

ll n,arr[3000],ti[3000][3000];

ll mx(ll a,ll b)
{
    if(a>=b) return a;
    else return b;
}

ll func(ll s,ll e)
{
    if(s>e) return 0;

    if(s==e)
        return arr[s];

    if(ti[s][e]!=-1)
            return ti[s][e];


    return ti[s][e]=mx(arr[s]-func(s+1,e),arr[e]-func(s,e-1));

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	//cin>>t;
	t=1;
	while(t--){
    cin>>n;


    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    memset(ti,-1,sizeof ti);

    ll ans=func(0,n-1);

    cout<<ans<<endl;

	}
	return 0;
}
