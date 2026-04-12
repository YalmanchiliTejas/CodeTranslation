#define _USE_MATH_DEFINES
#include  <iostream>
#include  <algorithm>
#include  <climits>
#include  <vector>
#include  <string>
#include  <cstring>
#include  <stack>
#include  <queue>
#include  <cmath>
#include  <iomanip>
#include  <set>
#include  <map>
#include  <new>
#include <cstdint>
#include <cctype>
#include  <cstdio>
#include  <sstream>
#include  <bitset>
using namespace std;
#define rep(i,n)  for(int i = 0; i < n; i++)
#define lrep(i,n,m)  for(int i = n; i < m; i++)

using ll = long long;
using ld = long double;
using Vii = vector<vector<int> >;
using Gjudge = vector<vector<bool>>;
using Vi = vector<int>;
using Vl = vector<ll>;
using Vd = vector<double>;
using Vld = vector<long double>;
using Vll = vector<vector<ll> >;
using Vldd = vector<vector<ld> >;
using Vs = vector<string>;
using Vb = vector<bool>;
using Pi = pair<int, int>;
using Pl = pair<ll, ll>;
using Pli = pair<ll, int>;
using VPi = vector<Pi>;
using VPl = vector<Pl>;
using VPli = vector<Pli>;
using Ti = tuple<int, int, int>;
using Tl = tuple<ll, ll, ll>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int Mod = static_cast<int>(1e9 + 7);
const int INF = INT_MAX;
const ll LINF = LLONG_MAX;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };

const ll M = 998244353;

int main()
{
	ll n, x, m;
	cin >> n >> x >> m;


	if (n <= m) {
		ll z = x;
		ll ans = x;
		for (int i = 0; i < n - 1; i++) {
			z = z * z;
			z %= m;
			ans += z;
			//cout << ans << endl;
		}
		cout << ans << endl;
		return 0;
	}

	Vi R;
	ll r = x;
	bool f = true;
	int t = 0;
	bool h = true;
	while (1) {
		r = r % m;
		for (int i = 0; i < R.size(); i++) {
			if (R[i] == r) {
				f = false;
				t = i;
				break;
			}
		}
		if (f) {
			if (h) {
				h = false;
				R.push_back(x);
				r = x * x;
			}
			else {
				R.push_back(r);
				r = r * r;
			}
		}
		else {
			break;
		}
	}

	ll ans = 0;
	for (int i = 0; i < t; i++) {
		ans += R[i];
	}
	ll cirsum = 0;
	for (int i = t; i < R.size(); i++) {
		cirsum += R[i];
	}
	ll numcir = (n - t) / (R.size() - t);
	ll numcirr = (n - t) % (R.size() - t);
	ans += cirsum * numcir;
	for (int i = 0; i < numcirr; i++) {
		ans += R[i + t];
	}
	cout << ans << endl;
}
