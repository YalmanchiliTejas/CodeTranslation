//カタラン数を語らん!w

#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream>
#include <random>
#include<map>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <unordered_map>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <bitset>
using namespace std;
typedef string::const_iterator State;
#define Ma_PI 3.141592653589793
#define eps 1e-5
#define LONG_INF 2000000000000000000LL
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL
#define MOD 998244353LL
#define seg_size 262144*2
#define REP(a,b) for(long long a = 0;a < b;++a)
#define int long long
int dp[201][201][500];
int grid[201][201];
#undef int
int main() {
#define int long long
	int h, w;
	cin >> h >> w;
	int hoge = 0;
	REP(i, h) {
		REP(q, w) {
			cin >> grid[i][q];
			hoge += grid[i][q];
		}
	}
	dp[0][0][0] = grid[0][0];
	for (int i = 0; i < h + w-2; ++i) {
		for (int q = 0; q <= i; ++q) {
			for (int j = 0; j <= i; ++j) {
				int first_x = q;
				int first_y = i - q;
				int second_x = j;
				int second_y = i - j;
				REP(t, 2) {
					REP(p, 2) {
						int next_fx = first_x + t;
						int next_fy = first_y + 1 - t;
						int next_sx = second_x + p;
						int next_sy = second_y + 1 - p;
						if (next_fx >= h || next_sx >= h | next_fy >= w | next_sy >= w) {
							continue;
						}
						int winning = dp[q][j][i] + grid[next_fx][next_fy];
						if (next_fx != next_sx || next_fy != next_sy) {
							winning += grid[next_sx][next_sy];
						}
						dp[next_fx][next_sx][i+1] = max(dp[next_fx][next_sx][i+1], winning);
					}
				}
			}
		}
	}
	cout << dp[h - 1][h - 1][h + w - 2] << endl;
}