#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define MOD 1000000007

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
    int inv = modInverse(b, m); 
    if (inv == -1){
    	cout << "masuk" << endl;
       return a; 
    }
    else {
    	// cout << inv << " " << a << " " << m << endl;
       return (inv * a) % m; 
    }
} 
  

int main() {
	int n;
	cin >> n;
	ll data[n + 5];
	ll cnt = 0;
	for(int i = 0; i < n; i++) {
		cin >> data[i];
		cnt += data[i];
		cnt %= MOD;
	}
	
	cnt = (cnt * cnt);
	
	
	ll res = 0;
	for(int i = 0; i < n; i++) {
		res += (data[i] * data[i]);
		res %= MOD;
	}
	
	cout << modDivide((cnt - res) % MOD, 2, MOD) << endl;
	return 0;
}