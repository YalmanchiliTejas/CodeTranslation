#include <cstdio>
#include <cmath>

#define incID(i, l, r) for(int i = (l)    ; i <  (r); i++)
#define incII(i, l, r) for(int i = (l)    ; i <= (r); i++)
#define decID(i, l, r) for(int i = (r) - 1; i >= (l); i--)
#define decII(i, l, r) for(int i = (r)    ; i >= (l); i--)
#define inc( i, n) incID(i, 0, n)
#define inc1(i, n) incII(i, 1, n)
#define dec( i, n) decID(i, 0, n)
#define dec1(i, n) decII(i, 1, n)

typedef long long   signed int LL;
typedef long long unsigned int LU;

template<typename T> void swap(T &x, T &y) { T t = x; x = y; y = t; return; }
template<typename T> T abs(T x) { return (0 <= x ? x : -x); }
template<typename T> T max(T a, T b) { return (b <= a ? a : b); }
template<typename T> T min(T a, T b) { return (a <= b ? a : b); }
template<typename T> bool setmin(T &a, T b) { if(a <= b) { return false; } else { a = b; return true; } }
template<typename T> bool setmax(T &a, T b) { if(b <= a) { return false; } else { a = b; return true; } }
template<typename T> T gcd(T a, T b) { return (b == 0 ? a : gcd(b, a % b)); }
template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }

// ---- ----

int h, w;
char a[8][9];
bool ans = false;

int main() {
	scanf("%d%d", &h, &w);
	inc(i, h) { scanf("%s", a[i]); }
	
	int memo[8][8];
	inc(i, 1 << (h + w - 1)) {
		inc(j, h) {
		inc(k, w) {
			memo[j][k] = 0;
		}
		}
		
		int hh = 0, ww = 0;
		bool flag1 = true;
		inc(j, h + w - 1) {
			if(hh < h && ww < w) { memo[hh][ww] = 1; } else { flag1 = false; break; }
			if(i & (1 << j)) { hh++; } else { ww++; }
		}
		if(! flag1) { continue; }
		
		inc(j, h) {
		inc(k, w) {
			if( (a[j][k] == '#') == (memo[j][k] == 1) ) { } else { flag1 = false; j = k = w + h; }
		}
		}
		if(flag1) { ans = true; break; }
	}
	
	printf("%s\n", ans ? "Possible" : "Impossible");
	
	return 0;
}
