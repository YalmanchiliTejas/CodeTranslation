#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <iterator>
#include <utility>
#include <iomanip>
#include <stack>
#include<bitset>
#include <cmath>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 
priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > >pq;
vector<ll>adj[1000005];
ll expo(ll b,ll n,ll m)
{
 ll r,p;
	p=1;
	 b=b%m;
	while(n>0)
	{ 
		r=n%2;
		if(r==1)
		   p=((p)*(b))%m;
		b=((b)*(b))%m; 
		n=n/2;		
	}
 return (p%m);
}
ll divide1(ll a,ll b,ll m)
	{ ll r,p,n;
			p=a%m;
				n=m-2;
				while(n>0){
						 r=n%2;
						if(r==1)
							p=((p%m)*(b%m))%m;
						b=((b%m)*(b%m))%m; 
						n=n/2;	
					}
	return (p%m); }
int main(int argc, char const *argv[])
{	ios_base::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	ll x;
	cin>>x;
	cout<<(x>=30?"Yes":"No")<<endl;
	return 0;
}
