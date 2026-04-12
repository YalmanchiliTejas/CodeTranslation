#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
#define pb push_back
#define mp make_pair
#define PI 3.14159265358979323846
#define fi first
#define se second

ll mod = 1e9+7;

ll max(ll a, ll b ) {
	if(a>b)
		return a;
	else return b;
}
ll min(ll a, ll b ) {
	if(a<b)
		return a;
	else return b;
}
ll gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
ll inv(ll a) {
	ll x, y;
	ll g = gcd(a, mod, x, y);
	x = (x % mod + mod) % mod;
	return x;
}
ll binpow(ll a, ll b, ll m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a%m;
        a = a * a%m;
        b >>= 1;
    }
    return res;
}

bool sortbysec(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
    return (a.second < b.second); 
}

int main() {
	int t;
	//cin>>t;
	t = 1;
	while(t--) {
		int x; cin>>x;
		if(x>=30) cout<<"Yes";
		else cout<<"No";
	}
	return 0;
}