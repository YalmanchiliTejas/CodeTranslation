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
int N, M;
vector<bool> use;
vector<vector<bool> > G;

int f(int a,int num) {
	int ans = 0;
	use[a] = true;
	++num;
	if (num == N) {
		use[a] = false;
		return 1;
	}

	for (int i = 0; i < N; ++i) {
		if (G[a][i] == false)continue;
		if (use[i])continue;
		ans += f(i,num);
	}

	use[a] = false;
	return ans;
}
void solve() {
	cin >> N >> M;
	G = vector<vector<bool>>(N, vector<bool>(N, false));
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		G[a][b] = true;
		G[b][a] = true;
	}
	use = vector<bool>(N, false);
	int ans = f(0,0);
	cout << ans << endl;
}

signed main(void) {
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	std::cout << std::fixed;//小数を10進数表示
	cout << setprecision(16);//小数点以下の桁数を指定//coutとcerrで別	

	solve();
}
