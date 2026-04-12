#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 100000000000
#define mod 1000000007
#define pll pair<long,long>
#define se second
#define fi first
#define pb push_back
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
typedef tree<pll,null_type,less<pll>,rb_tree_tag,tree_order_statistics_node_update>pllordered_set;


int main()
{
			ios_base::sync_with_stdio(false);
			cin.tie(NULL);
			ll n,m;
			cin>>n>>m;
			map<pair<ll,ll>,ll> edge;
			for(ll i=0;i<m;i++)
			{
				ll u,v;
				cin>>u>>v;
				edge[{u,v}]=1;
				edge[{v,u}]=1;
			}
			vector<ll> v1;
			for(ll i=1;i<=n;i++)
			{
				v1.pb(i);
			}
			ll cnt=0;
			do
			{
				ll c1=1;
				for(ll i=1;i<=n;i++)
				{
					if(edge[{v1[i],v1[i-1]}]==1)
						c1++;
				}
				if(c1==n)
					cnt++;
			}while(next_permutation(v1.begin()+1,v1.end()));
			cout<<cnt;
			
			
			
}
