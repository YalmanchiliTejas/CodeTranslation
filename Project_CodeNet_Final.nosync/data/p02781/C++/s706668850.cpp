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

int table[101][10][4];

char N[1000];
int K;

signed main()
{
	cin >> N;
	cin >> K;


	for (int i = 1; i < 10; i++)
	{
		table[0][i][1] = 1;
	}

	for (int i = 1; i < 100; i++)
	{
		for (int k = 1; k <= 3; k++)
		{
			int sum = 0;
			for (int j = 0; j < 10; j++)
			{
				sum += table[i - 1][j][k];
			}
			table[i][0][k] = sum;
		}

		for (int j = 1; j < 10; j++)
		{
			table[i][j][1] = 1;
		}
		for (int k = 2; k <= 3; k++)
		{
			for (int j = 1; j < 10; j++)
			{
				table[i][j][k] = table[i][0][k - 1];
			}
		}
	}

	//for (int ii = 1; ii <= 10000; ii++)
	{
		//for (int jj = 1; jj <= 3; jj++)
		{
			//itoa(ii, N, 10);
			//K = jj;

			//int _cnt = 0;
			//int _n = atoi(N);
			//for (int i = 1; i <= _n; i++)
			//{
			//	int n1 = (i / 1000 % 10) == 0 ? 0 : 1;
			//	int n2 = (i / 100 % 10) == 0 ? 0 : 1;
			//	int n3 = (i / 10 % 10) == 0 ? 0 : 1;
			//	int n4 = (i / 1 % 10) == 0 ? 0 : 1;

			//	if (n1 + n2 + n3 + n4 == K)
			//	{
			//		_cnt++;
			//		cout << i << endl;
			//	}
			//}
			//cout << _cnt << endl;



			int len = strlen(N);
			int k = K;
			int sum = 0;
			for (int s = 0; s < len; s++)
			{
				int i = len - s - 1;
				int a = N[s] - '0';

				if (a == 0) continue;

				if (k == 1)
				{
					for (int j = 0; j <= a; j++)
					{
						sum += table[i][j][k];
					}
					break;
				}
				else
				{
					for (int j = 0; j < a; j++)
					{
						sum += table[i][j][k];
					}
				}
				k--;
			}

			cout << sum << endl;

			//if (sum != _cnt)
			//{
			//	int a = 0;
			//}
		}
	}

}


