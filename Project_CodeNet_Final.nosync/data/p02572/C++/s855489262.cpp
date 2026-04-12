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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll n;
 	cin >> n;
 	vector <ll> vec(n);
 	for (ll i = 0; i < n; i++) {
 		cin >> vec[i];
 	}
 	vector <ll> pref = vec;
 	for (ll i = n - 2; i >= 0; i--) pref[i] = (pref[i] + pref[i + 1]) % mod; 
 	ll ans = 0;
 	for (ll i = 0; i < n - 1; i++) {
 		ans += (vec[i] * pref[i + 1]) % mod;
 		ans %= mod;
 	}
 	cout << ans << endl;
	return 0;
}