#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cstdio>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h>
#include <queue>
#include <stack>
#include <utility>
#include <fstream>
#include <random>
#include <map>
#include <unordered_map>
#include <cstdlib>
#include <functional>
#include <random>
#include <time.h>
#include <chrono>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <iostream>
#include <limits>
#include <numeric>
#include <type_traits>
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ll long long
#define INF 1000000001
#define MOD 1000000007
#define SORT(s) sort(s.begin(), s.end());
#define REVERSE(s) reverse(s.begin(), s.end());
#define SUM(s) accumulate(s.begin(), s.end(), 0LL);
#define P pair<int,int>
#define mp make_pair
#define valid(x,y,h,w) (0<=x&&x<h&&0<=y&&y<w)
//#define int ll
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int ndx[8] = { 0,1,0,-1, 1,1,-1,-1 };
int ndy[8] = { 1,0,-1,0, 1,-1,-1,1 };
using namespace std;
int POW(int x, int y) { return int(pow(double(x), double(y))); }
double log(double a, double b) { return log(b) / log(a); }

template <class T>
void VecRowShow(vector<T> vec) {
	rep(i, vec.size()) {
		if (i != vec.size() - 1) cout << vec[i] << " ";
		else cout << vec[i] << endl;
	}
}

unsigned euclidean_gcd(unsigned a, unsigned b) {
	if (a < b) return euclidean_gcd(b, a);
	unsigned r;
	while ((r = a % b)) {
		a = b;
		b = r;
	}
	return b;
}

int main() {

	ll n;
	cin >> n;
	vector<ll> e(n), o(n), q(n);
	rep(i, n) {
		ll a;
		cin >> a;
		q[i] = a;
		if (i % 2 == 0) {
			if (i == 0) {
				e[0] = a;
			}
			else {
				ll z = e[i - 2];
				e[i] = z + a;
			}
		}
		else {
			if (i == 1) {
				o[1] = a;
			}
			else {
				ll z = o[i - 2];
				o[i] = z + a;
			}
		}
	}

	vector<vector<pair<ll, ll>>> li(n);
	rep(i, n) {
		if (i == 0) {
			li[0].push_back(make_pair(0, 0));
			li[0].push_back(make_pair(1, q[0]));
		}
		else if (i == 1) {
			li[1].push_back(make_pair(0, 0));
			li[1].push_back(make_pair(1, q[1]));
		}
		else {
			ll m1 = (i + 1) / 2;
			ll m1m = -10000000000000000;
			FOR(j, 2, 7) {
				if (i - j < 0) {
					break;
				}
				rep(k, li[i - j].size()) {
					if (li[i - j][k].first == m1 - 1) {
						m1m = max(m1m, li[i - j][k].second);
					}
				}
			}
			li[i].push_back(make_pair(m1, m1m + q[i]));


			ll m2 = (i + 2) / 2;
			ll m2m = -10000000000000000;
			FOR(j, 2, 7) {
				if (i - j < 0) {
					break;
				}
				rep(k, li[i - j].size()) {
					if (li[i - j][k].first == m2 - 1) {
						m2m = max(m2m, li[i - j][k].second);
					}
				}
			}
			li[i].push_back(make_pair(m2, m2m + q[i]));
		}
	}

	ll i = n - 1;
	ll m3 = n / 2;
	ll m3m = -10000000000000000;
	FOR(j, 0, 7) {
		if (i - j < 0) {
			break;
		}
		rep(k, li[i - j].size()) {
			if (li[i - j][k].first == m3) {
				m3m = max(m3m, li[i - j][k].second);
			}
		}
	}
	cout << m3m << endl;

}


