#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <iomanip>
#include <functional>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> PLL;
#define rep(i,n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i,n) for (ll i = 1; i <= (ll)(n); i++)
#define repR(i,n) for (ll i = (ll)(n)-1; i >= 0; i--)
#define rep1R(i,n) for (ll i = (ll)(n); i >= 1; i--)
#define loop(i,a,B) for (ll i = a; i B; i++)
#define loopR(i,a,B) for (ll i = a; i B; i--)
#define all(v) v.begin(), v.end()
#define fcout cout<<fixed<<setprecision(15)
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078160628620899
const unsigned int BIT_FLAG_0 = (1 << 0);
const unsigned int BIT_FLAG_1 = (1 << 1);
const unsigned int BIT_FLAG_2 = (1 << 2);
const unsigned int BIT_FLAG_3 = (1 << 3);
const unsigned int BIT_FLAG_4 = (1 << 4);
const unsigned int BIT_FLAG_5 = (1 << 5);
const unsigned int BIT_FLAG_6 = (1 << 6);
const unsigned int BIT_FLAG_7 = (1 << 7);
const ll MOD = 1000000007;
const ll MOD2 = 998244353;
const ll INF = 1000000000000000000;

string S, T, U, V[1100000], W[1100000];
char P[1100000], Q[1100000];
ll ANS = 0, SUM = 0, NOW = 0, N, M, A = 0, B = 0, C = 0, D = 0, E = 0, F[1100000] = { 0 }, G[1100000] = { 0 }, H[1100000] = { 0 };
double n = 0, m = 0, a = 0, b = 0, c = 0, d = 0, e = 0, f[1100000] = { 0 }, g[1100000] = { 0 };
bool ans = 0, now = 0, sum = 0, BOOL[1100000];

int mod_pow(int x, int y, int m) {
	int res = 1;
	while (y) {
		if (y & 1) {
			res = res * x % m;
		}
		x = x * x % m;
		y >>= 1;
	}
	return res;
}

int kai(int x, int y) {
	int res = 1;
	for (int i = x - y; i <= x; i++) {
		res *= i;
		res %= MOD;
	}
	return res;
}

int comb(int x, int y) {
	if (y > x) return 0;
	return kai(x, y) * mod_pow(kai(x, y), MOD - 2, MOD) % MOD;
}

ll gcd(ll x, ll y) {
	if (x < y) {
		swap(x, y);
	}
	ll r = x % y;
	while (r != 0) {
		x = y;
		y = r;
		r = x % y;
	}
	return y;
}

int lcm(ll x, ll y) {
	ll ans = x * y / gcd(x, y);
	return ans;
}

long ketasu(ll n) {
	ll count = 1;
	while (n >= 10) {
		n /= 10;
		count++;
	}
	return count;
}

string sortS(string s) {
	string sortS;
	vector<char> t(s.size());
	rep(i, s.size()) t[i] = s[i];
	sort(t.begin(), t.end());
	rep(i, s.size()) sortS += t[i];
	return sortS;
}

bool anagram(string a, string b) {
	if (sortS(a) == sortS(b)) return true;
	else return false;
}

int euclidA(int a, int b) {
	bool h = false;
	int i = 1;
	int ansa;
	while (!h) {
		if (((i * a) - gcd(a, b)) % b == 0) {
			ansa = i;
			h = true;
		}
		i++;
	}
	return ansa;
}

int eucridB(int a, int b) {
	bool h = false;
	int i = 1;
	int ansb;
	while (!h) {
		if (((i * a) - gcd(a, b)) % b == 0) {
			ansb = ((i * a - gcd(a, b)) / b);
			h = true;
		}
		i++;
	}
	return ansb;
}

int twobeki(int n) {
	if (n == 0) return 1;
	if (n % 2 == 0) {
		int k = twobeki(n / 2);
		return k * k;
	}
	return twobeki(n - 1) * 2;
}

ll nibutanlowL(ll k, ll a[], ll b, ll c) {
	ll left = b - 1;
	ll right = c + 1;
	while (right - left > 1) {
		ll mid = left + (right - left + 1) / 2;
		if (a[mid] >= k) right = mid;
		else left = mid;
	}
	return left;
}

ll nibutanlowR(ll k, ll a[], ll b, ll c) {
	ll left = b - 1;
	ll right = c + 1;
	while (right - left > 1) {
		ll mid = left + (right - left + 1) / 2;
		if (a[mid] >= k) right = mid;
		else left = mid;
	}
	return right;
}

ll nibutanupL(ll k, ll a[], ll b, ll c) {
	ll left = b - 1;
	ll right = c + 1;
	while (right - left > 1) {
		ll mid = left + (right - left + 1) / 2;
		if (a[mid] > k) right = mid;
		else left = mid;
	}
	return left;
}

ll nibutanupR(ll k, ll a[], ll b, ll c) {
	ll left = b - 1;
	ll right = c + 1;
	while (right - left > 1) {
		ll mid = left + (right - left + 1) / 2;
		if (a[mid] > k) right = mid;
		else left = mid;
	}
	return right;
}

ll mod(ll a, ll b) {
	if (a >= 0) return a % b;
	ll c = 0 - a;
	ll d = c % b;
	return b - d;
}


int main() {
	char Z[110][110];
	vector<ll> tate(0);
	vector<ll> yoko(0);
	cin >> N >> M;
	rep(i, N)rep(j, M)cin >> Z[i][j];
	rep(i, N) {
		bool allw = true;
		rep(j, M) {
			if (Z[i][j] == '#') {
				allw = false;
			}
		}
		if (!allw) {
			tate.push_back(i);
			A++;
		}
	}
	rep(i, M) {
		bool allw = true;
		rep(j, N) {
			if (Z[j][i] == '#') allw = false;
		}
		if (!allw) {
			yoko.push_back(i);
			B++;
		}
	}
	for (ll i=0;i<A;i++) {
		for (ll j=0;j<B;j++) {
			cout << Z[tate[i]][yoko[j]];
		}
		cout << endl;
	}
	return 0;
}