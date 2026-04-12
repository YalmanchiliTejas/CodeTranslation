#include<bits/stdc++.h>
using namespace std ;

/// ------------------------------------------ (Debug) --------------------------------------------
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; }; sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0); sim > char dud(...);
struct debug {
#ifndef ONLINE_JUDGE
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i));}
sim, class b dor(pair < b, c > d) {ris << "(" << d.first << ", " << d.second << ")";}
sim dor(rge<c> d) {*this << "["; for (auto it = d.b; it != d.e; ++it) *this << ", " + 2 * (it == d.b) << *it; ris << "]";}
#else
sim dor(const c&) { ris; }
#endif
};
vector<char*> tokenizer(const char* args) {
	char *token = new char[111]; strcpy(token, args); token = strtok(token, ", ");
	vector<char*> v({token});
	while(token = strtok(NULL,", ")) v.push_back(token);
	return reverse(v.begin(), v.end()), v;
}
void debugg(vector<char*> args) { cerr << "\b\b "; }
template <typename Head, typename... Tail>
void debugg(vector<char*> args, Head H, Tail... T) {
	debug() << " [" << args.back() << ": " << H << "] ";
	args.pop_back(); debugg(args, T...);
}
#define harg(...) #__VA_ARGS__
#ifndef ONLINE_JUDGE
#define dbg(...) { debugg(tokenizer(harg(__VA_ARGS__, \b\t-->Line)), __VA_ARGS__, __LINE__); cerr << endl;}
#else
#define dbg(...) { }
#endif
/// ---------------------------------------------------------------------------------------------

typedef long long ll ;
typedef long double ld ;
#define F first
#define S second
#define pb push_back 
#define mp make_pair
#define vi vector <int>
#define vb vector <bool>
#define vc vector <char>
#define vll vector <ll>
#define vs vector <string>
#define pll pair < ll , ll >
#define pld pair < ld , ld >
#define pii pair < int , int >
#define vpld vector < pld >
#define vpii vector < pii >
#define vpll vector < pll >
#define vvi vector < vector < int > >
#define vvll vector < vector < ll > >
#define vvld vector < vector < ld > >
#define vvb vector < vector < bool > >
#define vvpii vector < vector < pii > >
#define all(v) (v).begin() , (v).end()
#define allrev(v) (v).rbegin() , (v).rend()
#define dist(x1 , y1 , x2 , y2) sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1))
const int MOD = 1e9 + 7 ;
const int infi = INT_MAX ;
const ll infll = LLONG_MAX ;
const int dx4[] = {0 , -1 , 0 , 1} ;
const int dy4[] = {-1 , 0 , 1 , 0} ;
const int dx8[] = {-1 , -1 , -1 , 0 , 1 , 1 , 1 , 0} ;
const int dy8[] = {-1 , 0 , 1 , 1 , 1 , 0 , -1 , -1} ;
const ld PI = 3.1415926535897932384626 ;

//-----------------------------------------------------------------------------------------------

ll power(ll a , ll b) {
	ll ans = 1 ;
	while (b > 0) {
		if (b & 1) ans *= a ;
		a *= a ;
		b >>= 1 ;
	}
	return ans ;
}

ll pow_mod (ll a , ll b , ll m) {
	ll ans = 1 ;
	while (b > 0) {
		if (b & 1) ans = (ans*a) % m ;
		a = (a*a) % m ;
		b >>= 1 ;
	}
	return ans % m ;
}

bool isprime (ll num) {
    for (ll i = 2 ; i * i <= num ; ++i) {
		if (num % i == 0) return false ;
	}
    return true;
}

ll gcd (ll a, ll b) {
    if (b == 0) return a ;
	else return gcd (b , a % b) ;
}

ll lcm (ll a, ll b) {
    return ((a / gcd(a , b)) * b) ;
}

ll cel (ll x1, ll y1) {
    if ((x1) <= 0) return (x1) / (y1) ;
    return (((x1) / (y1)) + (((x1) % (y1)) != 0)) ;
}

/**
const int N = 1e6+1 ;
vector<bool> pr(N , 1) ;
void sieve() {
	pr[0] = 0 ;
	pr[1] = 0 ;
	for (ll i = 2 ; i*i <= N ; ++i) {
		if (pr[i]) {
			for (ll j = i*i ; j <= N ; j += i) {
				pr[j] = 0 ;
			}
		}
	}
}
**/

//-----------------------------------------------------------------------------------------------

void solve (int test_case) {
	int n ;
	cin >> n ;
	vll a(n) ;
	vll suff(n+1) ;
	for (ll &i : a) cin >> i ;
	suff[n-1] = a[n-1] ;
	for (int i = n-2 ; i > -1 ; --i) {
		suff[i] = (suff[i+1] + a[i]) % MOD ;
	}
	ll ans = 0 ;
	for (int i = 0 ; i < n-1 ; ++i) {
		ans += (a[i] * suff[i+1]) % MOD ;
		ans %= MOD ;
	}
	cout << ans << "\n" ;
}

int main() {
	ios_base :: sync_with_stdio (false) ;
	cin.tie(0) ;
	cout.tie(0) ;
	int tc = 1 ;
	//cin >> tc ;
	for (int t = 1 ; t <= tc ; ++t) {
		solve (t) ;
	}
	return 0 ;
}