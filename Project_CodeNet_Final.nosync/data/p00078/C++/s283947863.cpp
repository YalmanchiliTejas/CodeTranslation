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

struct P{ P(int x, int y) : x(x), y(y) {} int x, y;	};

int main()
{
	int n;
	while(cin >> n && n)
	{
		vector<vint> field(n, vint(n, -1));

		P p = P(n/2, n/2+1);
		rep(i, n*n)
		{
			if(field[p.y][p.x] == -1)
			{
				field[p.y][p.x] = i + 1;
			}
			else
			{
				while(field[p.y][p.x] != -1)
				{
					if(field[(p.y + 1) % n][(p.x + 1) % n] == -1)
					{
						p = P((p.x + 1) % n, (p.y + 1) % n);
						break;
					}
				
					p = P(p.x, (p.y + 2) % n);
				}
				i--;
			}
		}

		rep(i, n)
		{
			rep(j, n)
				printf("%4d", field[i][j]);
			cout << endl;
		}
	}
}