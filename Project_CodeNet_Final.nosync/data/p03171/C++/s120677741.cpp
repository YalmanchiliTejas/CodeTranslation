/**
 *COYG, 14 FA Cups we are back baby
 */
#include <bits/stdc++.h>
using namespace std;
#define mod 		1000000007
#define ll 		long long
#define mp 		make_pair
#define pb 		push_back
#define forn(i,n) 	for(int i=0;i<n;i++)
#define for1(i,n) 	for(int i=1;i<n;i++)
#define ford(i,n) 	for(int i=n-1;i>=0;i--)
#define vi 		vector<int>
#define vl 		vector<ll>
#define pii 		pair<int,int>
#define pll 		pair<ll,ll>
#define vpi 		vector<pair<int,int> >
#define vpl		vector<pair<ll,ll> >
#define vvi 		vector<vector<int> >
#define vvl 		vector<vector<ll> >
#define ull 		unsigned long long
#define IOS 		ios_base::sync_with_stdio(false);
#define PI 		3.1415926535897932384626
#define ff 		first
#define ss 		second
#define char2Int(c) 	(c-'0')
#define FOREACH(i,t) 	for (auto i=t.begin(); i!=t.end(); i++)
#define clr(a,x) 	memset(a,x,sizeof(a)) //set elements of array to some value
#define all(x)		(x).begin(),(x).end()//cout<<"Case #"<<zzz<<": ";
#define plll pair<ll,pll >
ll n;vl a;ll flag;
ll dp[3001][3001];
ll getans(ll l,ll r)
{
    if(l>r)return 0;
    if(dp[l][r]!=-1)return dp[l][r];
    ll len=r-l+1;ll ret;
    if((len&1)^flag)
    {
        ret=max(a[l]+getans(l+1,r),a[r]+getans(l,r-1));
    }
    else
    {
        ret=min(-a[l]+getans(l+1,r),-a[r]+getans(l,r-1));
    }
    dp[l][r]=ret;
    return ret;
}
void solve()
{
    cin>>n;a.resize(n);forn(i,n)cin>>a[i];
    if(n&1)flag=0;else flag=1;
    for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)dp[i][j]=-1;
    cout<<getans(0,n-1)<<endl;
}
int main()
{
    IOS;cin.tie(NULL);
    ll zz;zz=1;
    //cin>>zz;
    for(int zzz=1;zzz<=zz;zzz++)
    {
        solve();
    }
    return 0;
}
