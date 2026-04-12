#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

bool d[11][11];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m;cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int u, v;
		cin>>u>>v;
		u--; v--;
		d[u][v]=1;
		d[v][u]=1;
	}
	vi perm(n);
	for(int i =0;i<n;i++)
	{
		perm[i]=i;
	}
	int ans = 0;

	do
	{
		bool pos=1;
		for(int i = 0; i < n - 1; i++)
		{
			if(!d[perm[i]][perm[i+1]])
			{
				pos=0;
				break;
			}
		}
		if(pos) ans++;
	}while(next_permutation(perm.begin()+1,perm.end()));
	cout<<ans<<'\n';
}
