#include <algorithm>
#include <iostream>
#include <cstdio>
#include <ctime>
#include <limits.h>
#define N 200005

using namespace std;

int n;
int x[N], y[N];
int Rmax, Rmin, Bmax, Bmin;
long long ans = 1e18;

inline void cmin(int &u, int v) { if(u > v) u = v; }
inline void cmax(int &u, int v) { if(u < v) u = v; }
inline void read(int &x) {
	x = 0; char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
}

inline long long judge(int x, int y) {
	static int trmax, trmin, tbmax, tbmin;
	trmax = max(x, Rmax), trmin = min(x, Rmin);
	tbmax = max(y, Bmax), tbmin = min(y, Bmin);
	return 1ll * (trmax - trmin) * (tbmax - tbmin);
}
inline void change(int x, int y) {
	cmax(Rmax, x), cmin(Rmin, x);
	cmax(Bmax, y), cmin(Bmin, y);
	return;
}

int main() {
	read(n);
	for(int i = 1; i <= n; ++i)
		read(x[i]), read(y[i]);
	
	srand(time(0));
	int tim = 50;
	while(tim --) {
		Rmax = Bmax = INT_MIN;
		Rmin = Bmin = INT_MAX;
		for(int i = 1; i <= n; ++i) {
			int p = rand() % n + 1;
			swap(x[i], x[p]), swap(y[i], y[p]);
		}
		for(int i = 1; i <= n; ++i) {
			if(judge(x[i], y[i]) < judge(y[i], x[i])) {
				change(x[i], y[i]);
			} else {
				change(y[i], x[i]);
			}
		}
		long long res = 1ll * (Rmax - Rmin) * (Bmax - Bmin);
		if(ans > res) ans = res;
	}
	cout << ans << endl;
	return 0;
}