#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair

const int MAXN = 100;
const int MOD = int(1E9) + 7;

inline int add(int x, int y) {x += y; return x >= MOD ? x - MOD : x;}
inline int sub(int x, int y) {x -= y; return x < 0 ? x + MOD : x;}
inline int mul(int x, int y) {return 1LL * x * y % MOD;}

int pow_mod(int b, int p) {
	int ret = 1;
	for(int i=p;i;i>>=1,b=mul(b,b))
		if( i & 1 ) ret = mul(ret, b);
	return ret;
}

int h[MAXN + 5], N;
pii get(int l, int r, int lh) {
	int mn = h[l];
	for(int i=l;i<=r;i++)
		mn = min(mn, h[i]);
	
	int lst = l; pii ret = mp(1, 1);
	for(int i=l;i<=r;i++) {
		if( h[i] == mn ) {
			if( i > lst ) {
				pii tmp = get(lst, i - 1, mn);
				ret.fi = mul(ret.fi, tmp.fi);
				ret.se = mul(ret.se, add(mul(2, tmp.fi), tmp.se));
			}
			ret.se = mul(ret.se, 2);
			
			lst = i + 1;
		}
	}
	if( r >= lst ) {
		pii tmp = get(lst, r, mn);
		ret.fi = mul(ret.fi, tmp.fi);
		ret.se = mul(ret.se, add(mul(2, tmp.fi), tmp.se));
	}
	
	return mp(mul(ret.fi, pow_mod(2, mn - lh)), sub(ret.se, mul(2, ret.fi)));
}

int main() {
	scanf("%d", &N);
	for(int i=1;i<=N;i++) scanf("%d", &h[i]);
	
	pii k = get(1, N, 0);
	printf("%d\n", add(k.fi, k.se));
}