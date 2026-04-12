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
typedef vector<vpint> vvpint;
typedef vector<vpll> vvpll;
typedef vector<vector<double>> vvdouble;
typedef vector<vector<string>> vvstring;
typedef vector<vector<bool>> vvbool;

typedef vector<vector<vector<ll>>> vvvll;

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

	////==================================
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(30);
	////==================================

	string n;
	ll K;
	cin >> n >> K;

	vll N;
	for (int i = 0; i < n.length(); i++)
	{
		N.emplace_back(ll(n[i]) - ll('0'));
	}

	ll ans = 0;

	if (K == 1)
	{
		// *000しかない


		// 長さが1以上小さいとき
		ans += 9 * (N.size() - 1);

		// 長さが同じとき
		ans += N[0];
	}
	else if (K == 2)
	{
		if (N.size() < 2)
		{
			cout << 0;
			return 0;
		}

		// *0*00
		

		// 長さが1以上小さいとき
		ll s = N.size() - 1;
		ans += ((s * (s - 1)) / 2 ) * 81;

		// 長さが同じとき

		// !N[0]*****
		ans += (N[0] - 1) * s * 9;

		ll first = LLINF;
		for (int i = 1; i < N.size(); i++)
		{
			if (N[i] != 0)
			{
				first = i;
				break;
			}
		}

		if (first != LLINF)
		{
			// N[0]*00000
			ans += N[first];

			// N[0]0****
			for (int i = first + 1; i < N.size(); i++)
			{
				ans += 9;
			}
		}
	}
	else if (K == 3)
	{
		if (N.size() < 3)
		{
			cout << 0;
			return 0;
		}

		// 長さが1以上小さいとき
		ll s = N.size() - 1;
		ans += ((s * (s - 1) * (s - 2)) / 6) * 9*9*9;

		// 長さが同じとき
		
		ll first = LLINF;
		for (int i = 1; i < N.size(); i++)
		{
			if (N[i] != 0)
			{
				first = i;
				break;
			}
		}
		ll second = LLINF;
		for (int i = first+1; i < N.size(); i++)
		{
			if (N[i] != 0)
			{
				second = i;
				break;
			}
		}

		if (second != LLINF)
		{
			// N[0]N[1]*000     
			ans += N[second];

			// N[0]N[1]0***
			for (int i = second + 1; i < N.size(); i++)
			{
				ans += 9;
			}
		}

		// N[0]!N[1]****
		first = LLINF;
		for (int i = 1; i < N.size(); i++)
		{
			if (N[i] != 0)
			{
				first = i;
				break;
			}
		}
		if (first != LLINF)
		{
			ans += (N[first] - 1) * (N.size() - first - 1) * 9;
		}

		//// N[0]0*****
		ll len = N.size() - first - 1;
		ans += ((len * len - len) / 2) * 9 * 9;

		// !N[0]******
		len++;
		ans += ((len * len - len) / 2) * 9 * 9 * (N[0]-1);
	}



	cout << ans;
}



