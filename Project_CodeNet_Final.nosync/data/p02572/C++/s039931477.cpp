#include <bits/stdc++.h> 
using namespace std; 
#define ll long long int
#define pb push_back             
#define se second                
#define fi first  
#define be begin()
#define en end()
#define all(v) v.be, v.en
template<typename... T> void pp(T... args) { ((cout << args << " "), ...); cout<<"\n"; }
template<typename... T> void po(T... args) { ((cout << args << " "), ...); cout<<""; }
// #define mod 1000000007
ll mod = 1e9+7;

ll gcd(ll a, ll b); 
  
// To compute x raised to power y under modulo m 
ll power(ll x, ll y, ll m); 
  
// Function to find modular inverse of a under modulo m 
// Assumption: m is prime 
ll modInverse(ll a, ll m) 
{ 
    // ll g = gcd(a, m); 
    ll g = 1;
    if (g != 1) 
        cout << "Inverse doesn't exist"; 
    else
    { 
        // If a and m are relatively prime, then modulo inverse 
        // is a^(m-2) mode m 
        // cout << "Modular multiplicative inverse is "
            //  << power(a, m-2, m); 
            return power(a, m-2, m); 
    } 
} 
  
// To compute x^y under modulo m 
ll power(ll x, ll y, ll m) 
{ 
    if (y == 0) 
        return 1; 
    ll p = power(x, y/2, m) % m; 
    p = (p * p) % m; 
  
    return (y%2 == 0)? p : (x * p) % m; 
} 


ll findProductSum(ll A[], ll n) 
{ 
    // calculating array sum (a1 + a2  ... + an) 
    ll array_sum = 0; 
    for (ll i = 0; i < n; i++){
         array_sum = array_sum + A[i]; 
         array_sum%=mod;
    }
       
  
    // calcualting square of array sum 
    // (a1 + a2 + ... + an)^2 
    ll array_sum_square = array_sum * array_sum; 
    array_sum_square%=mod;
  
    // calcualting a1^2 + a2^2 + ... + an^2 
    ll individual_square_sum = 0; 
    for (ll i = 0; i < n; i++){
        individual_square_sum += A[i]*A[i]; 
        individual_square_sum%=mod;

    }
  
    // required sum is (array_sum_square - 
    // individual_square_sum) / 2 
    ll ans = (array_sum_square - individual_square_sum); 
    ans = (ans+mod+mod+mod)%mod; 

    ans*=500000004;
    ans%=mod;
    return ans; 
}  
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
     int test=1;
     //cin>>test;
     for(int tt=1; tt<=test; tt++){
       ll n;
       cin>>n;
       ll a[n];
       for(ll i=0; i<n; i++){
           cin>>a[i];
       }
        ll ans = findProductSum(a, n);
        pp(ans);
     //cout<<"Case #"<<tt<<": ";  
     }
 
    return 0;
}