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

const int N = 10 * 1000 + 13;
const int K = 100 + 7;

int n, d;
string s;

bool read () {
	static char buf[N];
	if (scanf("%s", buf) != 1)
		return false;
	s = buf;
	n = sz(s);
	scanf("%d", &d);
	return true;
}

int dp[N][K];

int add(int a, int b){
	a += b;
	if (a >= MOD)
		a -= MOD;
	return a;
}

void solve() {	
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	forn(i, n) forn(j, K) forn(l, 10)
		dp[i + 1][(j + l) % d] = add(dp[i + 1][(j + l) % d], dp[i][j]);
	
	int ans = MOD - 1;
	int cur = 0;
	forn(i, n){
		int c = s[i] - '0';
		forn(j, c){
			ans = add(ans, dp[n - i - 1][((d - cur - j) % d + d) % d]);
			//cerr << i << " " << j << " " << dp[n - i - 1][d - j] << endl;
		}
		cur = (cur + c) % d;
	}
	ans = add(ans, cur == 0);
	
	printf("%d\n", ans);
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

	while(read()) {	
		solve();
		
#ifdef _DEBUG
	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();
#endif

	}
}