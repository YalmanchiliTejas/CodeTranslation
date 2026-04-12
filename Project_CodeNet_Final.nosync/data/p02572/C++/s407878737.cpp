#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define hell 1000000007

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
    if (inv == -1) 
       cout << "Division not defined"; 
    else
        return (inv*a)%m;
    //   cout << "Result of division is " << (inv * a) % m; 
    return -1;
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


int main(){
    ll n;
    cin >> n;
    ll ar[n];
    ll sos=0;
    ll su=0;
    for(int i=0;i<n;i++){
        cin >> ar[i];
        su=((su+ar[i])%hell);
        sos=((sos+((ar[i]*ar[i])%hell))%hell);
    }
    
    ll ssu=(su*su)%hell;
    
    ll diff=(ssu-sos+hell)%hell;
    
    ll ans=modDivide(diff,2,hell);
    cout << ans ;
    
    
    return 0;
}