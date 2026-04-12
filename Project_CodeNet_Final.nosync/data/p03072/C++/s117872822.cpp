/**
 *    author:  rishabh_sethi
**/
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define mem(x, val) memset(x, val, sizeof(x))
#define mk make_pair
#define f(i,n) for(i = 0; i < n; i++)
#define f1(i,n) for(i = 1; i <= n; i++)
#define all(a) a.begin(),a.end()
#define upp(v,val) upper_bound(v.begin(), v.end(), val)
#define lower(v,val) lower_bound(v.begin(), v.end(), val)
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())
#define dbg(x) cout << #x << " = " << x << endl
#define dbg2(x,y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define dbg3(x,y,z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define dbg4(x,y,z,q) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #q << " = " << q << endl
#define jaldi_chal() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define S second
#define F first
#define fm(it,m) for(it = m.begin(); it != m.end(); it++)
#define ct_set(n) __builtin_popcount(n) // count no of set bits
#define INF 0x3f3f3f3f
#define endl '\n'
#define mod 1000000007
#define PI 3.14159265    // acosl(-1)
#define precision cout << setprecision(15)
#define print_arr(a,n) for(int i = 0; i < n; i++) cout << a[i] << " ";
#define print_vec(v) for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
//vec.erase(std::remove(vec.begin(), vec.end(), val), vec.end());
using namespace std;

// for ordered set
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int ddx[8] = {1, 1, 0, -1, -1, -1, 0, 1}, ddy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

// v.resize(unique(v.begin(), v.end()) - v.begin());   // for unique elements in sorted vector
// fflush(stdout);  // after every output

// Using 128 bit integers
/*
	std::string toString(__int128 num) {
    std::string str;
    do {
        int digit = num % 10;
        str = std::to_string(digit) + str;
	        num = (num - digit) / 10;
	    } while (num != 0);
	    return str;
	}
	
	int main() {
	    __int128_t x;
	    string s;
	    cin >> s;
	    x = (stoll)(s);
	    __int128_t ans = x * x * x;
	    cout << toString(ans);
	}

*/

bool isPrime(ll n) {
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
 
    if (n % 2 == 0 || n % 3 == 0)
        return false;
 
    for (ll i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
 
    return true;
}

ll gcd(ll a,ll b) {
	if (a == 0)    
		return b; 	
	return gcd(b % a, a); 
}

ll lcm(ll a, ll b) {	
	ll g = gcd(a, b); 
	ll ans = (a * b) / g; 
	return ans;	
}

ll add(ll a, ll b) {
	a += b;
	if (a >= mod) a -= mod;
	return a;
}
 
ll sub(ll a, ll b) {
	a -= b;
	if (a < 0) {
		a += mod;
	}
	return a;
}
 
ll mul(ll a, ll b) {
	return (a * b) % mod;
}

vector <ll> primes;

bool prime[10005];
void seive() {
	mem(prime, 1);
	prime[0] = 0;
	prime[1] = 0;
	for(ll i = 2; i <= 10000; i++)
	{
		if(prime[i] == 1)
		{
			for(ll j = i * i; j <= 10000; j += i)
			prime[j] = 0;
		}
	}	
}

ll power(ll a, ll b) {
	ll ans = 1;
	while(b > 0)
	{
		if(b % 2 == 1)
		ans = (ans % mod * a % mod) % mod;
		a = (a * a) % mod;
		b = b / 2;
	}
	return ans;
}

template <typename T>
std::string NumberToString ( T Number ) {
	std::ostringstream ss;
	ss << Number;
	return ss.str();
}

string num_to_bits(ll n) {
	string ans = "";
	while(n) {
		ans += (n % 2) + '0';
		n /= 2;
	}
	reverse(all(ans));
	return ans;
}

ll bits_to_num(string s) {
	ll ans = 0;
	for(ll i = 0; i < s.size(); i++) {
		ll x = s.size() - i - 1;
		ll val = pow(2LL, x);
		if(s[i] == '1') {
			ans = ans + val;
		}
	}
	return ans;
}

ll gcdExtended(ll a, ll b, ll *x, ll *y);   
ll modInverse(ll b, ll m) { 
    ll x, y; 
    ll g = gcdExtended(b, m, &x, &y); 
    if (g != 1) 
        return -1; 
    return (x % m + m) % m; 
} 
  
// Function to compute a/b under modlo m 
ll modDivide(ll a, ll b, ll m) { 
    a = a % m; 
    ll inv = modInverse(b, m); 
    //if (inv == -1) 
       //cout << "Division not defined"; 
    //else
       //cout << "Result of division is " << (inv * a) % m; 
       return (inv * a) % m;
} 

ll gcdExtended(ll a, ll b, ll *x, ll *y) { 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
    ll x1, y1; 
    ll gcd = gcdExtended(b % a, a, &x1, &y1); 
    *x = y1 - (b / a) * x1; 
    *y = x1; 
    return gcd; 
} 
// To call for modulo division (a / b) % m : modDivide(a, b, m);

ll fact[2005];
void factorials() {
	fact[0] = 1;
	for(ll i = 1; i <= 2002; i++) {
		fact[i] = (i * fact[i - 1]) % mod;
	}
} 

ll nCr(ll n, ll r) {
	if(r > n) {
		return 0;
	}
	ll result = fact[n];
	result = modDivide(result, fact[r], mod);
	return modDivide(result, fact[n - r], mod);
}

/* This will store divisors of the number from 1 to n
	for(i = 1; i <= n; i++) {
		for(j = i; j <= n; j += i) {
			v[j].pb(i);
		}
	}
*/

void solve() {
	
	ll n;
	cin >> n;
	
	ll a[n], i, j;
	
	ll ans = 0, maxi = 0;
	for(i = 0; i < n; i++) { 
		cin >> a[i];
		maxi = max(maxi, a[i]);
		if(a[i] == maxi) {
			ans++;
		}
	}
	cout << ans;
	
}

int main() {
	jaldi_chal()
	
//	freopen("input.txt", "r" , stdin);
//  freopen("output.txt", "w", stdout);
	
//	seive();
//	for(int i = 2; i <= 10000; i++)	{
//		if(prime[i])
//		primes.pb(i);
//	}
	
	bool codechef = 0;
	ll t = 1;
	
	if(codechef) {
		cin >> t;
	}
	
	for(ll i = 1; i <= t; i++) {
		// cout << "Case #" << i << ": ";
		solve();
	}
	
	return 0;
}