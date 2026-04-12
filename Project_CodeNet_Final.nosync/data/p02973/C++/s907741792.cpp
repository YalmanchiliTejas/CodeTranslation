#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cmath>
#include <numeric>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <unordered_map>
#include <tuple>
#include <complex>


#define FOR(i, a, b)		for(int i = (int)(a); i < (int)(b); ++i)
#define FORE(i, a, b)		for(int i = (int)(a); i <= (int)(b); ++i)
#define REP(i, n)			FOR(i, 0, n)
#define REPE(i, n)			FORE(i, 0, n)
#define ALL(x)				(x).begin(),(x).end()
#define DEBUG_DC(x)			cout << #x << ": " << x << endl
#define VEC_TYPE			int
#define INF					1e5+1

using namespace std;
typedef long long ll;
typedef vector<VEC_TYPE> vdef;
typedef vector<vdef> vvdef;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmaxE(T& a, T b) { if (a <= b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T> inline bool chminE(T& a, T b) { if (a >= b) { a = b; return 1; } return 0; }
template<typename T> inline T mygcd(T a, T b) { return b ? mygcd(b, a%b) : a; }
template<typename T> inline T mylcm(T a, T b) { return a * b / mygcd(a, b); }

int main()
{
	int ans = 0;
	int n;
	cin >> n;
	vdef a(n, 0);
	for (int i = 0; i < n; ++i) cin >> a[i];

	vdef color;
	color.emplace_back(a[0]);

	for (int i = 1; i < n; ++i)
	{
		if (color[0] < a[i])
		{
			color[0] = a[i];
		}
		else if (color[color.size() - 1] >= a[i])
		{
			color.emplace_back(a[i]);
		}
		else
		{
			for (int j = 0; j < color.size(); ++j)
			{
				if (color[j] < a[i])
				{
					color[j] = a[i];
					break;
				}
			}
		}
	}

	ans = color.size();
	cout << ans << endl;
	return 0;
}