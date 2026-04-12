#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cassert>
#include <iostream>
#include <cctype>
#include <sstream>
#include <string>
#include <list>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <bitset>
#include <complex>
#include <fstream>
#include <iomanip>
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
typedef vector<int> vint;
typedef pair<int, int> pint;
#define rep(i, n) REP(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for(int i = x; i < n; i++)
template<class T> T RoundOff(T a){ return int(a+.5-(a<0)); }
template<class T, class C> void chmax(T& a, C b){ if(a < b) a = b; }
template<class T, class C> void chmin(T& a, C b){ if(b < a) a = b; }
template<class T, class C> pair<T, C> mp(T a, C b){ return make_pair(a, b); }


int tanri(int year, int money, double c, double b)
{
	int pool = 0;
	rep(i, year)
	{
		pool += money * c;
		money -= b;
	}

	return money + pool;
}

int hukuri(int year, int money, double c, double b)
{
	rep(i, year)
	{
		money *= 1.0 + c;
		money -= b;
	}

	return money;
}

int main()
{
	int m;
	cin >> m;
	while(m--)
	{
		double money, year, n;
		cin >> money >> year >> n;

		int res = 0;
		rep(i, n)
		{
			double f, c, b;

			cin >> f >> c >> b;
			

			if(!f) chmax(res, tanri(year, money, c, b));
			else  chmax(res, hukuri(year, money, c, b));
		}

		cout << res << endl;
	}
}