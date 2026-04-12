#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <numeric>
#include <queue>
#include <map> 
#include <set>
#include <string>
#include <functional>
#include <list>
#include <random>
#include <time.h>
#include <iomanip>
#include <assert.h>
#define int long long
#define double long double
#define oku7 1000000007
#define MAXN (int)1e+5 * 2+1
#define LL_MAX 9223372036854775807	//ない環境用
#define LL_HALFMAX 9223372036854775807 / 2	//ない環境用

using namespace std;
std::mt19937 mt((int)time(0));

int dx[4] = { 0, 1, 0, -1 }; // x軸方向への変位
int dy[4] = { 1, 0, -1, 0 }; // y軸方向への変位

vector<pair<int,int>> G[100002];

int x[100002];
int cnt = 0;
void dfs(int id) {
	//繋がってるノードをぜんぶ展開
	for (pair<int, int> p : G[id]) {
		//未訪問なら
		if (x[p.first] == LL_HALFMAX) {
			x[p.first] = x[id] + p.second;
			dfs(p.first);
		}
		//訪問済みなら
		else {
			//矛盾検査
			if (x[p.first] - x[id] != p.second) cnt++;
		}
	}
}

signed main() {
	int N, K;
	cin >> N >> K;
	//p:わるかず
	int ans = 0;
	for (int p = K + 1; p <= N; p++) {
		int add = (N / p)*(p - K) + max((N%p - max(K-1, 0LL)), 0LL);
		ans += add;
	}
	cout << ans << "\n";
	return 0;
}