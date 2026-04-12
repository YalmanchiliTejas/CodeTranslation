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
#include <numeric>
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

int pat[51];
int arr[51];

//レベルlvバーガーの下からx層食べた時に食えるパティの数
int rec(int lv, int x)
{
	if (x == 1) { 
		if(lv == 0) return 1;
		else return 0;
	}
	//lv-1バーガー一個目に差し掛かる
	else if (arr[lv - 1] + 1 >= x) {
		return rec(lv - 1, x - 1);
	}
	//真ん中のパティが食える
	else if (arr[lv - 1] + 2 >= x) {
		return pat[lv - 1] + 1;
	}
	//二個目に差し掛かる
	else if (arr[lv - 1] * 2 + 2 >= x) { 
		return rec(lv - 1, x - (arr[lv - 1] + 2)) + pat[lv - 1] + 1; 
	}
	//全部食える
	else { 
		return pat[lv - 1] * 2 + 1;
	}
}

signed main() {
	int N, X;
	cin >> N >> X;

	for (int i = 0; i < 51; i++) {
		if (i == 0) { 
			arr[0] = 1; 
			pat[0] = 1;
			continue;
		}
		pat[i] = 2 * pat[i - 1] + 1;
		arr[i] = 2 * arr[i - 1] + 3;
	}

	//int lv = N;
	//rec(2, 4);

	cout << rec(N, X) << "\n";



	return 0;
}