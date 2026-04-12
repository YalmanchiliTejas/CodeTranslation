#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace __gnu_pbds;
using namespace __gnu_cxx;

#define  FIO        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define  IN         freopen("input.txt","r",stdin);
#define  OUT        freopen("output.txt","w",stdout);
#define  debug(x)   cout<< #x << " --> " << x << "\n";
#define  NL         printf("\n");
#define  case(x)    printf("Case %lld: ",x);
#define  readI(x)   scanf("%d",&x);
#define  readL(x)   scanf("%lld",&x);
#define  writeI(x)  printf("%d",x);
#define  writeL(X)  printf("%lld",x);
#define  all(v)     v.begin(),v.end()

#define  ll     long long
#define  ld     long double
#define  pb     push_back
#define  pii    pair< int,int >
#define  pll    pair< ll,ll >
#define  vii    vector< int >
#define  vll    vector< ll >
#define  vss    vector< string >
#define  vdd    vector< double >
#define  vpi    vector< pii >
#define  vpl    vector< pll >
#define  vvi    vector< vii >
#define  vvl    vector< vll >
#define  PQ     priority_queue
#define  ff     first
#define  ss     second
#define  MX     100005
#define  mod    1000000007
#define  INF    10000000000000000
#define  EPS    1e-12

/* Special functions:
		find_by_order(k) --> returns iterator to the kth largest element counting from 0
		order_of_key(val) --> returns the number of items in a set that are strictly smaller than our item
*/

typedef tree<
ll,					// type long long
null_type,
less<ll>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

struct compare
{
    bool operator() (ll a, ll b)
    {
        return a>b;
    }
};

const ll p1=131,p2=137;
const ll mod1=1000000009;
const ll mod2=1000000007;

bool marked[MX];
vll primes;


inline ll bigMod(ll x, ll n)
{
    ll res=1;
    while(n){
        if(n&1) res=(res*x)%mod;
        x=(x*x)%mod;
        n=n>>1;
    }
    return res;
}

void sieve()
{
    marked[0]=marked[1]=true;
    for(ll i=2;i*i<MX;i++){
        if(marked[i]==false){
            for(ll j=i*i;j<MX;j+=i){
                marked[j]=true;
            }
        }
    }

    for(ll i=2;i<MX;i++)
        if(!marked[i]){
            primes.push_back(i);
        }
}

vpl primeFactors(ll N)
{
	vpl factors;
	ll pf_id=0,pf=primes[pf_id];
	while(pf*pf<=N){
        ll cnt=0;
		while(N%pf==0) N/=pf,cnt++;
        if(cnt) factors.push_back({pf,cnt});

		pf=primes[++pf_id];
	}

	if(N!=1) factors.push_back({N,1});
    return factors;
}


struct pair_hash {
    template <class T1, class T2>
    size_t operator () (const pair<T1,T2> &p) const {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);

        // Mainly for demonstration purposes, i.e. works but is overly simple
        // In the real world, use sth. like boost.hash_combine
        return h1 ^ h2;
    }
};

struct chash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}
	// Note: when casting y to unsigned x, x will be least unsigned int congruent
	// to y mod 2^64.
	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};
gp_hash_table<ll, ll, chash>var;


                        /**---------End of Template---------**/


struct BIT{
    vll bit1;
    vll bit2;
    ll N;

    BIT(ll n)
    {
        N=n;
        bit1.assign(n+1,0);
        bit2.assign(n+1,0);
    }

    BIT(vll v) : BIT(v.size())
    {
        for(ll i=0;i<v.size();i++)
            add(i+1, i+1, v[i]);
    }

    ll sum1(ll idx)
    {
        ll ret=0;
        for (; idx > 0; idx -= idx & -idx)
            ret += bit1[idx];
        return ret;
    }

    ll sum2(ll idx)
    {
        ll ret=0;
        for (; idx > 0; idx -= idx & -idx)
            ret += bit2[idx];
        return ret;
    }

    ll prefix_sum(ll idx)
    {
        return sum1(idx)*idx -  sum2(idx);
    }

    ll sum(ll l, ll r)
    {
        return prefix_sum(r) - prefix_sum(l-1);
    }

    void add1(ll idx, ll val)
    {
        for (; idx <= N; idx += idx & -idx)
            bit1[idx] += val;
    }

    void add2(ll idx, ll val)
    {
        for (; idx <= N; idx += idx & -idx)
            bit2[idx] += val;
    }

    void add(ll l, ll r, ll val)
    {
        add1(l,val);
        add1(r+1,-val);
        add2(l,val*(l-1));
        add2(r+1,-val*r);
    }
};


int main()
{

    FIO;
//    IN;
//    OUT;

    ordered_set ost;


    ll N;
    cin>> N;
    vll v(N);
    for(ll i=0;i<N;i++) cin>> v[i],ost.insert(v[i]);
    for(ll i=0;i<N;i++) v[i]=ost.order_of_key(v[i])+1;

    ll sz=ost.size()+10;
    BIT bit(sz);
    ll res=0;
    for(ll i=N-1;i>=0;i--){
        ll sum=bit.sum(v[i]+1,sz);
        if(!sum) bit.add(v[i],v[i],1),res++;
        else{
            ll low=v[i]+1,hi=sz;
            ll pos=-1;
            while(low<=hi){
                ll mid=(low+hi)/2;
                sum=bit.sum(low,mid);
                if(sum) pos=mid,hi=mid-1;
                else low=mid+1;
            }
            bit.add(pos,pos,-1);
            bit.add(v[i],v[i],1);
        }
    }

    cout<< res;
}

