#include <bits/stdc++.h>

using namespace std;

using uint = unsigned int;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_p(x) cerr<<#x": "<<(x).first<<' '<<(x).second<<endl
#define dbg_v(x, n) {cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<(x)[_]<<' ';cerr<<endl;}
#define all(v) v.begin(), v.end()
#define fi first
#define se second
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}
 
template<typename T1, typename T2>
ostream& operator <<(ostream &out, const pair<T1, T2> &item) {
	out << '(' << item.first << ", " << item.second << ')';
	return out;
}
 
template <typename T>
ostream& operator <<(ostream &out, const vector<T>& v) {
	for(const auto &item : v) out << item << ' ';
	return out;
}

string s;
ll k;

ll comb(ll n, ll k)
{
	if (k == 0)
		return 1;
	if (k == 1)
		return n;
	if (k == 2)
		return n*(n-1)/2;
	if (k == 3)
		return n*(n-1)*(n-2)/6;

	assert(false);
}

ll put(ll x, ll k)
{
	ll ans = 1;
	for (ll i=1; i<=k; i++)
		ans *= x;
	return ans;
}

ll solve(const string &s, ll k, ll start)
{
	ll rest = s.size() - start - 1;
	if (k == 0)
		return 1;

	if(start == s.size())
		return 0;

	ll x = s[start] - '0';
	if (x == 0)
		return solve(s, k, start+1);

	ll zero = 0, plus = 0;
	plus = (x - 1) * comb(rest, k-1) * put(9, k-1); 
	if (k <= rest)
		zero = comb(rest, k) * put(9, k);

	return plus + zero + solve(s, k-1, start+1);
}

int main()
{
	ios_base::sync_with_stdio(false);

	cin>>s;
	cin>>k;

	if (k > s.size())
	{
		cout<<0;
	}
	else
	{
		cout<<solve(s, k, 0);
	}
	cout<<'\n';
	return 0;
}