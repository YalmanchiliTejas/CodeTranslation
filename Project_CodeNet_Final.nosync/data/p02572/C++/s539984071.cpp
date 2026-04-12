#include <bits/stdc++.h>
using namespace std;
#define ll  long long
#define endl "\n"
#define mod 1000000007

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
     return (inv * a) % m; 
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



ll fi(ll A[], ll n) 
{ 
    // calculating array sum (a1 + a2  ... + an) 
    ll array_sum = 0; 
    for (ll i = 0; i < n; i++) 
        array_sum = (array_sum%mod + A[i]%mod)%mod; 
  
    // calcualting square of array sum 
    // (a1 + a2 + ... + an)^2 
    ll array_sum_square = (array_sum%mod * array_sum%mod)%mod; 
  
    // calcualting a1^2 + a2^2 + ... + an^2 
    ll individual_square_sum = 0; 
    for (ll i = 0; i < n; i++) 
        individual_square_sum = (individual_square_sum%mod+(A[i]%mod*A[i]%mod)%mod)%mod; 
  
    // required sum is (array_sum_square - 
    // individual_square_sum) / 2 
    array_sum_square=array_sum_square%mod;
    individual_square_sum=individual_square_sum%mod;
     ll v= (array_sum_square%mod - individual_square_sum%mod)%mod;
     if(v<0)
     v=v+mod;
     return modDivide(v, (ll)2, mod);
} 

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++)
    {
    	cin>>arr[i];
    }
    cout<<fi(arr,n);
	return 0;
}
