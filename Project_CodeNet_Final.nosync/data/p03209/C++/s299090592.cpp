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
#include <functional>

using ll = long long;
using namespace std;

constexpr int MOD = 1e9 + 7;
constexpr ll MOD_LL = ll(1e9 + 7);

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
		
	function<ll(int, ll)> func = [&](int i, ll r) -> ll {
		if( i == 0 ) {
			if( r <= 0 ) return 0;
			else return 1;
		} else if( r <= 1LL + b[i - 1] ) {
			return func(i - 1, r - 1);
		} else {
			return p[i - 1] + 1LL + func(i - 1, r - 2LL - b[i - 1]);
		}			
	};
	
	cout << func(n, x) << endl;
	
	return 0;
}
