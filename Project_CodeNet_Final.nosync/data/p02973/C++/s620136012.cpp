#include <bits/stdc++.h>

#define I inline
#define fi first
#define se second
#define R register
#define LL long long
#define mp make_pair
#define reg register int
#define pii pair<int,int>
#define cr const reg&
using namespace std;
const int inf = 2147483647;
const int N = 1e5 + 1;

I int _max(cr x, cr y) {return x > y ? x : y;}
I int _min(cr x, cr y) {return x < y ? x : y;}
I int read() {
	reg x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
	return x * f;
}
I void ptt(cr x) {if(x >= 10) ptt(x / 10); putchar(x % 10 + '0');}
I void put(cr x) {x < 0 ? putchar('-'), ptt(-x) : ptt(x);}
I void pr1(cr x) {put(x), putchar(' ');}
I void pr2(cr x) {put(x), puts("");}

multiset<int> s;
int a[N];

int main() {
	reg n = read();
	for(reg i = 1; i <= n; i++) a[i] = read();
	reg sum = 0;
	for(reg i = n; i >= 1; i--) {
		auto u = s.upper_bound(a[i]);
		if(u == s.end()) sum++, s.insert(a[i]);
		else {
			s.erase(u);
			s.insert(a[i]);
		}
	} pr2(sum);
	return 0;
}

