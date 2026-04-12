#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define br cout<<"\n";
#define ull unsigned long long int
#define ld long double
#define loop1(i,a,b) for(int i=a;i<b;i++)
#define loop2(i,a,b) for(int i=a;i<=b;i++)
#define loop3(i,a,b) for(int i=a;i>b;i--)
#define loop4(i,a,b) for(int i=a;i>=b;i--)
#define all(a) a.begin(),a.end()
#define test(t) ll t; cin >> t; while(t--)
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vll vector<ll>
#define fi first
#define se second
#define line cout<<"\n********************************************\n";
///////////////////////////////////////////////////////////////////////////////////////////////////////
 ll MI( ll a , ll mod) // mod inverse (x/y) % mod --> y == a.. multiply result with x..
 {
     return ((a %= mod) < 2) ? a : ((1 - (MI(mod % a , a) * mod))/a+mod);
 }
 bool isprime(ll n);
 ll power(ll x, ll y, ll mod);
 ll fact( ll n );
 ll nCrMod(ll n, ll r, ll p);
///////////////////////////////////////////////////////////////////////////////////////////////////////
//---------------------------------------------
// H B L O R D 7 8 7
// Solution for Problem Code : 
// Contest : 
//--------------------------------------------

signed main() 
{
    FASTIO
     int x;
     cin >> x;
     if( x >= 30) cout << "Yes\n";
     else cout << "No\n";
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//--------------------------------------------
bool isprime(ll n)
 {
     for(ll i = 2 ; i*i<=n ; i++)
        if( n % i == 0)
            return false;
     return true;
 }
 //--------------------------------------------
 ll fact( ll n )
{
 if( n == 1 ) return n;
 else return n*fact(n-1);
}
 //--------------------------------------------
ll power(ll x, ll y, ll mod)  // (x ^ y) % mod...
{  
    ll result = 1; 
    x = x % mod; 
    if (x == 0) return 0;
    while (y > 0)  
    {  
        if (y & 1) result = (result * x) % mod;  
        y = y >> 1; // y = y / 2
        x = (x * x) % mod;  
    }  
    return result;  
}  
 //--------------------------------------------
ll nCrMod(ll n, ll r, ll p) 
{ 
    if (r == 0) 
        return 1; 
    ull fac[n + 1]; 
    fac[0] = 1; 
    for (int i = 1; i <= n; i++) 
        fac[i] = (fac[i - 1] * i) % p; 
    return (((fac[n] * MI(fac[r], p)) % p) * (MI(fac[n - r], p) % p)) % p; 
}
 //--------------------------------------------
 /*
 fact[i] = (fact[i-1]*i)%MOD;
 invfact[i] = power(fact[i],MOD-2);
 int nCr(int n,int r){
    if(r > n) return 0;
    int ret = (fact[n]*invfact[r])%MOD;
    return (ret*invfact[n-r])%MOD;
}*/
 //--------------------------------------------
 //////////////////////////////////////////////////////////////////////////////////////////////////////
