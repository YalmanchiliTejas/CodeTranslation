#include<bits/stdc++.h>
#define ll  long long int
#define db long double 
#define ull unsigned long long int
// #define mp make_pair
#define F first
#define S second
#define pb push_back
#define rep(i,a,b)  for(ll i=a;i<=b;i++)
#define all(a) a.begin(),a.end()
#define Nmax 1000005
// #define INF 10000000000000
#define MOD 1000000007
#define MAXN 200005
 
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // compute();
    int tests=1;
    // cin>>tests;    
    while(tests--)
    {
    	ll i,j,n,m,x;
    	cin>>n>>x>>m;
    	x%=m;
    	map<ll,ll>mpp;
    	mpp[x]=1;
    	vector<ll>v;
    	v.pb(0);
    	v.pb(x);
    	ll period=-1;
    	ll cnt=1;
    	while(true)
    	{
    		x*=x;
    		x%=m;
    		// cout<<"-->"<<x<<"\n";
    		if(mpp.find(x)!=mpp.end())
    		{
    			period=v.size()-mpp[x];
    			break;
    		}
    		else
    		{
    			mpp[x]=v.size();
    			v.pb(x);
    		}
    		cnt++;
    		if(cnt==n) break;
    	}

    	// cout<<period<<"\n";

    	if(period==-1)
    	{
    		ll ans=0;
    		for(auto x:v) {ans+=x;}
    		cout<<ans;
    		return 0;
    	}

    	vector<ll>c;

    	cnt=0;
    	ll persum=0;
    	while(cnt<period)
    	{
    		c.pb(v.back());
    		persum+=v.back();
    		// persum%=m;
    		v.pop_back();
    		cnt++;
    	}
    	ll ans=0;
    	n-=v.size()-1;
    	for(auto x:v) {ans+=x;}

    	ans+=((n/period)*(persum));
    	// ans%=m;
    	n%=period;
    	reverse(all(c));
    	rep(i,0,n-1)
    	{
    		ans+=c[i];
    		// ans%=m;
    	}

    	cout<<ans;

    }

    return 0;
}
    