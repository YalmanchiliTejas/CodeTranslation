#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <chrono>

using namespace __gnu_pbds;
using namespace std;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// order_of_key (val): returns the no. of values less than val
// find_by_order (k): returns the kth largest element.(0-based)

#define ll long long int
#define ld long double
#define ff first
#define ss second
#define pb push_back
#define pi pair<ll,ll>
#define pii pair<ll,pi >
#define ppi pair<pi,ll>
#define ppp pair<pi,pi >
#define ex(str,a,b) str.substr((int)(a),min((int)str.size()-a,(int)(b-a+1))) 
#define all(X) X.begin(),X.end()
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// for pair comparison function(ascending order) use return (i1.ff < i2.ff);

/* string operations :
   str.substr (x,y) : returns a substring str[x],str[x+1],...str[x+y-1]
   __builtin_popcount(n) : no. of set bits in n.
*/

const int M = (1<<20)+5;
const int md = 1e9+7;

priority_queue<pi,vector<pi >,greater<pi > > pq;

ll pwr(ll a,ll n,ll m)
{
	ll p=1;
	while(n>0)
	{
		if(n%2==1)
			p=(p*a)%m;
		a=(a*a)%m;
		n=n/2;
	}
	return p;
}

ll ax[M],ay[M];
set<pii > px,py,nx,ny;
bool mrk[M];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll n,i,x,y,d,cost = 0;

	cin >> n;
	for(i=1;i<=n;++i)
	{
		cin >> x >> y;
		px.insert(pii(x,pi(y,i)));
		nx.insert(pii(-1*x,pi(y,i)));
		py.insert(pii(y,pi(x,i)));
		ny.insert(pii(-1*y,pi(x,i)));
		ax[i] = x;
		ay[i] = y;
	}

	pq.push(pi(0,1));

	while(!pq.empty())
	{
		pi ed = pq.top();
		pq.pop();
		d = ed.ff;
		i = ed.ss;
		if(mrk[i])
			continue;
		mrk[i] = 1;
		cost += d;
		px.erase(pii(ax[i],pi(ay[i],i)));
		nx.erase(pii(-1*ax[i],pi(ay[i],i)));
		py.erase(pii(ay[i],pi(ax[i],i)));
		ny.erase(pii(-1*ay[i],pi(ax[i],i)));

		auto gx = px.upper_bound(pii(ax[i],pi(-1,-1)));
		if(gx != px.end())
			pq.push(pi(min(abs((*gx).ff-ax[i]),abs((*gx).ss.ff-ay[i])),(*gx).ss.ss));
		gx = nx.upper_bound(pii(-1*ax[i],pi(-1,-1)));
		if(gx != nx.end())
			pq.push(pi(min(abs(-1*((*gx).ff)-ax[i]),abs((*gx).ss.ff-ay[i])),(*gx).ss.ss));
		gx = py.upper_bound(pii(ay[i],pi(-1,-1)));
		if(gx != py.end())
			pq.push(pi(min(abs((*gx).ff-ay[i]),abs((*gx).ss.ff-ax[i])),(*gx).ss.ss));
		gx = ny.upper_bound(pii(-1*ay[i],pi(-1,-1)));
		if(gx != ny.end())
			pq.push(pi(min(abs((*gx).ss.ff-ax[i]),abs(-1*((*gx).ff)-ay[i])),(*gx).ss.ss));
	}

	cout << cost << "\n";
}