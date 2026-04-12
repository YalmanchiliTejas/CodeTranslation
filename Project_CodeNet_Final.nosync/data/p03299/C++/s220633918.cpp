#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sqr(a) ((a) * (a))
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define forn(i, n) for(int i = 0; i < int(n); i++) 
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template <class A, class B> ostream& operator << (ostream& out, const pair<A, B> &a) {
	return out << "(" << a.x << ", " << a.y << ")";
}

template <class A> ostream& operator << (ostream& out, const vector<A> &v) {
	out << "[";
	forn(i, sz(v)) {
		if(i) out << ", ";
		out << v[i];
	}
	return out << "]";
}

mt19937 rnd(time(NULL));

const int INF = int(1e9);
const li INF64 = li(1e18);
const int MOD = INF + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

const int N = 100 + 7;

int n;
int a[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n)
		scanf("%d", &a[i]);
	return true;
}

int binpow(int a, int b){
	int res = 1;
	while (b){
		if (b & 1)
			res = (res * li(a)) % MOD;
		a = (a * li(a)) % MOD;
		b >>= 1;
	}
	return res;
}

pt get(int l, int r){
	if (l == r)
		return mp(1, 0);
	
	int mn = *min_element(a + l, a + r);
	
	vector<pt> dp;
	int lst = l;
	int cnt = 0;
	fore(i, l, r){
		a[i] -= mn;
		if (a[i] == 0){
			dp.pb(get(lst, i));
			lst = i + 1;
			++cnt;
		}
	}
	dp.pb(get(lst, r));
	
	fore(i, l, r)
		a[i] += mn;
	
	int dp1 = binpow(2, mn), dp2 = 0;
	for (auto it : dp)
		dp1 = (dp1 * li(it.x)) % MOD;
	
	int tmp;
	
	tmp = binpow(2, cnt);
	for (auto it : dp)
		tmp = (tmp * li(it.x + it.y)) % MOD;
	dp2 = (dp2 + tmp) % MOD;
	
	tmp = (binpow(2, mn) - 2 + MOD) % MOD;
	for (auto it : dp)
		tmp = (tmp * li(it.x)) % MOD;
	dp2 = (dp2 + tmp) % MOD;
	
	return mp(dp1, dp2);
}

void solve() {
	printf("%d\n", get(0, n).y);
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	
	int tt = clock();
	
#endif
	
	cerr.precision(15);
	cout.precision(15);
	cerr << fixed;
	cout << fixed;

#ifdef _DEBUG
	while(read()) {	
#else
	if(read()) {
#endif
		solve();
		
#ifdef _DEBUG
	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();
#endif

	}
}