/*--------------------------------
  Author: The Ace Bee
  Blog: www.cnblogs.com/zsbzsb
  This code is made by The Ace Bee
--------------------------------*/
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <ctime>
#include <set>
#define rg register
using namespace std;
typedef long long LL;
template < typename T > inline void read(T& s) {
	s = 0; int f = 0; char c = getchar();
	while (!isdigit(c)) f |= (c == '-'), c = getchar();
	while (isdigit(c)) s = s * 10 + (c ^ 48), c = getchar();
	s = f ? -s : s;
}
const int _ = 200010;
int n;
struct node{ int a, b; }t[_];
inline bool cmp(const node& x, const node& y) { return x.a < y.a; }
multiset < int > L, R;
inline LL calc()
{ return 1ll * (*L.rbegin() - *L.begin()) * (*R.rbegin() - *R.begin()); }
int main() {
	read(n);
	for (rg int a, b, i = 1; i <= n; ++i) {
		read(a), read(b);
		if (a > b) swap(a, b);
		t[i] = (node) { a, b };
		L.insert(a), R.insert(b);
	}
	LL ans = calc();
	sort(t + 1, t + n + 1, cmp);
	for (rg int i = 1; i <= n; ++i) {
		int a = t[i].a;
		int b = t[i].b;
		L.erase(L.find(a)), R.insert(a);
		R.erase(R.find(b)), L.insert(b);
		ans = min(ans, calc());
	}
	printf("%lld\n", ans);
	return 0;
}
//asfdadf
