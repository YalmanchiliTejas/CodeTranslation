#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <vector>
#include <cstdlib>
#include <list>
#include <cmath>

#define _USE_MATH_DEFINES
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define INF 999999999;
#define atcoder 1000000007;

using namespace std;

int main() {
	
	int N, ans=0;
	cin >> N;

	ans += N * 800;
	ans -= N / 15 * 200;
	cout << ans << endl;

	return 0;
}