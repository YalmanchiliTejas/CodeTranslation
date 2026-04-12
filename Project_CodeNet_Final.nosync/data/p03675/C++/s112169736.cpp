/*{{{*/
#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = (x), _ = (y); i <= _; ++ i)
#define per(i, x, y) for(int i = (x), _ = (y); i >= _; -- i)
#define dprintf(...) fprintf(stderr, __VA_ARGS__)
#define disp(x) cout << #x << " = " << x << "; "

typedef long long LL;

template <class T> bool chkmin(T& a, T b) { return a > b ? a = b, true : false; }
template <class T> bool chkmax(T& a, T b) { return a < b ? a = b, true : false; }

template <class T> void read(T& a) {
	char c = getchar(); 
	T f = 1; 
	a = 0;
	for(; !isdigit(c); c = getchar()) if(c == '-') f = -1;
	for(; isdigit(c); c = getchar()) a = a * 10 + c - '0';
	a *= f;
}
/*}}}*/

const int maxN = 2e5 + 5;

int outp[maxN];
int a[maxN];
int l, r;
int N;

int main()
{
	read(N);
	read(outp[l = r = 100000]);
	rep(i, 2, N)
	{
		int x;
		read(x);
		if(((N - i) & 1) == 0)
			outp[--l] = x;
		else
			outp[++r] = x;
	}
	rep(i, l, r)
		printf("%d ", outp[i]); puts("");

	return 0;
}
