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
template<class T> inline bool chmaxe(T& a, T b) { if (a <= b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T>inline T mygcd(T a, T b) { return b ? mygcd(b, a%b) : a; }
template<typename T>inline T mylcm(T a, T b) { return a * b / mygcd(a, b); }


int main()
{
	int n;
	cin >> n;
	int ans = 0;
	int maxh = 0;

	for (int i = 0; i < n; ++i)
	{
		int h;
		cin >> h;

		if (chmaxe(maxh, h))
		{
			++ans;
		}
	}

	cout << ans << endl;
	return 0;
}