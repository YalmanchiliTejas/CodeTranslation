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

typedef vector<pair<int, int>> vpint;
typedef vector<pair<ll, ll>> vpll;
typedef vector<pair<double, double>> vpdouble;

typedef vector<vector<int>> vvint;
typedef vector<vector<ll>> vvll;
typedef vector<vector<double>> vvdouble;
typedef vector<vector<bool>> vvbool;

const int c_YET = -1;
const int INF = 1e9 + 1;
const ll LLINF = 1e17 + 1;
const int DX[9] = { 0,0,1,-1, 1, 1, -1, -1, 0 }; // 4;４近傍
const int DY[9] = { 1,-1,0,0, 1, -1, 1, -1, 0 }; // 8:８近傍 9:(0,0)を含む
const ll MOD = 1e9 + 7; //10^9 + 7
const ll MAX = 1e9;
const double PI = 3.14159265358979323846264338327950288;
//========================================================================








int main() {

	//==================================
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(30);
	//==================================



	string S;
	cin >> S;

	char first = S[0];
	for (int i = 0; i < S.length(); i++) {
		if( S[i] != first){
			cout << "Yes";
			return 0;
		}
	}

	cout << "No";

}
