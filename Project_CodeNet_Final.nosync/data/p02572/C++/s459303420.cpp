#include <bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define mod 1000000007

ll gcdExtended(ll a, ll b, ll *x, ll *y); 
  int modInverse(int b, int m) 
{ 
    ll x, y; // used in extended GCD algorithm 
    ll g = gcdExtended(b, m, &x, &y); 
  
    if (g != 1) 
        return -1; 
    return (x%m + m) % m; 
} 
  
ll modDivide(ll a, ll b, ll m) 
{ 
    a = a % m; 
    ll inv = modInverse(b, m); 
   return (inv * a) % m; 
} 
ll gcdExtended(ll a, ll b, ll *x, ll *y) 
{ 
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
  
ll power(ll x, ll y, ll m) 
{ 
    if (y == 0) 
        return 1; 
    int p = power(x, y/2, m) % m; 
    p = (p * p) % m; 
  
    return (y%2 == 0)? p : (x * p) % m; 
} 
  

ll findProductSum(ll A[], ll n) 
{ 
	ll array_sum = 0; 
	for (int i = 0; i < n; i++) 
		array_sum = array_sum + A[i]; 
    array_sum%=mod;
    
	ll array_sum_square = array_sum * array_sum; 
    array_sum_square%=mod;
    
	ll individual_square_sum = 0; 
	for (int i = 0; i < n; i++) {
		individual_square_sum += A[i]*A[i]; 
		individual_square_sum%=mod;}

	return modDivide(((array_sum_square - individual_square_sum)+mod)%mod,2,mod); 
} 
 
int main() 
{ 
	ll n;
	cin>>n;
	ll arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	cout<<findProductSum(arr,n);
	return 0; 
} 
