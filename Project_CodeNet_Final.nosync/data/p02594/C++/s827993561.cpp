#include <bits/stdc++.h>
#include <algorithm>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long 
#define pb push_back
#define mk make_pair
#define mod 1000000007
#define endl "\n"
using namespace std;

ll gcd(ll a, ll b){
    return __gcd(a,b);
}

ll lcm(ll a, ll b){
    return (a*b)/gcd(a,b);
}

bool isPrime(ll n){
    if(n <= 1) return false;
    for(ll i=2; i<=sqrt(n); i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

void solve(){
  ll n;
  cin >> n;
  if(n >= 30) cout << "Yes" << endl;
  else  cout << "No" << endl;
}

int main() {
    fast;
    solve();
	//ll t; cin >> t; while(t--){ solve(); }
	return 0;
}
