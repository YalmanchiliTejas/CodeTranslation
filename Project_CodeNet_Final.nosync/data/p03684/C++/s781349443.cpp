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

struct St
{
	int index;
	int n;
	bool operator < (const St &st) const
	{
		return (n < st.n);
	}
};

struct Sub
{
	int from;
	int to;
	int sub;
	Sub(int from, int to, int sub)
	{
		this->from = from;
		this->to = to;
		this->sub = sub;
	}
	bool operator < (const Sub &st) const
	{
		return (sub > st.sub);
	}
};

int N;
St sorted_x[100000] = {};
St sorted_y[100000] = {};
int table_x[100000] = {};
int table_y[100000] = {};
bool flg[100000] = {};

priority_queue<Sub> q;

signed main()
{
	cin >> N;
	REP(i, N)
	{
		int x, y;
		cin >> x >> y;
		sorted_x[i].index = i;
		sorted_x[i].n = x;
		sorted_y[i].index = i;
		sorted_y[i].n = y;
	}

	ARY_SORT(sorted_x, N);
	ARY_SORT(sorted_y, N);

	REP(i, N)
	{
		table_x[sorted_x[i].index] = i;
		table_y[sorted_y[i].index] = i;
	}

	int cnt = 0;
	int ans = 0;
	int next = 0;
	flg[0] = true;
	while (true)
	{
		int x = sorted_x[table_x[next]].n;
		int y = sorted_y[table_y[next]].n;
		int xi = table_x[next];
		int yi = table_y[next];

		if (xi > 0)
		{
			int sub = abs(x - sorted_x[xi - 1].n);
			q.push(Sub(sorted_x[xi].index, sorted_x[xi - 1].index, sub));
		}
		if (yi > 0)
		{
			int sub = abs(y - sorted_y[yi - 1].n);
			q.push(Sub(sorted_y[yi].index, sorted_y[yi - 1].index, sub));
		}
		if (xi < N - 1)
		{
			int sub = abs(x - sorted_x[xi + 1].n);
			q.push(Sub(sorted_x[xi].index, sorted_x[xi + 1].index, sub));
		}
		if (yi < N - 1)
		{
			int sub = abs(y - sorted_y[yi + 1].n);
			q.push(Sub(sorted_y[yi].index, sorted_y[yi + 1].index, sub));
		}

		while (true)
		{
			Sub s = q.top();
			q.pop();
			if (!flg[s.to])
			{
				ans += s.sub;
				flg[s.to] = true;
				next = s.to;
				break;
			}
		}

		cnt++;
		if (cnt >= N - 1) break;
	}

	cout << ans << endl;
}
