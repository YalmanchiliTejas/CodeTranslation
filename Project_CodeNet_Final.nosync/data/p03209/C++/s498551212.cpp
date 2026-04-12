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

#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)

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
	return a * b / gcd(a, b);
}





///////////////////////////

ll size(ll N) {
	if (N == 0) { return 1; }
	return 3 + 2 * size(N - 1);
}

ll pat(ll N) {
	if (N == 0) { return 1; }
	return 1 + 2 * pat(N - 1);
}

ll ans(ll N, ll x) {

	if (N == 0) { return 1; }

	ll K = size(N - 1);
	ll P = pat(N - 1);

	if (x <= 1) { return 0; }
	if (1 < x&&x <= 1 + K) { return ans(N - 1, x - 1); }
	if (x == K + 2) { return P+1; }
	if (K + 2 < x&&x <= 2 * K + 2) { return P + 1 + ans(N - 1, x - K - 2); }
	if (x == 2 * K + 3) { return 2 * P + 1; }
}


int main() {
	ll N, x;
	cin >> N >> x;
	cout << ans(N, x);
	
	system("PAUSE");

}
