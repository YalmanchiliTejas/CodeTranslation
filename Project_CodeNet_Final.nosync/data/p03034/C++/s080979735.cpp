#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using P   = pair<ll, ll>;
using mat = vector<vector<ll>>;
typedef string::const_iterator State;
class ParseError {};

void IOS() { ios::sync_with_stdio(false), cin.tie(0); }

const ll INF = 1e16;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-12;

template <typename T>
void dump(T x) { cout << x << endl; }
void dumpf(ld x, int t) { cout << setprecision(t) << fixed << x << endl; }
template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val) {
	fill((T *)array, (T *)(array + N), val);
}
inline ll mod(ll a, ll b) {
	if (a > 0) return a % b;
	if (a % b == 0) return 0;
	ll x = -a / b + 1;
	a += x * b;
	return a % b;
}
ll powm(ll a, ll b, ll c) {
	if (b == 0)
		return 1;
	else if (b % 2 == 0) {
		ll d = powm(a, b / 2, c);
		return (d * d) % c;
	} else
		return (a * powm(a, b - 1, c)) % c;
}
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

//ll dx[4] = {1, 0, -1, 0};
//ll dy[4] = {0, 1, 0, -1};

int main() {
	ll n;
	cin >> n;
	vector<ll> s(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	ll ans = 0;
	for (int c = 0; c < n; c++) {
		set<ll> se;
		ll score = 0;
		for (int x = 0; x < n; x++) {
			ll a = n - 1 - x * c;
			ll b = a - c;
			if (a <= 0 || b <= 0) break;
			ll right = n - 1 - x * c;
			ll left  = x * c;
			if (right <= 0 || left >= n - 1 || left == right || se.find(right) != se.end() || se.find(left) != se.end()) break;
			se.insert(right);
			se.insert(left);
			score += s[left] + s[right];
			ans = max(ans, score);
		}
	}
	dump(ans);
	return 0;
}
