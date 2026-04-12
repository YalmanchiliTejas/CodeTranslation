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
const int nax=307;
using pii=pair<int,int>;

int n, m;

int tab[nax][nax];

int dp[nax*2][nax][nax];

int &daj(pii a, pii b)
{
	return dp[a.first+a.second][a.first][b.first];
}

vector <pii> mog(pii v)
{
	vector <pii> ret;
	if (v.first<n)
		ret.push_back({v.first+1, v.second});
	if (v.second<m)
		ret.push_back({v.first, v.second+1});
	return ret;
}

int licz(pii a, pii b)
{
	if (a==make_pair(n, m))
		return tab[n][m];
	
	if (daj(a, b)!=-1)
		return daj(a, b);
	
	int ret=0;
	for (pii i : mog(a))
		for (pii j : mog(b))
			ret=max(ret, licz(i, j));
	
	ret+=tab[a.first][a.second];
	if (a!=b)
		ret+=tab[b.first][b.second];
	return daj(a, b)=ret;
}

int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			scanf("%d", &tab[i][j]);
	printf("%d\n", licz({1, 1}, {1, 1}));
	return 0;
}
