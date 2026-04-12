#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string.h>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <math.h>
#include <algorithm>
#include <numeric>

using namespace std;

// マクロ&定数 ============================================================
typedef unsigned int uint;
typedef long long ll;
//typedef pair<int, int> P;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<double> vdouble;
typedef vector<bool> vbool;
typedef vector<string> vstring;

typedef vector<vector<int>> vvint;
typedef vector<vector<ll>> vvll;
typedef vector<vector<double>> vvdouble;
typedef vector<vector<bool>> vvbool;

const int INF = 1e9 + 1;
const ll LLINF = 1e17 + 1;
const int DX[9] = { 0,0,1,-1, 1, 1, -1, -1, 0 }; // 4;４近傍
const int DY[9] = { 1,-1,0,0, 1, -1, 1, -1, 0 }; // 8:８近傍 9:(0,0)を含む
const ll MOD = 1e9 + 7; //10^9 + 7
const double PI = 3.14159265358979323846264338327950288;
//========================================================================


int main() {

	//==================================
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(30);
	//==================================

	int H, W;
	cin >> H >> W;

	vstring A(H);
	for (int i = 0; i < H; i++) {
		cin >> A[i];
	}

	vvint Grid(H);
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			Grid[i].emplace_back(int(A[i][j] == '#'));
		}
	}


	int nowH = 0;
	int nowW = 0;

	while (nowH != H-1 || nowW != W-1) {

		if (nowH + 1 < H && Grid[nowH + 1][nowW] == 1) {
			nowH++;
		}
		else if (nowW + 1 < W && Grid[nowH][nowW] == 1) {
			nowW++;
		}
		else {
			cout << "Impossible";
			return 0;
		}


	}

	int sum = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			sum += Grid[i][j];
		}
	}

	if (sum != H + W-1) {
		cout << "Impossible";
		return 0;
	}

	cout << "Possible";

}
