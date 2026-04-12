#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <bitset>
#include <utility>
#include <numeric>
#include <queue>
#include <stack>

using ll = long long;
using namespace std;

constexpr int MOD = 1e9 + 7;
constexpr ll MOD_LL = ll(1e9 + 7);

ll cnt(const vector<ll> &b, const vector<ll> &p, int n, ll x) {
	if( n == 0 ) {
		if( x <= 0 ) return 0;
		else return 1;
	} else if( x <= 1LL + b[n - 1] ) {
		return cnt(b, p, n - 1, x - 1);
	} else {
		return p[n - 1] + 1LL + cnt(b, p, n - 1, x - 2LL - b[n - 1]);
	}
}

int main(void) {
	int n;
	ll x;
	cin >> n >> x;
	
	vector<ll> b(n + 1), p(n + 1);
	b[0] = 1LL; 
	p[0] = 1LL;
	
	for(int i = 1; i <= n; ++i) {
		b[i] = b[i - 1] * 2LL + 3LL;
		p[i] = p[i - 1] * 2LL + 1LL;
	}

	cout << cnt(b, p, n, x) << endl;
	
	return 0;
}
