#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
#define time_taken_start int begtime = clock();
#define time_taken_end int endtime = clock(); \
cerr << "\n\n" << "Time elapsed: " << \
(endtime - begtime)*1000/CLOCKS_PER_SEC << " ms\n\n"; \
return 0;
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define mod 998244353
#define inf 100000000000000007
#define eps 0.000000000001
#define pi acosl(-1)
#define pdd pair<ld,ld>
#define pll pair<ll,ll>
#define ff first
#define ss second
#define vpl vector<pll>
#define vll vector<ll>
#define mseti multiset <ll>
#define msetd multiset <ll,greater<ll>>
#define pb push_back
#define pf push_front
#define lb lower_bound
#define ub upper_bound 
#define stp fixed<<setprecision(20)
#define endl '\n'
ll b[100009];
void solve()
{
    ll n,m,x;
    cin>>n>>x>>m;ll ans=0;
    ll i=1;
    for(;i<=n;i++)
    {
    	ans+=x;
    	b[x]=1;
    	x*=x;
    	x%=m;
    	if(b[x]==1)
    		break;
    	if(x==0)
    	{
    		cout<<ans;
    		return;
    	}
    }
    ll ans1=0;
    if(i<n)
    {
    	ll z=x;
    	for(ll j=0;j<=100000;j++)
    	{
    		b[j]=0;
    	}
    	ll c=1,cnt=n-i;
    	for(;c<=cnt;c++)
    	{
    		ans1+=x;
    		b[x]=1;
    		x*=x;
    		x%=m;
    		if(b[x]==1)
    			break;
    		if(x==0)
    		{
    			cout<<ans+ans1;
    			return;
    		}
    	}
    	if(c>=cnt)
    	{
    		cout<<ans+ans1;
    		return;
    	}
    	ll d=cnt/c;
    	ans1*=d;
    	d*=c;
    	d=cnt-d;
    	for(ll j=0;j<d;j++)
    	{
    		ans1+=x;
    		x*=x;
    		x%=m;
    	}
    }
    cout<<ans+ans1;
}
int main()
{
    FAST
    #ifdef ayk_16
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
    #endif
    time_taken_start
    ll t=1;
    //cin>>t;
    for(ll i=0;i<t;i++)
    {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    time_taken_end
}