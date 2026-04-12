#define _USE_MATH_DEFINES 
#include<iomanip> 
#include<cmath>  
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<bitset>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<queue>
#include<deque>
#include<stack>
using namespace std;
typedef long long ll;
#define repi(i,a,b) for(ll i = (ll)(a) ; i < (ll)(b) ; i++)
#define repd(i,a,b) for(ll i = (ll)(a) ; i > (ll)(b) ; i--)
#define rd(x) cin >> x
#define wr(x)  cout << x
#define wrln(x) cout << x << endl
#define wl() cout << endl
const ll MAX_10p5 = 100010;
const ll MAX_10p9 = 1000000010;
const ll MAX_10p18 = 1000000000000000010;
const ll MOD = 1000000007;
const ll m4x[4] = { 1,0,-1,0 };
const ll m4y[4] = { 0,1,0,-1 };
const ll m8x[8] = { 1,1,0,-1,-1,-1,0,1 };
const ll m8y[8] = { 0,1,1,1,0,-1,-1,-1 };
const ll m9x[9] = { 1,1,0,-1,-1,-1,0,1,0 };
const ll m9y[9] = { 0,1,1,1,0,-1,-1,-1,0 };

struct edge {
	ll from, to, cost;
	bool operator<(const edge& right) const {
		return cost < right.cost;
	}
};
struct point {
	ll x, y;
	bool operator<(const point& right) const {
		return x == right.x ? y < right.y : x < right.x;
	}
};

///////////////////////////////////////////////////////////////////////////////////////

ll n, x[MAX_10p5 * 2], sorted[MAX_10p5 * 2], ansL, ansR;

int main() {
	cin >> n;
	repi(i, 0, n) {
		rd(x[i]);
		sorted[i] = x[i];
	}
	sort(sorted, sorted + n);
	ansL = sorted[n / 2 - 1];
	ansR = sorted[n / 2];
	repi(i, 0, n) {
		if (x[i] <= ansL) wrln(ansR);
		else wrln(ansL);
	}
	return 0;
}
