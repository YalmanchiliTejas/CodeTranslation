/************************Code by Hardik Aggarwal!!!!***********************************/

#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL); 

#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define mp make_pair
#define pu push
#define pp pop_back
#define in insert
#define ld long double
#define endl '\n'
#define debug cout << "Hold right there sparky.....\n";
#define forn(low,high,i) for(i=low;i<high;i++)
#define forrev(high,low,i) for(i = high; i>= low;i--)
#define trace(x) cerr << #x << ": " << x << " " << endl;

typedef long long int ll;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
const ll mod =1e9+7;
ll dp[3005][3005][2];
ll a[3005];
ll solve(ll l,ll r,ll p)
{	

	ll &res = dp[l][r][p];
	if(res!=-1)
		return res;
	if(l==r)
		if(p==1)
			return res=a[l];
		else
			return res=-a[l];

	if(p==1)
	{
		res=max(solve(l+1,r,!p)+a[l],solve(l,r-1,!p)+a[r]);
	}
	else
	{
		res=min(solve(l+1,r,!p)-a[l],solve(l,r-1,!p)-a[r]);
	}

	return res; 

}	

int main()
{	
	IOS
	ll n;
	cin>>n;
	
	memset(dp,-1,sizeof(dp));
	for(ll i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(n==1)
	{
		cout<<a[0];
		return 0;
	}

	ll ans=solve(0,n-1,1);

	cout<<ans<<endl;
}
    
 
    
    
