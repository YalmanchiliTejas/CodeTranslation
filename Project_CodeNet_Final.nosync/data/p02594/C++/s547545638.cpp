#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
const ll mod = 1e9 + 7;
ll powmod(ll a, ll b) { ll res=1; a%=mod; assert(b>=0); for(;b;b>>=1) { if(b&1) res=res*a%mod; a=a*a%mod; } return res; }
ll gcd(ll a, ll b) { return b ? gcd(b,a%b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a,b); }

// * ALways PASS arrays, strings etc to functions BY REFERENCE

int main() {
    int t = 1;
    // cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        if (n >= 30)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

	return 0;
}