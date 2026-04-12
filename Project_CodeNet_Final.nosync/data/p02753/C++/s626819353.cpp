#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)  for(int i = 0; i < n; i++)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.rbegin(), cont.rend()
#define unique(a)  (a).erase(unique((a).begin(), (a).end()),(a).end())
#define fastio          ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define PB push_back
#define endl "\n"
#define mod 1000000007
typedef long long LL;
#define int long long
typedef long double LD;
typedef vector<int> VI;
inline LL add(LL x, LL y) { x += y; if (x >= mod) x -= mod; return x; }
inline LL moduloMultiplication(LL x, LL y) {
	return (x%mod * 1LL * y%mod) %

		mod;
}
inline LL power(LL a, LL b) {
	LL x = 1 % mod;
	while (b) {
		if (b & 1) x = moduloMultiplication(x, a);
		a = moduloMultiplication(a, a);
		b >>= 1;
	}
	return x % mod;
}

inline LL inv(LL a) { return power(a, mod - 2) % mod; }
LL gcd(LL a, LL b)
{
	if (!a)
		return b % mod;
	return gcd(b%a, a) % mod;
}

signed main()
{
	fastio;
	string s;
	cin >> s;
	bool pos = false;
	rep(i, s.length() - 1) {
		if (s.substr(i, 2) == "BA" || s.substr(i, 2) == "AB") {
			pos = true;
		}
	
	}
	if (pos) {
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}

}

