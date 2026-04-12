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

void solve() {
	int N;
	cin >> N;
	vector<LL> A(N);
	LL ans = 0;
	LL base = N * N + N;
	
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
		LL cnt = A[i] / base;
		ans += base * cnt;
		A[i] %= base;
	}
	
	int LOOP = 0;
	int ter = 0;
	while (LOOP != N) {
		if (A[ter] >= N) {
			LOOP = 0;
			int asd = A[ter] / N;
			ans += asd;
			A[ter] %= N;
			for (int i = 0; i < N; ++i) {
				if (i == ter)continue;
				A[i] += asd;
			}
		}
		else {
			LOOP++;
		}
		ter = (ter + 1) % N;
	}
	cout << ans << endl;
}

signed main(void) {
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	std::cout << std::fixed;//小数を10進数表示
	cout << setprecision(16);//小数点以下の桁数を指定//coutとcerrで別	

	solve();
}
