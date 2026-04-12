#define _USE_MATH_DEFINES
#include<cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <algorithm>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <iterator>

using namespace std;

#define rep(i,a,b) for(int i=(a), i##_len=(b);i<i##_len;i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)

#define int ll
#define SZ(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

typedef long long ll;
//typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<double, double> pdd;
typedef vector<vector<int>> mat;
//typedef unsigned int uint;

template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;

int N, M;
int G[10][10];

int dfs(int p, int t, int checked)
{
	if (t == N)
	{
		return 1;
	}

	int res = 0;
	rep(i, 0, N)
	{
		if (G[p][i] == 1 && (checked&(1 << i)) == 0)
		{
			res+=dfs(i, t + 1, checked | (1 << i));
		}
	}

	return res;
}

signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	int x, y;
	rep(i, 0, M)
	{
		cin >> x >> y;
		x--;
		y--;
		G[x][y] = 1;
		G[y][x] = 1;
	}

	cout << dfs(0, 1, 1) << endl;

	return 0;
}