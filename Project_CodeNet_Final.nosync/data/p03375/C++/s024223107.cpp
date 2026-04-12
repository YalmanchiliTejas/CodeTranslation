/*input
3000 111111113
*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define N 3005
#define bit(x,y) ((x>>y)&1LL)
#define loop(x) for(int xv=1; xv<=x; xv++)

#define what_is(x) cerr << #x << " is " << x << endl;
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &a) {
	return os << '(' << a.first << ", " << a.second << ')';
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &a) {
	os << '[';
	for (unsigned int i = 0; i < a.size(); i++)
		os << a[i] << (i < a.size() - 1 ? ", " : "");
	os << ']';
	return os;
}
template <class T>
ostream &operator<<(ostream &os, const set<T> &a) {
	os << '{';
	for (typename set<T>::iterator it = a.begin(); it != a.end(); it++) {
		typename set<T>::iterator jt = it;
		os << *it << (++jt != a.end() ? ", " : "");
	}
	os << '}';
	return os;
}
template <class T1, class T2>
ostream &operator<<(ostream &os, map<T1, T2> &a) {
	os << "{\n";
	for (typename map<T1, T2>::iterator it = a.begin(); it != a.end(); it++) {
		typename map<T1, T2>::iterator jt = it;
		os << "  " << it->first << ": " << it->second << (++jt != a.end() ? ",\n" : "\n");
	}
	os << '}';
	return os;
}

int n, mod;
int dp[N];
int C[N][N];
int f[N][N];
int p2[N * N];
int p22[N];

#define pow binPow
long long binPow(long long a, long long q) {
	long long ret = 1;
	for (int i = 0; (1LL << i) <= q; i++) {
		if (q & (1LL << i)) ret = (ret * a) % mod;
		a = (a * a) % mod;
	}
	return ret;
}

long long _binPow(long long a, long long q) {
	long long ret = 1;
	for (int i = 0; (1LL << i) <= q; i++) {
		if (q & (1LL << i)) ret = (ret * a) % (mod - 1);
		a = (a * a) % (mod - 1);
	}
	return ret;
}

void calDP() {
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0)
				dp[i] = (dp[i] + 1LL * f[i][j] * p2[(n - i) * j] % mod * (p22[n - i] - 1) % mod) % mod;
			else
				dp[i] = (dp[i] + 1LL * f[i][j] * p2[(n - i) * j] % mod * (p22[n - i]) % mod) % mod;
		}
		dp[i] = (1LL * dp[i] * C[i][n]) % mod;
	}
}

void prep() {
	for (int i = 1; i <= N - 5; i++) C[0][i] = 1, C[1][i] = i;
	for (int i = 2; i <= N - 5; i++) {
		for (int j = i; j <= N - 5; j++) {
			C[i][j] = (C[i][j - 1] + C[i - 1][j - 1]) % mod;
		}
	}
	for (int i = 0; i <= N - 5; i++) f[i][0] = 1;
	for (int i = 1; i <= N - 5; i++) {
		for (int j = 1; j <= i; j++) {
			f[i][j] = (1LL * (j + 1) * f[i - 1][j] + f[i - 1][j - 1]) % mod;
		}
	}
	p2[0] = 1;
	for (int i = 1; i < N * N; i++) p2[i] = (1LL * p2[i - 1] * 2) % mod;
	for (int i = 0; i < N; i++) p22[i] = binPow(2, _binPow(2, i));
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> mod;
	prep();
	calDP();
	int ans = p22[n] - 1;
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 0) ans = (ans + dp[i]) % mod;
		else ans = (ans - dp[i]) % mod;
	}
	if (ans < 0) ans += mod;
	cout << ans << endl;
}