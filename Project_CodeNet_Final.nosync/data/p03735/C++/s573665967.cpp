#include <set>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using std::min; using std::max;
using std::swap; using std::sort;
typedef long long ll;

template<typename T>
void read(T &x) {
	int flag = 1; x = 0; char ch = getchar();
	while(ch < '0' || ch > '9') { if(ch == '-') flag = -flag; ch = getchar(); }
	while(ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	x *= flag;
}
#if __cplusplus >= 201103l
template<typename T, typename... V>
void read(T &x, V&... v) { read(x), read(v...); }
#endif

const int _ = 2e5 + 10, Inf = 2e9 + 10;
int n, rmx, rmn = Inf, bmx, bmn = Inf; ll ret;
std::multiset<int> r, b;

struct node {
	int v1, v2;
	node() {}
	node(int _v1, int _v2) { v1 = _v1, v2 = _v2; }
	bool operator < (const node &a) const { return v1 < a.v1; }
} p[_];

ll calc() { return 1ll * (*r.rbegin() - *r.begin()) * (*b.rbegin() - *b.begin()); }

int main () {
	read(n);
	for(int i = 1, x, y; i <= n; ++i) {
		read(x, y); if(x > y) swap(x, y);
		p[i] = node(x, y), r.insert(x), b.insert(y);
	}
	ret = calc(), sort(p + 1, p + n + 1);
	for(int i = 1; i <= n; ++i) {
		int x = p[i].v1, y = p[i].v2;
		r.erase(r.find(x)), b.erase(b.find(y));
		r.insert(y), b.insert(x);
		ret = min(ret, calc());
	}
	printf("%lld\n", ret);
	return 0;
} 
//