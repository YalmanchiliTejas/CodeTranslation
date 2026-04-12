#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <array>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <sstream>
#include <stdio.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <list>
#include <numeric>
#include <stack>
#include <iomanip>

//using namespace std;

#define Rep(i,a,b) for(int i = a; i < b; i++)
#define rep(i,b) Rep(i,0,b)
#define allof(a) (a).begin(), (a).end()

typedef long long ll;
const int inf = 1e9 + 7;
const ll infll = 1ll << 60ll;
const ll mod = 1e9 + 7;
// 0~3までは右左下上 4~7までは斜め
constexpr int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
constexpr int dy[] = { 0, -1, 0, 1, 1, -1, -1, 1 };

namespace {  // 名前なし名前空間
	// gcd, lcm は C++17 でstdに標準入りしたので言語のバージョンに注意
	// 最大公約数
	ll gcd(ll a, ll b) {
		if (b == 0) return a;
		return gcd(b, a % b);
	}

	// 最小公倍数
	ll lcm(ll a, ll b) {
		return a / gcd(a, b) * b;
	}
}

int main() {
	int n;
	std::cin >> n;
	std::vector<std::string> s(n);
	rep(i, n) std::cin >> s[i];

	// 共通の文字をすべて保存
	std::vector<int> cnum(26, inf);

	rep(i, n) {
		std::vector<int> tmpNum(26, 0);
		rep(j, (int)s[i].size()) {
			tmpNum[s[i][j] - 'a']++;
		}
		rep(j, 26) {
			cnum[j] = std::min(cnum[j], tmpNum[j]);
		}
	}

	rep(i, 26) {
		rep(j, cnum[i]) {
			std::cout << (char)(i + 'a');
		}
	}

	std::cout << std::endl;

	return 0;
}