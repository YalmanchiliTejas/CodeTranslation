#include <iostream>
#define NDEBUG
#include <bits/stdc++.h>
//#include <assert.h>

using namespace std;

#define ll long long
#define pb push_back
#define pf push_front
#define loop(i, n) for(int i = 0 ; i < n ; ++i)
#define LOOP(i, a, b) for(int i = a ; i < b ; ++i)
#define max3(a, b, c) max(a, max(b,c))
#define max4(a, b, c, d) max3(a, b, max(c, d))
#define ff first
#define ss second
#define mkp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vi>
#define vii vector<pii>
#define vvii vector<vii>
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define nmbr(c) (int)(c-'0')
#define ltr(c) (int)(c-'a')
#define INF 1e18
#define inf 1e9
#define MOD 1000000007 //check
#define _69e27 ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

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
#ifndef ONLINE_JUDGE
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

int d;
string k;
ll dp[10005][105][2];

ll ways(int i, int sum, int f)
{
	if(i == sz(k) && sum == 0) return 1;
	if(i == sz(k)) return 0;
	ll &ans = dp[i][sum][f];
	if(ans != -1) return ans;
	ans = 0;
	if(f) loop(j, 10)
	{
		ans += ways(i+1, (sum+j)%d, 1);
		ans %= MOD;
	}
	else loop(j, nmbr(k[i])+1)
	{
		if(j != nmbr(k[i])) ans += ways(i+1, (sum+j)%d, 1);
		else ans += ways(i+1, (sum+j)%d, 0);
		ans %= MOD;
	}
	return ans%MOD;
}
int main() {
	_69e27;
	memset(dp, -1, sizeof(dp));
	cin >> k >> d;
	assert(d == 4);
	debug() << imie(k);
	cout << (ways(0, 0, 0)-1+MOD)%MOD;
	return 0;
}