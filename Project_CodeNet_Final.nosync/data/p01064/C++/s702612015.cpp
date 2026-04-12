#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <limits>
#include <functional>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) __typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

int main() {
	int N;
	while(~scanf("%d", &N)) {
		int a; int d;
		scanf("%d%d", &a, &d);
		int Q;
		scanf("%d", &Q);
		vector<int> x(Q), y(Q), z(Q);
		for(int i = 0; i < Q; ++ i)
			scanf("%d%d%d", &x[i], &y[i], &z[i]), -- y[i], -- z[i];
		int K;
		scanf("%d", &K), -- K;
		vi ops;
		for(int i = Q - 1; i >= 0; -- i) {
			if(!(y[i] <= K && K <= z[i])) continue;
			if(x[i] == 0) {
				K = z[i] - K + y[i];
			} else if(x[i] == 1) {
				ops.push_back(1);
			} else if(x[i] == 2) {
				ops.push_back(2);
			}
		}
		reverse(all(ops));
		int val = a + d * K;
		each(i, ops) {
			if(*i == 1) {
				++ val;
			} else {
				val /= 2;
			}
		}
		printf("%d\n", val);
	}
	return 0;
}