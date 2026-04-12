
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


string toRight(int i)
{
	if(i % 3 == 0 && i % 5 == 0)
		return "FizzBuzz";

	if(i % 3 == 0)
		return "Fizz";
	
	if(i % 5 == 0)
		return "Buzz";

	stringstream ss;
	ss << i;

	return ss.str();
}

int main()
{
	int n, m;
	while(cin >> n >> m && n)
	{
		vint v(n);
		rep(i, n) v[i] = i + 1;

		int p = 0;
		bool flag = n != 1;
		rep(i, m)
		{
			string in;
			cin >> in;

			if(flag && in != toRight(i + 1))
			{
				v.erase(v.begin() + p);
				
				flag = v.size() != 1;
			}
			else p++;

			p %= v.size();
		}

		rep(i, v.size())
			cout << v[i] << (i + 1 == v.size() ? "\n" : " ");
	}
}