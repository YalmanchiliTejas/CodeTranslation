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

#define int long long
#define CONTAINS(v,n) (find((v).begin(), (v).end(), (n)) != (v).end())
#define SORT(v) sort((v).begin(), (v).end())
#define RSORT(v) sort((v).rbegin(), (v).rend())
#define ARY_SORT(a, size) sort((a), (a)+(size))
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define REMOVE(v,a) v.erase(remove(v.begin(), v.end(), a), v.end())
#define REP(i, n) for (int (i) = 0; (i) < (n); (i)++)
using namespace std;

int N;
int a[50];

signed main()
{
	cin >> N;
	REP(i, N) cin >> a[i];

	int cnt = 0;
	while (true)
	{
		int cc = 0;
		for (int i = 0; i < N; i++)
		{
			int c = a[i] / N;
			cc += c;
			a[i] -= c * N;
			a[i] -= c;
		}
		for (int i = 0; i < N; i++)
		{
			a[i] += cc;
		}
		cnt += cc;
		if (cc == 0)
		{
			break;
		}
	}

	cout << cnt << endl;
}