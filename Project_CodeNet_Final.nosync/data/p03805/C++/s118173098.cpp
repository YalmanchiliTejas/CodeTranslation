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


	int N, M;
	cin >> N >> M;

	vvint edge(N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			edge[i].emplace_back(false);
		}
	}


	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
	
		edge[a-1][b-1] = true;
		edge[b-1][a-1] = true;
	
	}

	vint perm = {};
	for (int i = 0; i < N; i++)
	{
		perm.emplace_back(i);
	}

	int ans = 0;


	for (int i = 0; i < N - 1; i++)
	{
		if (edge[perm[i]][perm[i + 1]])
		{
			if (i == N - 2)
			{
				ans++;
				//for (int j = 0; j < N; j++) {
				//	cout << perm[j] << " ";
				//}
				//cout << endl;
			}
		}
		else {
			break;
		}
	}


	while (next_permutation(perm.begin(), perm.end()))
	{
		if (perm[0] != 0)
		{
			continue;
		}

		for (int i = 0; i < N-1; i++)
		{
			if (edge[perm[i]][perm[i + 1]])
			{
				if (i == N - 2)
				{
					ans++;
					//for (int j = 0; j < N; j++) {
					//	cout << perm[j] << " ";
					//}
					//cout << endl;
				}
			}
			else {
				break;
			}
		}


	}


	cout << ans;

}

