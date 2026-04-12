#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <functional>
#include <array>
#include <map>
#include <queue>
#include <limits.h>
#include <set>
#include <stack>
#include <random>
#define rep(i,s,n) for(int i = (s); (n) > i; i++)
#define REP(i,n) rep(i,0,n)
#define RANGE(x,a,b) ((a) <= (x) && (x) <= (b))
#define DUPLE(a,b,c,d) (RANGE(a,c,d) || RANGE(b,c,d) || RANGE(c,a,b) || RANGE(d,a,b))
#define INCLU(a,b,c,d) (RANGE(a,c,d) && (b,c,d))
#define POWT(x) ((x)*(x))
#define ALL(x) (x).begin(), (x).end()
#define MODU 1000000007
#define bitcheck(a,b)   ((a >> b) & 1)
#define bitset(a,b)      ( a |= (1 << b))
#define bitunset(a,b)    (a &= ~(1 << b))
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

const pii four_Dir[4] = {
	{ 0,-1 },{ -1 ,0 },{ 0 ,1 },
	{ 1 ,0 }
};
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T &val) {
	std::fill((T*) array, (T*) (array + N), val);
}

signed main() {
	int h, w;
	scanf("%d %d", &h, &w);
	vector<vector<char>> m(h + 2, vector<char>(w + 2));
	int c = 0;
	REP(i, h) {
		scanf("%*c");
		REP(j, w) {
			scanf("%c", &m[i + 1][j + 1]);
			if (m[i + 1][j + 1] == '#')
				c++;
		}
	}
	if (c != (h + w - 1)) {
		printf("Impossible\n");
		return 0;
	}
	m[0][1] = '#';
	m[h][w - 1] = '#';
	rep(i, 1, h) {
		rep(j, 1, w) {
			if (m[i][j] == '#') {
				if (m[i + 1][j] == '#' && m[i][j + 1] == '#') {
					printf("Impossible\n");
					return 0;
				}
				if (m[i + 1][j] != '#' && m[i][j + 1] != '#') {
					printf("Impossible\n");
					return 0;
				}
				if (m[i - 1][j] == '#' && m[i][j - 1] == '#') {
					printf("Impossible\n");
					return 0;
				}
				if (m[i - 1][j] != '#' && m[i][j - 1] != '#') {
					printf("Impossible\n");
					return 0;
				}
			}
		}
	}
	printf("Possible\n");
	return 0;
}