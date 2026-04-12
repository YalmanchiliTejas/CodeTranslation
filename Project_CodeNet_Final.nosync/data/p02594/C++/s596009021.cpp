#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
#define watch(x) cout << (#x) << " is " << (x) << endl
 
bool isPrime(int i) {
	if(i < 2) {
		return false;
	}
	if(i == 2) {
		return true;
	}
	if(!(i % 2)) {
		return false;
	}
	for(int j = 3; j * j <= i; j += 2) {
		if(!(i % j)) {
			return false;
		}
	}
	return true;
}
void solve() {
	int n;
	cin >> n;
	if(n >= 30) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}

}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); 
	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif
    int T = 1; 
    // cin >> T;
    while(T--)
    	solve();
	return 0;
}
