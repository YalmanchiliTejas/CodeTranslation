#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <cstring>
#include <map>
#include <bitset>
#include <random>
#include <stack>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <ctime>

using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define sc second
#define fs first
#define mp make_pair
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

template<class T> T sqr(T x) { return x*x; }
ld pi = 3.1415926535897932384626433832795;
ll mod = 1e9 + 7;
const int N = 1e6 + 10;

typedef vector<vector<ll> > mtrx;

ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}

ll ans[111];

int try_solve(int n) {
	ll a = 1;
	while (1) {
		int id = 0;
		for (int i = 0; i < n; i++)
			if (ans[i] > ans[id]) id = i;
		if (ans[id] < n) {
			return a-1;
		}
		a++;
		for (int i = 0; i < n; i++) ans[i] += 1;
		ans[id] -= n + 1;
	}
}

ll b[111];
bool can(ll k, int n) {
	for (int i = 0; i < n; i++)
		b[i] = ans[i] + k;
	ll dd = n + 1;
	ll need = 0;
	for (int i = 0; i < n; i++)
		need += (b[i]-(n-1) + dd-1) / dd;
	return need <= k;
}

int main(){
	ll n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> ans[i];
	ll res = 0;
	while (1) {
		ll temp = 0;
		for (int i = 0; i < n; i++) {
			ll t = (ans[i] - (n - 1)) / n;
			temp += t;
			ans[i] -= t*(n+1);
		}
		for (int i = 0; i < n; i++)
			ans[i] += temp;
		res += temp;
		if (temp == 0) break;
	}
	cout << res + try_solve(n);
	//ll k;
	//cin >> k;
	/*
	if (k == 1) {
		cout << 3 << '\n' << 0 << ' ' << 0 << ' ' << 3;
	}
	else if (k == 2) {
		cout << 2 << '\n' << 2 << ' ' << 2;
	} else if (k < 10)
	cout << 2 << '\n' << 2 - 1 << ' ' << 2ll - 1ll + k;
	else {
		ll n = 50;
		ll cur = k;
		for (int i = 0; i < n; i++) {
			ans[i] = n-1;
			ll add = min(cur, k / n);
			ans[i] += add;
			cur -= add;
		}
		for (int i = 0; i < cur; i++)
			ans[i] += n-cur;
		//ans[0] += 1;
		//ans[0] += 10;
		cout << n << endl;
		for (int i = 0; i < n; i++) {
			cout << ans[i] << ' ';
		}
		//try_solve(k, n);
	}*/
	return 0;
}