#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <stdio.h>

#include <sstream>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <complex>

#include <string>
#include <cstring>
#include <vector>
#include <bitset>

#include <queue>
#include <set>
#include <map>
#include <stack>
#include <list>

#include <ctime>
////
//#include <random>//
/////////

typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;

////定数
const int INF = (int)1e9 + 10;
const LL MOD = (LL)1e9 + 7;
const LL LINF = (LL)4e18 + 20;
const LD PI = acos(-1.0);
const double EPS = 1e-9; 
/////////
using namespace::std;
//////////////
vector<LL> sum(51),P(51);

LL eat(int L, LL &x) {
	if (x <= 0) {
		return 0;
	}
	LL ans = 0;
	if (sum[L] <= x) {
		x -= sum[L];
		return P[L];
	}

	--x;
	if (x < sum[L - 1]) {
		return eat(L - 1, x);
	}
	ans += P[L - 1];
	x -= sum[L - 1];
	///////////////////////////
	if (x == 0) {
		return ans;
	}
	x--;
	ans++;

	if (x < sum[L - 1]) {
		return ans + eat(L - 1, x);
	}
	ans += P[L - 1];
	x -= sum[L - 1];
	
	return ans;
}
void solve() {
	LL N, X;
	cin >> N >> X;
	sum[0] = 1; P[0] = 1;
	for (int i = 1; i <= N; ++i) {
		sum[i] = sum[i - 1] * 2 + 3;
		P[i] = P[i - 1] * 2 + 1;
	}
	
	cout << eat(N, X) << endl;
}

signed main(void) {
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	std::cout << std::fixed;//小数を10進数表示
	cout << setprecision(16);//小数点以下の桁数を指定//coutとcerrで別	

	solve();
}
