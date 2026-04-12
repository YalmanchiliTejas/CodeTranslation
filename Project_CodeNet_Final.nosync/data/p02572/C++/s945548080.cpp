#include <iostream>
using namespace std;
const long long MOD = 1e9 + 7;
typedef long long ll;

inline void normal(ll &a) {if(a>=MOD)a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) {normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) {normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) {normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

ll findProductSum(ll A[], ll n)
{
   ll array_sum = 0;
    for (ll i = 0; i < n; i++)
        array_sum = modAdd((array_sum) , A[i]);

    ll array_sum_square = modMul((array_sum) , (array_sum));

    ll individual_square_sum = 0;
    for (ll i = 0; i < n; i++)
        individual_square_sum = modAdd((individual_square_sum) , modMul((A[i]),(A[i])));

    return (modDiv(modSub(array_sum_square , individual_square_sum), 2));
}

int main()
{
    ll n;  cin >> n;
    ll A[n + 2] ;

    for(ll i = 0; i < n ; i++) cin >> A[i];
    ll ans = findProductSum(A, n);

    cout  << ans % MOD << endl;

    return 0;
}
