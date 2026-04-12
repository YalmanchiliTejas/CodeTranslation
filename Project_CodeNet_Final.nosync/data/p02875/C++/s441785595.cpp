//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

#define shandom_ruffle random_shuffle

using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
const int nax=10*1000*1007;
const ll mod=998244353;

int n;

ll sil[nax];
ll odw[nax];
ll pot[nax];

ll wyn;

ll dziel(ll a, ll b)
{
	ll wyk=mod-2;
	while(wyk)
	{
		if (wyk&1)
			a=(a*b)%mod;
		b=(b*b)%mod;
		wyk>>=1;
	}
	return a;
}

ll kom(int a, int b)
{
	if (b>a || b<0)
		return 0;
	return sil[a]*odw[b]%mod*odw[a-b]%mod;
}

ll choc[nax];

int main()
{
	scanf("%d", &n);
	sil[0]=odw[0]=1;
	for (int i=1; i<=n; i++)
		sil[i]=(sil[i-1]*i)%mod;
	odw[n]=dziel(1, sil[n]);
	for (int i=n-1; i; i--)
		odw[i]=(odw[i+1]*(i+1))%mod;
	pot[0]=1;
	for (int i=1; i<=n; i++)
		pot[i]=(pot[i-1]*2)%mod;
	
	for (int i=n/2; i>=0; i--)
	{
		choc[i]=kom(n/2, i)*pot[n/2-i]%mod;
		choc[i]+=choc[i+1];
		choc[i]%=mod;
	}
	ll odj=1;
	for (int i=1; i<=n; i++)
		odj=(odj*3)%mod;
	for (int i=0; i<=n/2; i++)
	{
		ll jed=pot[i]*kom(n/2, i)%mod;
		wyn=(wyn+jed*choc[i+1]%mod)%mod;
	}
	
	//~ for (int i=(n+1)/2; i<=n; i++)
	//~ {
		//~ ll ter=sil[n]*odw[i]%mod*odw[n-i]%mod*pot[n-i]%mod;
		//~ wyn=(wyn+ter)%mod;
	//~ }
	
	debug() << odj << " " << wyn;
	printf("%lld\n", (odj-wyn*2%mod+mod)%mod);
	return 0;
}
