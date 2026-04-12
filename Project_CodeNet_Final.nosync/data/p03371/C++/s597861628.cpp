#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const ll md = 1000000007;
vector<ll> fact(1e6 + 7), invfact(1e6 + 7);

ll fn(ll a, ll r, ll n, ll mod = md) {
    ll res = 1, x = r%mod;
    ll ans = 0;
    while(n) {
        if(n&1) ans = (x*ans + res)%mod;
        res = ((res*x)%mod + res%mod)%mod;
        x = (x*x)%mod;
        n = n/2;
    }
    ans = (ans*a)%mod;
    return ans;
}

ll nCr(ll n, ll r) {
    if(r == 0) return 1;
    ll num = fact[n];
    ll den = (invfact[r] % md *invfact[n-r] % md)%md;
    return (num*den)%md;
}

ll mul(ll a, ll b, ll mod = md) {
    ll res = (a%mod * b%mod)%mod;
    return res;
}

ll mulm(ll a, ll b, ll mod = md) {
    ll r = 0;
    a %= mod;
    while (b) {
        if (b & 1) r = (r+a)%mod;
        a = (a+a)%mod;
        b = b/2;
    }
    r %= mod;
    return r;
}

ll power(ll x, ll n, ll mod = md) {
    ll res = 1;
    x %= mod;
    while (n) {
        if (n & 1)  res = (res*x)%mod;
        n = n/2;
        x = (x*x)%mod;
    }
    return res;
}

ll power2(ll x, ll n) {
    ll res = 1;
    while (n)  
    {  
        if (n & 1)  res = (res*x);  
        n = n/2; 
        x = (x*x);  
    }  
    return res;
}

bool is_prime(ll x) {
    if(x == 1 || x == 0) return false;
    for(int i=2; i*i <= x; i++) {
        if(x%i == 0) return false;
    }
    return true;
}

ll compgcd(ll n, vector<ll> const &primes) { 
    ll res = n; 
    for (ll i=0; primes[i]*primes[i] <= n; i++) {
        if (n % primes[i]== 0) { 
            res -= (res / primes[i]); 
            while (n%primes[i]== 0) {
               n/=primes[i]; 
            }
        } 
    } 
    if (n > 1) {
       res -= (res / n); 
    }
    return res; 
} 

void sieve(vector<bool> &prime, vector<ll> &primes, ll lim) {
    for(int i = 2; i*i <= lim; i++) {
        if(prime[i]) {
            for(int j = 2; j*i <= lim; j++) {
                prime[j*i] = false;
            }
        }
    }
    for(int i = 2; i <= lim; i++) {
        if(prime[i]) {
            primes.push_back(i);
        }
    }
}

void sieveGCD(ll lim, vector<ll> &tab, vector<ll> const &primes) {
    for(int  i = 1; i <= lim; i++) {
        tab[i] = i;
    }
    for(int i = 0; i<primes.size() && primes[i] <= lim; i++) {
        tab[primes[i]] = primes[i]-1;
        for(int j = 2; primes[i]*j <= lim; j++) {
            tab[primes[i]*j] = (tab[primes[i]*j]/primes[i])*(primes[i]-1);
        }
    }
}

int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a, b, c, x, y, res;
    cin >> a >> b >> c >> x >> y;
    if(2*c < a+b) {
        res = (2*c)*min(x,y) + abs(x-y)*(x>y? (2*c < a ? (2*c) : a) : (2*c < b ? (2*c) : b));
    } else {
        res = a*x + b*y;
    }
    cout << res << "\n";
    return 0; 
}