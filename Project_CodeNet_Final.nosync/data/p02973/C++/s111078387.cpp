#include <bits/stdc++.h>
//#include<unordered_map>
#define debug(x) (cout << "#x = " << (x) << endl)
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)
//#define mid (l + r >> 1)
#define lowbit(x) (x & -x)
#define Set(x, i) memset(x, i, sizeof x)
#define R register
#define For( i, j, k ) for(R int i = (j); i <= (k); ++i)
#define foR( i, j, k ) for(R int i = (j); i >= (k); --i)
#define Cross( i, j, k ) for(R int i = (j); i; i = (k))using namespace std;
typedef long long ll;
using namespace std;
const ll N = 1000011;
const ll Inf = 0x3f3f3f3f3f3f;

namespace IO {

	#define dd ch = getchar()
	inline ll read() {
		ll x = 0; bool f = 0; char dd;
		for (; !isdigit (ch); dd) f ^= (ch == '-');
		for (; isdigit (ch); dd)  x = x * 10 + (ch ^ 48);
		return f? -x: x;
	}
	#undef dd

	inline void write ( ll x ) {
		if (x < 0) putchar ('-'), x = -x;
		if (x > 9) write (x / 10); putchar ( x % 10 | 48 );
	}

	inline void wrn ( ll x ) { write(x); putchar (' '); }

	inline void wln ( ll x ) { write(x); putchar ('\n'); }

	inline void wlnn ( ll x, ll y ) { wrn(x); wln (y); }

}

using namespace IO;

namespace Cesare {
	
	#define int long long
	
	ll n, Ans = 0, a[N], b[N], f[N], l[N];
	
	#define ls(x) (x << 1)
	#define rs(x) (x << 1 | 1)
	#define mid ((l + r) >> 1)
	
	ll T[N << 2];
	
	inline void pushUp ( ll p ) { T[p] = T[ls(p)] + T[rs(p)]; }
	
	inline void Update ( ll p, ll l, ll r, ll x, ll k ) {
		if (l == r) return (void) (T[p] = k);
		if (mid >= x) Update(ls(p), l, mid, x, k);
		if (mid < x)  Update(rs(p), mid + 1, r, x, k); pushUp(p);
	}
	
	inline ll Query ( ll p, ll l, ll r, ll ul, ll ur, ll res = 0 ) {
		if (ul > ur) return 0;
		if (l >= ul && r <= ur) return T[p];
		if (mid >= ul) res += Query(ls(p), l, mid, ul, ur);
		if (mid < ur)  res += Query(rs(p), mid + 1, r, ul, ur);
		return res;
	}
	
	struct cmp{bool operator()(int a,int b){return a>b;}};
	
	int main() {
		Set (T, 0); n = read();
		For ( i, 1, n ) a[i] = read();
		
		int con=1,Ans=1;
		l[1]=f[1]=a[1];
		for(int i=2;i<=n;i++)
		{
			if(l[Ans]>=a[i])l[++Ans]=a[i];
			else l[upper_bound(l+1,l+Ans+1,a[i],cmp())-l]=a[i];
			if(f[con]<a[i])f[++con]=a[i];
			else f[lower_bound(f+1,f+con+1,a[i])-f]=a[i];
		} return wln(Ans), 0;
	}
	
}

signed main()
{
	return Cesare::main();
}

/*

*/

