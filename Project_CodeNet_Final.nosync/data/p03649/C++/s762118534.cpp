#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long int
#define ordered_set tree < ll ,  null_type ,  less<ll> ,  rb_tree_tag ,  tree_order_statistics_node_update >
//added two more functions to set
//(1)*(set.find_by_order(k))[kth element in the sorted set] 
//(2)set.order_of_key(k)[count of elements strictly less than k]
typedef vector< int > vi;
typedef vector< ll > lvi;
typedef vector< vi > vvi;
typedef vector< lvi > lvvi;
typedef pair< int,int > ii;
typedef pair< ll,ll > lii;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(auto i = (c).begin(); i != (c).end(); i++)//remember i is an iterator
#define present(c,x) ((c).find(x) != (c).end())//for sets,maps,multimaps
#define cpresent(c,x) (find(all(c),x) != (c).end())//for vectors
#define tc(t) int (t); cin>>(t);while((t)--)
#define ff first
#define ss second
#define mp make_pair
#define ld long double
#define ull unsigned long long int
#define mod 1000000007
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);	
	ll n;
	cin>>n;
	lvi a(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(all(a));
	ll ans=0;
	while(1)
	{
		lvi op(n+2,0);
		ll tt=0;
		for (int i = 0; i < n; ++i)
		{
			if(a[i]<n) continue;
			ll k=a[i]-n+1;
			ll tmp=ceil((ld)k/n);
			a[i]=a[i]-tmp*n;
			tt+=tmp;
			op[i]=tmp;
		}
		if(tt==0) break;
		ans+=tt;
		for(int i=0;i<n;i++)
		{
			a[i]=a[i]+tt-op[i];
		}
		sort(all(a));
	}
	cout<<ans<<endl;
	return 0;
}