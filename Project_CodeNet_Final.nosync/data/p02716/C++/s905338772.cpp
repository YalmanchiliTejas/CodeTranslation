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


bool is_overflow(ll a, ll b)
{
	if ((a * b) / b != a)
	{
		return true;
	}
	else
	{
		return false;
	}
}

ll dp[200009][5][5];


int main() {

	////==================================
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(30);
	////==================================


	ll N;
	cin >> N;
	vll A(N);
	for (ll i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	for (ll i = 0; i <= N; i++)
	{
		for (ll j = 0; j < 3; j++)
		{
			for (ll k = 0; k < 2; k++)
			{
				dp[i][j][k] = -LLINF;
			}
		}
	}

	A.emplace_back(0);
	A.emplace_back(0);
	A.emplace_back(0);
	A.emplace_back(0);
	A.emplace_back(0);
	A.emplace_back(0);

	/*
	配るDP！
	dp[i番目までの数字][これ以前にp回パスした][u＝１ならその数字を使う];
	*/

	dp[0][0][1] = A[0];
	dp[0][1][0] = 0;

	for (ll i = 0; i < N; i++)
	{
		for (ll p = 0; p <= 2; p++)
		{
			// ひとつ次(pass無し)
			if (dp[i][p][0] != -LLINF)
			{
				dp[i + 1][p][1] = max(dp[i][p][0] + A[i + 1], dp[i + 1][p][1]);
			}
			if (dp[i][p][1] != -LLINF)
			{
				dp[i + 1][p][0] = max(dp[i][p][1], dp[i + 1][p][0]);
			}

			// 二つ先(pass*1)
			if (p <= 1)
			{
				if (dp[i][p][0] != -LLINF)
				{
					dp[i + 2][p + 1][1] = max(dp[i][p][0] + A[i + 2], dp[i + 2][p + 1][1]);
				}
			}
		}


	}


	ll ans = -LLINF;

	if (N % 2 == 0)
	{
		ans = max(ans, dp[N - 1][0][0]);
		ans = max(ans, dp[N - 1][1][1]);
		ans = max(ans, dp[N - 1][0][1]);
		ans = max(ans, dp[N - 1][1][0]);
	}
	else
	{
		//ans = max(ans, dp[N - 1][0][0]);
		ans = max(ans, dp[N - 1][1][1]);
		ans = max(ans, dp[N - 1][2][0]);
		ans = max(ans, dp[N][2][0]);
		//ans = max(ans, dp[N - 1][0][1]);
		ans = max(ans, dp[N - 1][1][0]);
		ans = max(ans, dp[N - 1][2][1]);
		ans = max(ans, dp[N][2][1]);
	}
	cout << ans;

}



