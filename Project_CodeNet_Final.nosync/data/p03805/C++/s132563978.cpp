#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <stdlib.h>
#include <string.h>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <stdio.h>
#include <tuple>
#include <bitset>
#include <cfloat>
#include <fstream>
#include <limits.h>
#include <list>
#include <math.h>
#include <random>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <numeric>
#include <utility>
#include <sstream>

template<class T> inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<class T> inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

using namespace std;
#define int long long
#define ll long long
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define FORR(i,a,b)for(ll i=(a);i<=(b);i++)
#define repr(i,n) for(ll i=n;i>=0;i--)
#define P pair<ll, ll>
#define sz(x) (ll)x.size()
#define ALL(x) (x).begin(),(x).end()
#define ALLR(x) (x).rbegin(),(x).rend()
#define VE vector<ll>
#define COUT(x) cout<<(x)<<endl
#define MA map<ll,ll>
#define SE set<ll>
#define PQ priority_queue<ll>
#define PQR priority_queue<ll,VE,greater<ll>>
#define COUT(x) cout<<(x)<<endl
#define YES(n) cout << ((n) ? "YES" : "NO"  ) << endl
#define Yes(n) cout << ((n) ? "Yes" : "No"  ) << endl
#define EPS (1e-10)


const long long MOD = 1000000007;
//const long long MOD = 998244353;
const long long INF = 1LL << 60;


long long modinv(long long a, long long m) {
	long long b = m, u = 1, v = 0;
	while (b) {
		long long t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= m;
	if (u < 0) u += m;
	return u;
}
ll gcd(ll a, ll b) {
	if (a < b)swap(a, b);
	if (b == 0) return a;
	unsigned r;
	while ((r = a % b)) {
		a = b;
		b = r;
	}
	return b;
}
ll lcm(ll a, ll b) {
	ll g = gcd(a, b);
	return a * g / b;
}
bool prime(ll n) {
	for (ll i = 2; i <= sqrt(n); i++) {
		if (n%i == 0)return false;
	}
	return n != 1;
}




const long double PI = 3.14159265359;
const int MAX_N = 100010;

bool graph[10][10];

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m; cin >> n >> m;
	VE a(m), b(m);
	rep(i, m) {
		cin >> a[i] >> b[i]; a[i]--; b[i]--;
		graph[a[i]][b[i]] = true; graph[b[i]][a[i]] = true;
	}
	VE tmp(n-1);
	int ans = 0;
	rep(i, n - 1)tmp[i] = i + 1;
	do {
		bool ok = true;
		rep(i, n - 1) {
			if (i == 0) {
				if (!graph[0][tmp[i]]) {
					ok = false;
				}
			}
			else {
				if (!graph[tmp[i - 1]][tmp[i]]) {
					ok = false;
				}

			}
		}
		if (ok)ans++;
	} while (next_permutation(ALL(tmp)));
	cout << ans << endl;
	return 0;
}