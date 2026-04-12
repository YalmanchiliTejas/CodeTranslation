#define _USE_MATH_DEFINES
#include <iostream>
#include <sstream>
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
#include <set>
#include <array>
#include <stdio.h>
#include <string.h>
#include <random>
using ll = long long;
using ull = unsigned long long;
using namespace std;
#define int long long
#define CONTAINS_VEC(v,n) (find((v).begin(), (v).end(), (n)) != (v).end())
#define SORT(v) sort((v).begin(), (v).end())
#define RSORT(v) sort((v).rbegin(), (v).rend())
#define ARY_SORT(a, size) sort((a), (a)+(size))
#define REMOVE(v,a) (v.erase(remove((v).begin(), (v).end(), (a)), (v).end()))
#define REVERSE(v) (reverse((v).begin(), (v).end()))
#define ARY_REVERSE(v,a) (reverse((v), (v)+(a)))
#define REP(i, n) for (int (i)=0; (i) < (n); (i)++)
#define REPE(i, n) for (int (i)=0; (i) <= (n); (i)++)
#define CONTAINS_MAP(m, a) ((m).find((a)) != m.end())
#define CONTAINS_SET(m, a) ((m).find((a)) != m.end())
void YesNo(bool b) { cout << (b ? "Yes" : "No") << endl; }
void Yes() { cout << "Yes" << endl; }
void No() { cout << "No" << endl; }


int N, X, M;
bool memo[100000];


signed main()
{
	cin >> N >> X >> M;

	int a = X;

	int number = -1;
	memo[a] = true;
	for (int i = 1; i < N; i++)
	{
		a = a * a % M;
		if (memo[a])
		{
			number = a;
			break;
		}
		memo[a] = true;
	}


	if (number == -1)
	{
		a = X;
		int sum = 0;
		for (int i = 0; i < N; i++)
		{
			sum += a;
			a = a * a % M;
		}
		cout << sum << endl;
	}
	else
	{
		int seq1 = 0;
		a = X;
		int index = 0;
		int index0 = 0;
		while(true)
		{
			if (a == number) break;
			seq1 += a;
			a = a * a % M;
			index++;
		}
		index0 = index;

		int seq2 = 0;
		int loop_size = 0;
		while(true)
		{
			seq2 += a;
			loop_size++;
			a = a * a % M;
			if (a == number) break;
		}

		int seq3 = 0;
		int loop_cnt = (N - index0) / loop_size;
		index = index0 + loop_cnt * loop_size;
		a = number;
		for (; index < N; index++)
		{
			seq3 += a;
			a = a * a % M;
		}

		int ans = seq1 + seq2 * loop_cnt + seq3;
		cout << ans << endl;
	}

}

