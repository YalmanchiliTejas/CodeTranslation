//#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <vector>
#include <cassert>
#include <fstream>
#include <algorithm>
#include <list>
#include <random>
#include <ctime>
#include <cmath>
#include <random>
#include <bitset>
#include <complex>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
//#define int ll
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector< vvi > vvvi;
typedef vector<short> vs;
typedef vector<vs> vvs;
typedef vector<vvs> vvvs;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef pair<ld, ld> pld;
typedef complex<double> base;

#define mmin(a, b) a = min(a, (b))
#define mmax(a, b) a = max(a, (b))
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define ALL(a) a.begin(),a.end()
#define sqr(x) (x) * (x)
#define fori(i, n) for(int i = 0; i < int(n); ++i)
#define cint const int & 
#define SZ(a) ((int)(a.size()))
#define watch(x) cout << (#x) << " = " << x << endl;

const double PI = 2 * acos(0.0);

template<class T>
void show(const vector<T> &a) {
	for (T x : a)
		cout << x << " ";
	cout << endl;
}


signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<pii> a(n);
	fori(i, n) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(ALL(a));
	vi ans(n);
	fori(i, n) {
		if (i < n / 2) ans[a[i].second] = a[n / 2].first;
		else ans[a[i].second] = a[n / 2 - 1].first;
	}
	fori(i, n)
		cout << ans[i] << "\n";
}