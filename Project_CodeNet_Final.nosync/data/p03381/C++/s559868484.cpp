#include <bits/stdc++.h>
#define For(i, l, r) for(int i = (l), i##end = (int)(r); i <= i##end; ++i)
#define Fordown(i, r, l) for(int i = (r), i##end = (int)(l); i >= i##end; --i)
#define Set(a, v) memset(a, v, sizeof(a))
using namespace std;

bool chkmin(int &a, int b) {return b < a ? a = b, 1 : 0;}
bool chkmax(int &a, int b) {return b > a ? a = b, 1 : 0;}

inline int read() {
    int x = 0, fh = 1; char ch = getchar();
    for (; !isdigit(ch); ch = getchar() ) if (ch == '-') fh = -1;
    for (; isdigit(ch); ch = getchar() ) x = (x<<1) + (x<<3) + (ch ^ '0');
    return x * fh;
}

const int N = 2e5 + 1e3;
int n, a[N], b[N];

int main () {
	n = read();
	For (i, 1, n) b[i] = a[i] = read();
	sort(a + 1, a + 1 + n);

	int mid = n >> 1;
	For (i, 1, n)
		printf ("%d\n", b[i] <= a[mid] ? a[mid + 1] : a[mid]);
    return 0;
}
