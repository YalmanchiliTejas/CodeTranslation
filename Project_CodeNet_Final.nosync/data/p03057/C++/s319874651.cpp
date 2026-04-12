#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#ifdef DEBUG
#define display(x) cerr << #x << " = " << x << endl;
#define displaya(a, st, n)\
	{cerr << #a << " = {";\
	for(int qwq = (st); qwq <= (n); ++qwq) {\
		if(qwq == (st)) cerr << a[qwq];\
		else cerr << ", " << a[qwq];\
	} cerr << "}" << endl;}
#define displayv(v) displaya(v, 0, (int)(v).size() - 1)
#endif
template<typename T> bool chmin(T &a, const T &b) { return a > b ? a = b, true : false; }
template<typename T> bool chmax(T &a, const T &b) { return a < b ? a = b, true : false; }

const int maxN = 200000 + 233;
const LL P = 1000000007;
int n, m;
char s[maxN];
LL f[maxN];

LL purity() {
	LL f00 = 1, f11 = 1, f01 = 0, f10 = 0;
	// '11' is not OK
	for(int i = 2; i <= n; ++i) {
		LL g00 = f00 + f01, g01 = f00,
		   g10 = f10 + f11, g11 = f10;
		f00 = g00 % P; f01 = g01;
		f10 = g10 % P; f11 = g11;
	}
	return (f00 + f01 + f10) % P;
}

LL recur(int lim) {
	// sum( x ^ (p + 1) )
	// sum( (c + 1) * x ^ (p + 1) )
//	display(lim);
	memset(f, 0, sizeof(f));
	f[0] = 1; f[1] = 0; f[2] = 1; f[3] = 0;
	for(int i = 4; i <= n; ++i) {
		f[i] = f[i - 2] * 2 % P;
		if(i - lim - 3 >= 0) f[i] = (f[i] + P - f[i - lim - 3]) % P;
	}
//	displaya(f, 0, n);
	LL ans = 0;
	for(int i = 1; i <= lim; i += 2) if(n - i - 1 >= 0)
		(ans += f[n - i - 1] * (i + 1)) %= P;
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m >> (s + 1);
	assert((int)strlen(s + 1) == m);
	char major = s[1], minor = (int)'R' + 'B' - major;
	int cons = 0;
	int mn = maxN;
	bool first = true;
	for(int i = 1; i <= m; ++i) {
		if(s[i] == major) cons++;
		else {
			if(first) chmin(mn, cons | 1), cons = 0, assert(s[i] == minor), first = false;
			else if(cons & 1) chmin(mn, cons), cons = 0, assert(s[i] == minor);
			else cons = 0;
		}
	}
	if(mn == maxN) cout << purity() << endl;
	else cout << recur(mn) << endl;
	return 0;
}
