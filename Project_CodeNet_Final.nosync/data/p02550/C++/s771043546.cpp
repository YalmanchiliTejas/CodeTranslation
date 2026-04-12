#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>  
using namespace std;
using namespace __gnu_pbds;

#define int long long int
#define float long double
#define pb push_back
#define fi first
#define se second
#define vii vector<int>
#define pii pair<int,int>
#define vpii vector<pii>
#define pq priority_queue<int>
#define test int tcase; cin>>tcase; for(int tc = 1; tc <= tcase; tc++)
#define inp(a,n,f) int a[n+f];for(int hh=f;hh<n+f;hh++)cin>>a[hh];
#define prdec(k) cout<<fixed<<setprecision(k);
#define mem(a,k) memset(a,k,sizeof(a))
#define ub upper_bound
#define lb lower_bound
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define mii map<int,int>
#define all(v) v.begin(),v.end()
#define mod (int)(1e9+7)
#define inf LLONG_MAX
int exp(int x,int y){int res=1;x=x%mod;while(y>0){if(y&1)res=(res*x)%mod;y=y>>1;x=(x*x)%mod;}return res;}
int modinv(int x){return exp(x,mod-2);}


signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,x,m,idx=-1,res=-1,idx2=-1,ans=0,sum=0;
	cin>>n>>x>>m;
	vector<int> v;
	set<int> s;
	s.insert(x);
	v.pb(x);
	for(int i=2;i<=n;i++)
	{
		int val=(x*x)%m;
		if(s.count(val)>0)
		{
			res=val;
			idx=i;
			break;
		}
		s.insert(val);
		v.pb(val);
		x=val;
	}
	if(idx==-1)
	{
		for(int x:v)
			ans+=x;
		cout<<ans;
		return 0;
	}
	for(int i=0;i<idx;i++)
	{
		if(v[i]==res)
		{
			idx2=i;
			break;
		}
	}
	for(int i=0;i<idx2;i++)
		ans+=v[i];
	n-=idx2;
	int k=(int)v.size() - idx2;
	for(int i=idx2;i<idx;i++)
		sum+=v[i];
	ans+=(n/k)*sum;
	for(int i=idx2;i<idx2+(n%k);i++)
		ans+=v[i];
	cout<<ans;
	return 0;
}