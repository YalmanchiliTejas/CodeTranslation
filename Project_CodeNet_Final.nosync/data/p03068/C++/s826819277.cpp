#include<bits/stdc++.h>
using namespace std;

#define N 1000
#define pb push_back
#define mp make_pair
#define ll long long
#define mod 1000000007
#define all(cont) cont.begin(), cont.end()
#define sortcmp(n, cmpfunc) sort(all(n), cmpfunc)
#define fastio ios::sync_with_stdio(false); cin.tie(0)

ll powm(ll a, ll b);
ll divm(ll a, ll b);
ll multm(ll a, ll b);
ll subm(ll a, ll b);
ll addm(ll a, ll b);

int main(){
	int n, k;
	string s;
	fastio;
	// #ifndef LOCAL
 //    	freopen("input.in", "r", stdin);
 //    	freopen("output.out", "w", stdout);
	// #endif
    cin >> n >> s >> k;
    for(auto i : s){
    	if(i != s[k-1]) cout << '*';
    	else cout << i;
    }
    cout << endl;
	return 0;
}

// template function
ll gcd(int a, int b) { 
	if (b == 0) return a; 
	return gcd(b, a % b);  
} 

ll lcm(ll a, ll b){
	return a*b/gcd(a, b);
}

ll powm(ll a, ll b){
	ll x=1, y=a; 
    while (b > 0) {
        if (b%2) x = (x*y) % mod;
        y = (y*y) % mod;
        b /= 2;
    }
    return x % mod;
}

ll multm(ll a, ll b){
	return ((a%mod) * (b%mod)) % mod;
}

ll divm(ll a, ll b){
	return (a * powm(b, mod - 2)); 
}

ll subm(ll a, ll b){
	a -= b;
  	if (a < 0) a += mod;
	return a;
}

ll addm(ll a, ll b){
	a += b;
  	if (a >= mod) a -= mod;
  	return a;
}