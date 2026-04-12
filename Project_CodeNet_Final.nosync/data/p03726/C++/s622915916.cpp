#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <stdio.h>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <list>
#include <utility>
#include <set>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <bitset>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <random>

using namespace std;

static const double EPS = 1e-9;
template<class T> bool INRANGE(T x, T a, T b) { return a <= x&&x <= b; }
template<class T> void amin(T &a, T v) { if (a > v) a = v; }
template<class T> void amax(T &a, T v) { if (a < v) a = v; }
int ROUND(double x) { return (int)(x + 0.5); }
bool ISINT(double x) { return fabs(ROUND(x) - x) <= EPS; }
bool ISEQUAL(double x, double y) { return fabs(x - y) <= EPS*max(1.0, max(fabs(x), fabs(y))); }
double SQSUM(double x, double y) { return x*x + y*y; }
#define PI  (acos(-1))
#define ARRAY_NUM(a) (sizeof(a)/sizeof(a[0])) 
#define NG (-1)
#define BIG ((int)1e9+10)
#define BIGLL ((ll)4e18)
#define SZ(a) ((int)(a).size())
#define SQ(a) ((a)*(a))
typedef unsigned long long ull;
typedef long long ll;



#if 1
vector < vector <int> > adj;
bool found = false;

vector <bool> visited;

int dfs(int now, int prev)
{
	if (visited[now])
	{
		return 0;
	}

	// BEGIN CUT HERE
//	cout << " now=" << now << " prev=" << prev << endl;
	// END CUT HERE
	// 奇数

	int totalChildren = 1;

	int numOddChildren = 0;

	for (int next : adj[now])
	{
		if (next != prev)
		{
			const int numChildren = dfs(next, now);
			if (numChildren % 2)
			{
				numOddChildren++;
			}
			totalChildren += numChildren;
		}
	}

	if (numOddChildren >= 2)
	{
		found = true;
	}

	// BEGIN CUT HERE
//	cout << " now=" << now << " prev=" << prev << " totalChildren=" << totalChildren << " numOddChildren=" << numOddChildren << endl;
	// END CUT HERE


	visited[now] = true;

	return totalChildren;
}

int main()
{
	int n;
	cin >> n;

	found = false;
	adj.clear();
	adj.resize(n);
	visited.clear();
	visited.resize(n);

	for (int i = 0; i < n-1; ++i)
	{
		int a,b;
		cin >> a >> b;
		a--;
		b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	found = false;

	fill(visited.begin(), visited.end(), false);
	dfs(0, NG);

	fill(visited.begin(), visited.end(), false);
	dfs(adj[0][0], NG);


	if (found)
	{
		printf("First\n");
	}
	else
	{
		printf("Second\n");
	}
	return 0;
}



#elif 1

void nuru_bfs(vector< string >& vs, const int y, const int x, const int dist)
{
	queue < pair < pair <int, int>, int> > q;
	q.push(make_pair(make_pair(y, x), dist));
	while (!q.empty())
	{
		pair < pair <int, int>, int> now = q.front();
		const int ny = now.first.first;
		const int nx = now.first.second;
		const int dist = now.second;
		q.pop();

		if (vs[ny][nx] == '.' && dist>=1)
		{
			vs[ny][nx] = 'x';

			if (ny + 1 <= SZ(vs) - 1)
			{
				q.push(make_pair(make_pair(ny + 1, nx), dist-1));
			}
			if (ny - 1 >= 0)
			{
				q.push(make_pair(make_pair(ny - 1, nx), dist-1));
			}
			if (nx + 1 <= SZ(vs[0]) - 1)
			{
				q.push(make_pair(make_pair(ny, nx + 1), dist-1));
			}
			if (nx - 1 >= 0)
			{
				q.push(make_pair(make_pair(ny, nx - 1), dist-1));
			}
		}
	}
	return;
}

int main()
{
	int h,w,k;
	cin >> h >> w >> k;

	vector <string> field(h);
	for (int i = 0; i < h; ++i)
	{
		cin >> field[i];
	}

	int sy, sx;
	for (int y = 0; y < h; ++y)
	{
		for (int x = 0; x < w; ++x)
		{
			if (field[y][x] == 'S')
			{
				sy = y;
				sx = x;
				field[y][x] = '.';
			}
		}
	}

	nuru_bfs(field, sy, sx, k+1);

	int best = BIG;
	for (int y = 0; y < h; ++y)
	{
		for (int x = 0; x < w; ++x)
		{
			if (field[y][x] == 'x')
			{
				int dist = BIG;
				amin(dist, x);
				amin(dist, y);
				amin(dist, abs(x-(w-1)));
				amin(dist, abs(y - (h - 1)));

				int turn = (dist + (k-1))/k;
				amin(best, turn);
			}
		}
	}
	best++;

	cout << best << endl;




}

#elif 1

int main()
{
	int n,m;
	cin >> n >> m;

	vector <ll> sum(n);
	for (int i=0;i<m;i++)
	{
		int a,b;
		cin >> a >> b;
		if (a > b)
		{
			swap(a,b);
		}
		a--;
		b--;

		sum[a]++;
		sum[b]--;
	}

	bool ok = true;
	int value = 0;
	for (int i=0;i<n;i++)
	{
		value += sum[i];
		if(value%2)
		{
			ok = false;
			break;
		}
	}

	if(ok)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
	return 0;
}


#else

int main()
{
	ll a,b,c;
	cin >> a >> b >> c;

	for (int i=0;i<1000000;i++)
	{
		if (a % 2 || b % 2 || c % 2)
		{
			printf("%d\n", i);
			return 0;
		}
		ll na = (b+c)/2;
		ll nb = (c+a)/2;
		ll nc = (a+b)/2;

		a = na;
		b = nb;
		c = nc;
	}

	printf("%d\n", -1);
	return 0;
}

#endif