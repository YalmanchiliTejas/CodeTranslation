#include "bits/stdc++.h"

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define bit(n) (1LL << (n))
#define sz(x) ((int)(x).size())
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define en '\n'
#define pb push_back
#define mp make_pair

typedef long long ll;
using namespace std;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { ll g = gcd(a, b); return a / g * b; }
const int dx[4] = { 1, 0, -1,  0 };
const int dy[4] = { 0, 1,  0, -1 };
const int INF = (int)1e9;
const ll  inf = (ll)1e18;
const int mod = 1000000007;

struct aaa {
	aaa() {
		cin.tie(0);
		ios::sync_with_stdio(0);
		cout << fixed << setprecision(20);
	};
}aaaaa;



int main() {
	int n;
	cin >> n;
	if (n == 7 || n == 5 || n == 3) {
		cout << "YES" << en;
	}
	else {
		cout << "NO" << en;
	}
}