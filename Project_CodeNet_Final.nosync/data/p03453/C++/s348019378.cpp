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

#define int long long
#define CONTAINS(v,n) (find((v).begin(), (v).end(), (n)) != (v).end())
#define SORT(v) sort((v).begin(), (v).end())
#define RSORT(v) sort((v).rbegin(), (v).rend())
#define ARY_SORT(a, size) sort((a), (a)+(size))
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define REMOVE(v,a) (v.erase(remove((v).begin(), (v).end(), (a)), (v).end()))
#define REVERSE(v) (reverse((v).begin(), (v).end()))
#define LOWER_BOUND(v,a) (lower_bound((v).begin(), (v).end(), (a)))
#define UPPER_BOUND(v,a) (upper_bound((v).begin(), (v).end(), (a)))
#define REP(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define CONTAINS_MAP(m, a) (m).find((a)) != m.end()
using namespace std;

using P = pair<int, int>;

int N, M;
int S, T;
vector<P> link[200001];

const int O = 1000000007;

int dik[200001];
bool used[200001];

vector<P> route[200001];
vector<P> inv_route[200001];
int link_count[200001];
int inv_link_count[200001];

int add(int a, int b)
{
	return (a + b) % O;
}

int sub(int a, int b)
{
	return (a + O - b) % O;
}

int mul(int a, int b)
{
	return (a * b) % O;
}

signed main()
{
	cin >> N >> M;
	cin >> S >> T;
	REP(i, M)
	{
		int u, v, d;
		cin >> u >> v >> d;
		link[u].push_back(P(v, d));
		link[v].push_back(P(u, d));
	}

	REP(i, N + 1) dik[i] = INT64_MAX;
	dik[S] = 0;
	priority_queue<P, vector<P>, greater<P>> q;
	q.push(P(0, S));
	while (q.size() > 0)
	{
		int d, p;
		tie(d, p) = q.top();
		q.pop();
		if (used[p]) continue;
		used[p] = true;
		for (P l : link[p])
		{
			int new_len = d + l.second;
			if (dik[l.first] == new_len)
			{
				inv_route[l.first].push_back(P(p, l.second));
			}
			if (dik[l.first] > new_len)
			{
				dik[l.first] = new_len;
				inv_route[l.first].clear();
				inv_route[l.first].push_back(P(p, l.second));
				if (l.first != T)
				{
					q.push(P(new_len, l.first));
				}
			}
		}
	}

	int max_len = dik[T];

	memset(used, 0, sizeof(used));
	q.push(P(0, T));
	inv_link_count[T] = 1;
	while (!q.empty())
	{
		int d, p;
		tie(d, p) = q.top();
		q.pop();
		if (used[p]) continue;
		used[p] = true;
		for (P r : inv_route[p])
		{
			inv_link_count[r.first] = add(inv_link_count[r.first], inv_link_count[p]);
			route[r.first].push_back(P(p, r.second));
			q.push(P(d + r.second, r.first));
		}
	}
	int all_cnt = inv_link_count[S];

	memset(used, 0, sizeof(used));
	q.push(P(0, S));
	link_count[S] = 1;
	while (!q.empty())
	{
		int d, p;
		tie(d, p) = q.top();
		q.pop();
		if (used[p]) continue;
		used[p] = true;
		for (P r : route[p])
		{
			link_count[r.first] = add(link_count[r.first], link_count[p]);
			q.push(P(d + r.second, r.first));
		}
	}

	int sum = 0;
	double half = max_len / 2.0;

	int all_cnt2 = mul(all_cnt, all_cnt);

	for (int i = 1; i < N + 1; i++)
	{
		if (dik[i] == half) //あやしい
		{
			int a = mul(link_count[i], inv_link_count[i]);
			int b = sub(all_cnt, a);
			int c = mul(a, b);
			sum = add(sum, c);
		}
		else if(dik[i] < half)
		{
			for (P l : route[i])
			{
				int d = dik[i] + l.second;
				if (d > half)
				{
					int a = mul(link_count[i], inv_link_count[l.first]);
					int b = sub(all_cnt, a);
					int c = mul(a, b);
					sum = add(sum, c);
				}
			}
		}
	}
	cout << sum << endl;;
}





