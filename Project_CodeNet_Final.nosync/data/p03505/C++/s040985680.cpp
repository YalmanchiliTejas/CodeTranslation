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
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll k,a,b; cin>>k>>a>>b;
	if(a<=b)
	{
		if(a>=k)
		{
			cout<<1<<'\n';
		}
		else
		{
			cout<<-1<<'\n';
		}
		return 0;
	}
	ll tmp = 2LL*((max(k-a,0LL)+a-b-1)/(a-b))+1;
	ll tmp2 = 2LL*((k+a-b-1)/(a-b));
	cout<<min(tmp,tmp2)<<'\n';
}