#include <iostream>
#include <string>
#include <cmath>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<iomanip>
#define _USE_MATH_DEFINES
#include <math.h>
#include <functional>
using namespace std;

#define rep(i,x) for(ll i=0;i<x;i++)
#define repn(i,x) for(ll i=1;i<=x;i++)

typedef long long ll;
const ll INF = 1e17;
const ll MOD = 1000000007;
const ll MAX = 1000001;

ll max(ll a, ll b) {
	if (a > b) { return a; }
	return b;
}

ll min(ll a, ll b) {
	if (a > b) { return b; }
	return a;
}

ll gcd(ll a, ll b) {
	if (b == 0) { return a; }
	if (a < b) { return gcd(b, a); }
	return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) *b;
}

struct edge {
	ll ind;
	ll fr;
	ll to;
	ll d;
};


///////////////////////////


int main() {
	
	ll N;
	cin >> N;

	vector<ll> A(N + 1);
	repn(i, N) cin >> A[i];

	sort(++A.begin(), A.end());

	ll ans = 0;

	repn(i, N-1) {
		ans += (A[i + 1] - A[i]) * 2 * min(i, N - i);
	}

	ll x;
	if (N % 2 == 1) { x = min(A[N / 2 + 2] - A[N / 2 + 1], A[N / 2 + 1] - A[N / 2]); }
	else { x = A[N / 2 + 1] - A[N / 2]; }

	cout << ans - x;


	system("PAUSE");
}
