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
#include<iomanip>

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

vector<string> pmap;
bool skip[101];

signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int H, W;
	string s;

	cin >> H >> W;
	rep(i, 0, H)
	{
		cin >> s;
		if (count(all(s), '#') > 0)
		{
			pmap.push_back(s);
		}
	}

	int j = 0;
	rep(j, 0, W)
	{
		skip[j] = true;
		rep(i, 0, SZ(pmap))
		{
			if (pmap[i][j] == '#')
			{
				skip[j] = false;
				break;
			}
		}
	}

	rep(i, 0, SZ(pmap))
	{
		rep(j, 0, W)
		{
			if (skip[j])continue;
			cout << pmap[i][j];
		}
		cout << endl;
	}

	return 0;
}