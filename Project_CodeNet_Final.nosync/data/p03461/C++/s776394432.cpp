#include <bits/stdc++.h>
#define For(i, l, r) for(register int i = (l), i##end = (int)(r); i <= i##end; ++i)
#define Fordown(i, r, l) for(register int i = (r), i##end = (int)(l); i >= i##end; --i)
#define Set(a, v) memset(a, v, sizeof(a))
using namespace std;

inline bool chkmin(int &a, int b) {return b < a ? a = b, 1 : 0;}
inline bool chkmax(int &a, int b) {return b > a ? a = b, 1 : 0;}

inline int read() {
    int x = 0, fh = 1; char ch = getchar();
    for (; !isdigit(ch); ch = getchar() ) if (ch == '-') fh = -1;
    for (; isdigit(ch); ch = getchar() ) x = (x << 1) + (x << 3) + (ch ^ 48);
    return x * fh;
}

void File() {
#ifdef zjp_shadow
	freopen ("E.in", "r", stdin);
	freopen ("E.out", "w", stdout);
#endif
}

const int N = 310;
int A, B, n, d[N][N], f[N][N];

int main () {
	File();

	n = 149;
	A = read(); B = read();
	For (i, 1, A) For (j, 1, B) d[i][j] = read();

	For (i, 0, n) For (j, 0, n)
		For (a_, 1, A) For (b_, 1, B)
			chkmax(f[i][j], d[a_][b_] - a_ * i - b_ * j);

	For (a_, 1, A) For (b_, 1, B) {
		int res = 0x7f7f7f7f;
		For (i, 0, n) For (j, 0, n)
			chkmin(res, f[i][j] + a_ * i + b_ * j);
		if (res != d[a_][b_]) return puts("Impossible"), 0;
	}

	puts("Possible");
	
	printf ("%d %d\n", n * 2 + 2, n * 2 + (n + 1) * (n + 1));
	int S = 1, T = n + 2;
	For (i, 1, n)
		printf ("%d %d X\n", i, i + 1);

	For (i, 1, n)
		printf ("%d %d Y\n", i + n + 2, i + n + 1);

	For (i, 0, n) For (j, 0, n)
		printf ("%d %d %d\n", i + 1, j + n + 2, f[i][j]);

	printf ("%d %d\n", S, T);
    return 0;
}
