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

ll N, X;
vll S;
vll P;

ll saiki(ll L, ll n) // レベルiの下からj枚食べるときのパティの数
{
	if (L == 0 && n == 1)
	{
		return 1;
	}
	else if (n <= 1 || L < 0)
	{
		return 0;
	}
	else if (1 < n && n <= 1 + S[L - 1])
	{
		return saiki(L - 1, n - 1);
	}
	else if (n == 1 + S[L - 1] + 1)
	{
		return saiki(L - 1, n - 2) + 1;
	}
	else if (1 + S[L - 1] + 1 < n && n <= 1 + S[L - 1] + 1 + S[L-1])
	{
		return saiki(L - 1, S[L - 1]) + 1 + saiki(L - 1, n - (1 + S[L - 1] + 1));
	}
	else
	{
		return saiki(L - 1, S[L - 1]) * 2 + 1;
	}




}



int main() {

	//==================================
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(30);
	//==================================

	cin >> N >> X;

	for (int i = 0; i <= N; i++)
	{
		S.emplace_back(ll(pow(2, i + 2)) - 3);
		P.emplace_back(ll(pow(2, i + 1)) - 1);
	}


	cout << saiki(N, X);






}



