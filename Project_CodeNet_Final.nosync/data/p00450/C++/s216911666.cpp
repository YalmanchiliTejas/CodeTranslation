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
#define rep(i,s,n) for(long long i = (s); (n) > i; i++)
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
	{ -1 ,0 },{ 0 ,1 },
	{ 1 ,0 },{ 0,-1 }
};
struct UnionFind {
	vector<int> data;
	UnionFind(int size) : data(size, -1) { }
	bool unionSet(int x, int y) { //????????\??£??????????????¨ y?????\??£?????????????????????
		x = root(x); y = root(y);
		if (x != y) {
			//if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool findSet(int x, int y) { //x??¨y????????????????????\??£??????????????????????????????
		return root(x) == root(y);
	}
	int root(int x) {
		return data[x] < 0 ? x : data[x] = root(data[x]);
	}
	int size(int x) {
		return -data[root(x)];
	}
	bool isroot(int x) {
		return data[x] < 0;
	}
};
signed main() {
	int n;
	while (scanf("%d", &n)) {
		if (!n)
			break;
		int bef = -1;
		UnionFind uf(n);
		vector<int> uft(n);
		REP(i, n) {
			int cur;
			scanf("%d", &cur);
			if (i % 2) {
				uf.unionSet(i - 1, i);
				if (uf.root(i)) {
					if(uft[uf.root(uf.root(i)-1)] == cur)
						uf.unionSet(uf.root(i) - 1, i);				
				}
			}
			else if (cur == bef) {
				uf.unionSet(i - 1, i);
			}
			bef = cur;
			uft[uf.root(i)] = cur;
		}
		int ans = 0;
		REP(i, n) {
			if (uf.isroot(i) && !uft[uf.root(i)]) {
				ans += uf.size(i);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}