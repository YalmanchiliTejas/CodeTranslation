#include <bits/stdc++.h>
using namespace std;
typedef vector<long long int> vint;
typedef vector<vint> vvint;
typedef long long int ll;
#define MOD 1000000007

static vint arr;

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

ll modInverse(ll b) 
{ 
    ll x, y; // used in extended GCD algorithm 
    ll g = gcdExtended(b, MOD, &x, &y); 
  
    // Return -1 if b and m are not co-prime 
    if (g != 1) 
        return -1; 
  
    // m is added to handle negative x 
    return (x%MOD + MOD) % MOD; 
} 

void divide(ll& a, ll b){
	a = a % MOD;
	a = (modInverse(b) * a) % MOD; 
}

ll solve(void){
	ll res = 0, n = arr.size(), curr = 0;

	for(int i = 1; i < n; i++){
		curr = (curr + ((arr[0] * arr[i]) % MOD)) % MOD;
	}

	res = curr;

	for(int i = 1; i < n; i++){
		divide(curr, arr[i-1]);
		curr = (curr - arr[i]) % MOD;
		if(curr < 0)
			curr += MOD;

		curr = (curr * arr[i]) % MOD;
		res = (res + curr) % MOD;
	}

	return res;

	// unordered_map<ll, ll> bucket, product;

	// for(ll i:arr)
	// 	bucket[i]++;

	// for(auto itr = bucket.begin(); itr != bucket.end(); itr++){

	// }
}

int main(){
	int n;
	while(cin >> n){
		arr.resize(n);
		for(int i = 0; i < n; i++)
			cin >> arr[i];

		cout << solve() << "\n";
	}
	
	return 0;
}
