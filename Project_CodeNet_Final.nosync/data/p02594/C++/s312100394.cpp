#include "bits/stdc++.h"
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
//adds two more functions to set
//(1)*(set.find_by_order(k))[kth element in the sorted set]
//(2)set.order_of_key(k)[count of elements strictly less than k]
#define ll long long
#define ld long double
#define vv vector
#define pp pair
#define ff first
#define ss second
#define all(v) v.begin(), v.end()
typedef pair<ll, ll> pll;
typedef vv<bool> vbool;
typedef vv<ll> vll;
typedef vv<ld> vld;
typedef vv<pll> vpll;
#ifdef LOCAL
#include "prettyprint.hpp"
#define LG(args...)                           \
{                                             \
	string _s = #args;                        \
	replace(_s.begin(), _s.end(), ',', ' ');  \
	stringstream _ss(_s);                     \
	err(istream_iterator<string>(_ss), args); \
	cerr << endl;                             \
}
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << "(" << *it << ":" << a << ") ";
	err(++it, args...);
}
#define fastio
#else
#define LG(...)
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define endl "\n"
#endif
//:::::::::::::::::::::::::::::::::::::::::::::
const ll INF = 9e18;
const ll MOD = 1e9 + 7;

int main(){
	fastio;
	ll n;
	cin>>n;
	string s;
	if(n >=30)
		s ="Yes";
	else
		s ="No";
	cout<<s<<endl;
}