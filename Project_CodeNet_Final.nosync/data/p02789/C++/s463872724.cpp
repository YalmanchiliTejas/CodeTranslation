/**
 * @author      : omgursocute
 * @created     : 20/01/2020
 * @task        : A
 */

// ===== TEMPLATE STARTS HERE ===== //

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define FORa(i, a, b) for(ll i = (a); i <= (b); ++i)
#define FORb(i, a, b, c) for(ll i = (a); i <= (b); i += (c))
#define FORn(i, n) for(ll i = 0; i < (n); ++i)
#define FORra(i, a, b) for(ll i = (a); i >= (b); --i)
#define FORrb(i, a, b, c) for(ll i = (a); i >= (b); i -= (c))
#define FORrn(i, n) for(ll i = ((n)-1); i >= 0; --i)
#define NUMARGC(_1, _2, _3, _4, NAME, ...) NAME
#define FOR(...) NUMARGC(__VA_ARGS__, FORb, FORa, FORn)(__VA_ARGS__)
#define RFOR(...) NUMARGC(__VA_ARGS__, FORrb, FORra, FORrn)(__VA_ARGS__)

#define XFOR(i, x) for(__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define RXFOR(i, x) for(__typeof((x).rbegin()) i = (x).rbegin(); i != (x).rend(); ++i)

#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define range(x, a, b) ((x).begin()+a), (x).begin()+b)
#define pb push_back

#define sqr(x) 1ll*(x)*(x)
#ifndef ONLINE_JUDGE
#define debug(x) cerr << '[' << #x << ']' << " = " << x << '\n'
#else
#define debug(x) "cute"
#endif

namespace io {
	void Speed() {
		ios::sync_with_stdio(false);
		cin.tie(NULL); cout.tie(NULL);
	}
#ifndef ONLINE_JUGDE
	void In(string s) {freopen(s.c_str(), "r", stdin);}
	void Out(string s) {freopen(s.c_str(), "w", stdout);}
	void setIO(string s) {In(s + ".inp"); Out(s + "out");}
#endif
}

// ======= TEMPLATE ENDS HERE ======= //

int main() {
	io::Speed();
	
	int a, b;
	cin >> a >> b;

	cout << ((a ^ b) ? "No" : "Yes");

	return 0;
}

