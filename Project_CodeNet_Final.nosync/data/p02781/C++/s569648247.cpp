#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <cstring>
#include <cmath>
#include <stack>
#include <iomanip>
#include <tuple>
#include <functional>
#include <cfloat>
#include <map>
#include <stdio.h>
#include <string.h>
using ll = long long;

//LLONG_MAX
#define int long long
#define CONTAINS(v,n) (find((v).begin(), (v).end(), (n)) != (v).end())
#define SORT(v) sort((v).begin(), (v).end())
#define RSORT(v) sort((v).rbegin(), (v).rend())
#define ARY_SORT(a, size) sort((a), (a)+(size))
#define REMOVE(v,a) (v.erase(remove((v).begin(), (v).end(), (a)), (v).end()))
#define REVERSE(v) (reverse((v).begin(), (v).end()))
#define LOWER_BOUND(v,a) (lower_bound((v).begin(), (v).end(), (a)))
#define UPPER_BOUND(v,a) (upper_bound((v).begin(), (v).end(), (a)))
#define REP(i, n) for (int (i)=0; (i) < (n); (i)++)
#define CONTAINS_MAP(m, a) (m).find((a)) != m.end()

using namespace std;

int _dp0[101][4];
int _dp1[101][4];

char cN[110];
int N[110];
int K;

signed main()
{
	cin >> cN;
	cin >> K;
	int len = strlen(cN);
	REP(i, len) N[i] = cN[i] - '0';

	_dp0[0][1] = 1;
	_dp1[0][1] = N[0] - 1;
	_dp1[0][0] = 1;

	for (int i = 1; i < len; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			if (N[i] == 0)
			{
				_dp0[i][j] = _dp0[i - 1][j];
			}
			else
			{
				_dp0[i][j + 1] = _dp0[i - 1][j];

				_dp1[i][j] += _dp0[i - 1][j];
				if (j < 3)
				{
					_dp1[i][j + 1] += (N[i] - 1) * _dp0[i - 1][j];
				}
			}
		}

		for (int j = 0; j <= 3; j++)
		{
			_dp1[i][j] += _dp1[i - 1][j];
			if (j > 0)
			{
				_dp1[i][j] += _dp1[i - 1][j - 1] * 9;
			}
		}
	}

	int ans = _dp0[len - 1][K] + _dp1[len - 1][K];
	cout << ans << endl;
}


