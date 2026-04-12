#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <complex>

#define pb push_back
#define mp make_pair
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define tr(c, i) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define rtr(c, i) for (typeof((c).rbegin()) i = (c).rbegin(); i != (c).rend(); --i)
#define contains(c, x) ((c).find(x) != (c).end())
#define Contains(c, x) (find(all(c), x) != (c).end())
#define REP(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) REP(i, 0, (n))
#define To_String to_string< char,std::char_traits<char>,std::allocator<char> >

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int a[20][20];
int main()
{
	ios_base::sync_with_stdio(0);
	int n;
	while (scanf("%d", &n), n) {
		memset(a, 0, sizeof(a));
		int r = n/2+1, c = n/2;
		int k = 1;
		a[r][c] = 1;
		r++, c++;
		while (k < n*n) {
			if (0 <= r && r < n) {
				if (0 <= c && c < n) {
					if (a[r][c] == 0) {
						a[r][c] = ++k;
						r++, c++;
					}
					else {
						r++, c--;
					}
				}
				else if (c >= n) { c = 0; }
				else if (c < 0) { c = n-1; }
			}
			else if (r >= n) { r = 0; }
		}
		rep(i, n) {
			rep(j, n) printf("%4d", a[i][j]);
			puts("");
		}
	}
	return 0;
}