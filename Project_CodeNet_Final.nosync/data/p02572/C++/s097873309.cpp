                              //          ★★ ASHWINI SHARMA ★★ 
#include <bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (long long i = (n) - 1; i >= 0; i--)
#define foreach(it,ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define ull unsigned long long int
#define ll long long int
#define ui unsigned int
#define pb push_back
 
#define PI 3.1415926535897932385
#define INF 1e9
#define EPS 1e-7
#define MAXN 1000000005
#define MOD 1000000007 
                              //          ★★ ASHWINI SHARMA ★★      
ll gcd(ll a, ll b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 
ll exp(ll x, ll y, ll p)
{
    ll res = 1;   
    x = x % p;  
    while (y > 0)
    {
        if (y & 1)    
            res = (res*x) % p;
        y = y>>1;     
        x = (x*x) % p; 
    }
    return res;
}



int main() {
   
    fastio;
    int n;
    cin >> n;
    ll a[n];
    rep(i, n)
    cin >> a[i];
    ll pre[n] = {0};
    pre[n-1] = a[n-1];
    for(int i=n-2;i>=0;i--)
        pre[i] = (a[i] % MOD + pre[i+1] % MOD) % MOD;
    ll sum = 0;
    rep(i, n-1)
    {
        sum += (a[i] * pre[i+1]) % MOD;
        sum %= MOD;
    }
    cout << sum;



    return 0; 
}