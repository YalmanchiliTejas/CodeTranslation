#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mii map<int,int>
#define mll map<ll,ll>
#define all(x) (x).begin(),(x).end()
#define S(x) (int)(x).size()
#define L(x) (int)(x).length()
#define debug(x) cerr << #x << " " << x << endl;
#define debug_p(x) cerr << #x << " [" << x.fi << " " << x.se << "]"<<endl;
#define debug_v(x) {cerr << #x << " "; for (auto ioi : x) cerr << ioi << " "; cerr << endl;}
#define debug_vp(x) {cerr << #x << " "; for (auto ioi : x) cerr << '[' << ioi.fi << " " << ioi.se << ']'; cerr << endl;}
#define debug_v_v(x) {cerr << #x << "/*\n"; for (auto ioi : x) { for (auto ioi2 : ioi) cerr << ioi2 << " "; cerr << '\n';} cerr << "*/" << #x << endl;}
#define gen_clock(x) ll x = clock(); cerr << "Clock " << #x << " created" << endl;
#define check_clock(x) cerr << "Time spent in " << #x << ": " << (double)(clock() - x)/CLOCKS_PER_SEC << endl; x = clock();
#define reset_clock(x) x = clock()
 
const int mod = 1e9+7;
const ll infl = 0x3f3f3f3f3f3f3f3fLL;
const int infi = 0x3f3f3f3f;
ll power(ll x, ll y, ll p)  
{  
    int res = 1;     // Initialize result  
  
    x = x % p; // Update x if it is more than or  
                // equal to p 
   
    if (x == 0) return 0; // In case x is divisible by p; 
  
    while (y > 0)  
    {  
        // If y is odd, multiply x with result  
        if (y & 1)  
            res = (res*x) % p;  
  
        // y must be even now  
        y = y>>1; // y = y/2  
        x = (x*x) % p;  
    }  
    return res;  
} 
void solve()
{
	ll n,x,p;
	cin>>n>>x>>p;
	ll it=0;
	vector<int>a(1e5+1,0),pos(1e5+1,0);
	map<ll,ll>mp;
	a[0]=x;
	mp[x]++;
	pos[x]=0;
	it++;
	x=power(x,2,p);
	while((mp[x]==0)&&(it<n))
	{
	a[it]=x;
	mp[x]++;
	pos[x]=it;
	it++;
	x=power(x,2,p);
	}
	//for(ll i=0;i<it;i++)
	//cout<<a[i]<<endl;
	if(it==n)
	{
		ll ans=0;
		for(ll i=0;i<n;i++)
		{
			ans+=a[i];
		}
		cout<<ans<<endl;
	}
	else
	{
		ll y=pos[x];
		ll z=it-y;
		ll ans=0;
		for(ll i=0;i<it;i++)
		{
			ans+=a[i];
		}
		//cout<<ans<<endl;
		n=n-it;
		ll val=0;
		for(ll i=y;i<it;i++)
		{
			val+=a[i];
		}
		ans+=val*(n/z);
		for(ll i=y;i<y+n%z;i++)
		ans+=a[i];
		cout<<ans<<endl;
	}
}
 
int main()
{
	IOS
	int t=1;
	//cin>>t;
	while(t--)
	{
		solve();
	}
}
