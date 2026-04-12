//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
//~ #pragma GCC target ("avx2")
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
const int nax=1000*1007;
const int n1=(1<<18);
const ll mod=1000*1000*1000+7;
const ll inf=1e18;

int n, m;

int l[nax];
int r[nax];
ll w[nax];

vi kt[nax];

ll dp[nax];

ll narz[nax];
ll pod[nax];

ll daj(int v)
{
	return pod[v]+narz[v];
}

void upd(int v)
{
	pod[v]=max(daj(2*v), daj(2*v+1));
}

void pisz(int v, int a, int b, int graa, int grab, ll w)
{
	if (a>=graa && b<=grab)
	{
		narz[v]+=w;
		return;
	}
	if (a>grab || b<graa)
	{
		return;
	}
	pisz((v<<1), a, (a+b)>>1, graa, grab, w);
	pisz((v<<1)^1, (a+b+2)>>1, b, graa, grab, w);
	upd(v);
}

ll czyt(int v, int a, int b, int graa, int grab)
{
	if (a>=graa && b<=grab)
	{
		return daj(v);
	}
	if (a>grab || b<graa)
	{
		return -inf;
	}
	return max(
	czyt((v<<1), a, (a+b)>>1, graa, grab),
	czyt((v<<1)^1, (a+b+2)>>1, b, graa, grab)
	)+narz[v];
}

int main()
{
	scanf("%d%d", &n, &m);
	n+=2;
	for (int i=1; i<=m; i++)
	{
		scanf("%d%d%lld", &l[i], &r[i], &w[i]);
		l[i]++;
		r[i]++;
		kt[r[i]].push_back(i);
	}
	for (int i=2; i<=n; i++)
	{
		dp[i]=czyt(1, 1, n1, 1, i-1);
		pisz(1, 1, n1, i, i, dp[i]);
		for (int j : kt[i])
			pisz(1, 1, n1, l[j], r[j], w[j]);
		//~ debug() << i << " " << dp[i];
	}
	printf("%lld\n", dp[n]);
	return 0;
}
