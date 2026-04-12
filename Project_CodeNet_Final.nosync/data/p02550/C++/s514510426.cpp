#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;
#define pival 3.14159265358979323846264338327950L
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pqq priority_queue
#define all(a) a.begin(), a.end()
#define sz(a) (ll)(a.size())
#define endl '\n'
#define DEBUG
#ifdef DEBUG
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1)
    {
        cerr << name << " = " << arg1 << endl;
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args)
    {
        const char* comma = strchr(names + 1, ','); cerr.write(names, comma - names) << " = " << arg1 << " || ";
        __f(comma+1, args...);
    }
#else
#define debug(...)
#endif
template <class Ch, class Tr, class Container>
basic_ostream <Ch, Tr> & operator << (basic_ostream <Ch, Tr> & os, Container const& x) {
    os << "{ ";
    for(auto& y : x) os << y << " ; ";
    return os << "}";
}
template <class X, class Y>
ostream & operator << (ostream & os, pair <X, Y> const& p) {
    return os << "[ " << p.first << ", " << p.second << "]" ;
}
ll power(ll x, ll y, ll p)
{ 
    ll res = 1;  
    x = x % p;
    while (y > 0) { 
        if (y & 1) res = (res * x) % p; 
        y = y >> 1;
        x = (x * x) % p;   
    } 
    return res; 
}
ll gcdExtended(ll a, ll b, ll *x, ll *y); 
  
// Function to find modulo inverse of b. It returns 
// -1 when inverse doesn't 
ll modInverse(ll b, ll m) 
{ 
    ll x, y; // used in extended GCD algorithm 
    ll g = gcdExtended(b, m, &x, &y); 
  
    // Return -1 if b and m are not co-prime 
    if (g != 1) 
        return -1; 
  
    // m is added to handle negative x 
    return (x%m + m) % m; 
} 
  
// Function to compute a/b under modlo m 
ll modDivide(ll a, ll b, ll m) 
{ 
    a = a % m; 
    ll inv = modInverse(b, m); 
    if (inv == -1) return 0;
    else return (inv * a) % m;
} 
  
// C function for extended Euclidean Algorithm (used to 
// find modular inverse. 
ll gcdExtended(ll a, ll b, ll *x, ll *y) 
{ 
    // Base Case 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    ll x1, y1; // To store results of recursive call 
    ll gcd = gcdExtended(b%a, a, &x1, &y1); 
  
    // Update x and y using results of recursive 
    // call 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
} 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll n, x, m;
 	cin >> n >> x >> m;
 	map <ll, ll> rep;
 	map <ll, ll> pref;
 	ll pos = 1;
 	pref[0] = 0;
 	ll ans = 0;
 	while (1) {
 		ll temp = (x % m);
 		if (rep[x] != 0) {
 			ans += pref[rep[x] - 1];
 			ll l = rep[x];
 			ll r = pos - 1;
 			n -= (l - 1);
 			ll segs = (n / (r - l + 1));
 			ans += segs * (pref[r] - pref[l - 1]);
 			ll rem = (n % (r - l + 1));
 			// debug(x, l, r, n, segs, pref[r], pref[l - 1], ans, rem);
 			ll r2 = l + rem - 1;
 			if (rem != 0) {
 				ans += (pref[r2] - pref[l - 1]);
 			}
 			break;
 		}	
 		pref[pos] = pref[pos - 1] + temp;
 		rep[x] = pos; 
 		x = (x * x) % m;
 		pos++;
 	}
 	cout << ans << endl;
	return 0;
}