#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)  for(int i = 0; i < n; i++)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.rbegin(), cont.rend()
#define unique(a)        (a).erase(unique((a).begin(), (a).end()),(a).end())
#define fastio          ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define PB push_back
#define endl "\n"
#define mod 1000000007 
typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
inline LL moduloMultiplication(LL x, LL y) { return (x%mod * 1LL * y%mod) % mod; }
inline LL power(LL a, LL b) {
	LL x = 1 % mod;
	while (b) {
		if (b & 1) x = moduloMultiplication(x, a);
		a = moduloMultiplication(a, a);
		b >>= 1;
	}
	return x % mod;
}

LL gcd(LL a, LL b)
{
	if (!a)
		return b;
	return gcd(b%a, a);
}
inline LL add(LL x, LL y) { x += y; if (x >= mod) x -= mod; return x; }
int main()
{
	int a, b;
	cin >> a >> b;
	if (a == b)cout << "Yes" << endl;
	else cout << "No" << endl;
}
