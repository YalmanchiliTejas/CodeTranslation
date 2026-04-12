#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef unsigned long long int lu;
typedef vector< int > vi;
typedef vector < ll > vl;
typedef set <ll> sl;
typedef vector< vi > vvi;
typedef vector< vl > vvl;
typedef pair< int,int > ii;
typedef pair< ll,ll > il;
#define sz(a) ll((a).size())
#define test(t) ll t;cin>>t;while(t--)
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define Vi vector
#define pr pair
#define mpr make_pair
#define fi first
#define se second
#define isnum(a) (a>=48 && a<=57)
#define isS(a) (a>='a' && a<='z')
#define isU(a) (a>='A' && a<='Z')
#define toS(a) (isU(a)?a+32:a)
#define toU(a) (isS(a)?a-32:a)
#define toC(a) a&15

set <ll> s[100005];
ll d[100005];

vector<char> prime (100000+1, true);
void sieve(ll n)
{	
	//O(nloglogn) time
	prime[0] = prime[1] = false;
	for (ll i=2; i<=n; ++i)
	{
		if (prime[i])
		{
			s[i].insert(i);			
			for (ll j=2*i; j<=n; j+=i)
			{
				prime[j] = false;
				s[j].insert(i);
			}
		}
	}
}
#define forn(i,e) for(int i = 0; i < e; i++)
#define rep(i,a,b) for(i=a;i<b;i++)
#define REP(i,a,b) for(i=a;i<=b;i++)
#define reprev(i,a,b) for(i=a;i>=b;i--)

// Convex Hull Trick
typedef ll LT;
typedef pair<LT,LT> LP;
struct CHT {
  deque<LP> d;
  LT get(LT x) {
    while (sz(d) >= 2) {
      LT a = d[0].fi*x + d[0].se;
      LT b = d[1].fi*x + d[1].se;
      if (a <= b) break; // get min
      d.pop_front();
    }
    return d[0].fi*x + d[0].se;
  }
  void add(LP x) { // decreasing order of x.fi
    while (sz(d) >= 2) {
      LP y = d[sz(d) - 1];
      LP z = d[sz(d) - 2];
      if ((x.se-y.se)*(z.fi-y.fi) >= (y.fi-x.fi)*(y.se-z.se)) break; // both
      d.pop_back();
    }
    d.pb(x);
  }
};
//

#define leadzero(a) __builtin_clz(a) //count leading zeros
#define trailzero(a) __builtin_ctz(a) //count trailing zeros
#define bitcount(a) __builtin_popcount(a) // count set bits (add ll)
#define ln cout<<"\n"
#define sp cout<<" "
#define maxe(a) *max_element(a.begin(),a.end())
#define maxi(a) max_element(a.begin(),a.end())-a.begin()
#define mine(a) *min_element(a.begin(),a.end())
#define mini(a) min_element(a.begin(),a.end())-a.begin()
ll gcd(ll a, ll b) { if(b == 0) return a; return gcd(b, a % b); }
ll fastpowMOD(ll a, ll p,ll MOD){ if(p==0) return 1; ll z = fastpowMOD(a,p/2,MOD); z = (z*z)%MOD; if(p%2) z = (z*a)%MOD; return z; }
ll fastpow(ll a, ll p){ if(p==0) return 1; ll z = fastpow(a,p/2); z = (z*z); if(p%2) z = (z*a); return z; }
//CHT stands for convex hull trick
ll search1(ll a[], ll f,ll n)
{
	ll left=1;
	ll right=n+1;
	while(right-left>1)
	{
		ll mid = left + (right-left)/2;
		if(a[mid]<f)
		{
			left=mid;
		}
		else right=mid;
	}
	return a[left];
}

const ll INF = 1e18;
vector<ll> lazy;
vector<ll> tree;

void updateRange(ll node, ll start, ll end, ll l, ll r, ll val)
{
    if(lazy[node] != 0)
    { 
        // This node needs to be updated
        tree[node] += (/*end - start*/ + 1) * lazy[node];    // Update it
        if(start != end)
        {
            lazy[node*2] += lazy[node];                  // Mark child as lazy
            lazy[node*2+1] += lazy[node];                // Mark child as lazy
        }
        lazy[node] = 0;                                  // Reset it
    }
    if(start > end or start > r or end < l)              // Current segment is not within range [l, r]
        return;
    if(start >= l and end <= r)
    {
        // Segment is fully within range
        lazy[node] += (/*end - start*/ + 1) * val;
        if(start != end)
        {
            // Not leaf node
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        tree[node]+=lazy[node];
        lazy[node]=0;
        return;
    }
    ll mid = (start + end) / 2;
    updateRange(node*2, start, mid, l, r, val);        // Updating left child
    updateRange(node*2 + 1, mid + 1, end, l, r, val);   // Updating right child
    tree[node] = max(tree[node*2],tree[node*2+1]);        // Updating root with max value 
}

ll queryRange(ll node, ll start, ll end, ll l, ll r)
{
	if(lazy[node] != 0)
    {
        // This node needs to be updated
        tree[node] += (/*end - start +*/ 1) * lazy[node];            // Update it
        if(start != end)
        {
            lazy[node*2] += lazy[node];         // Mark child as lazy
            lazy[node*2+1] += lazy[node];    // Mark child as lazy
        }
        lazy[node] = 0;                 // Reset it
    }

    if(start > end or start > r or end < l)
        return -INF;         // Out of range

    if(start >= l and end <= r)             // Current segment is totally within range [l, r]
        return tree[node];
    ll mid = (start + end) / 2;
    if(r<=mid)return queryRange(node*2, start, mid, l, r);
    else if(l>=mid+1) return queryRange(node*2 + 1, mid + 1, end, l, r);
    ll p1 = queryRange(node*2, start, mid, l, r);         // Query left child
    ll p2 = queryRange(node*2 + 1, mid + 1, end, l, r); // Query right child
    //tree[node] = max(tree[node*2],tree[node*2+1]);
    return max(p1,p2);
}
const ll nax = (ll)2*1e5+10;
vector<ll> intervall[nax];
vector<pair<ll,ll> > intervalr[nax];

int main(){
	ll n,m,i,j;
	cin >> n >> m;
	/*ll base = 1;
	while(base<=n+1)base=base*2;
	tree.resize(2*base);
	lazy.resize(2*base);*/
	tree.resize(4*nax);
	lazy.resize(4*nax);
	rep(i,0,m)
	{
		ll l,r,a;
		cin >> l >> r >> a;
		intervall[l].pb(a);
		intervalr[r].pb({l,a});
	}
	ll dp[n+4];
	memset(dp,0,sizeof(dp));
	REP(i,1,n)
	{
		/*if(i==1)
		{
			ll best=0;
			for(ll x : intervall[i])best+=x;
			updateRange(1,1,n,i,i,best);
			dp[1]=best;
			continue;
		}*/
		ll best=0;
		for(ll x : intervall[i])best+=x;
		updateRange(1,0,n,0,i-1,best);
		dp[i] = queryRange(1,0,n,0,i-1);
		updateRange(1,0,n,i,i,dp[i]);
		for(pair<ll,ll> p : intervalr[i])
		{
			updateRange(1,0,n,0,p.fi-1,-p.se);
		}	
	}
	
	cout << max((ll)0,*max_element(dp,dp+n+4)) << endl;
	return 0;
}