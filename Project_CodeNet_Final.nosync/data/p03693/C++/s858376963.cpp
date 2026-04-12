/*
	A - RGB Cards
*/
#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;

double EPS = 1e-10;

#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define int(x) int x; cin >> x;
#define lint(x) long long x; cin >> x;
#define vint(v,n) vector<int> v(n); REP(i,n) cin >> v[i];
#define vlint(v,n) vector<lint> v(n); REP(i,n) cin >> v[i];
#define double(x) double x; cin >> x[i];
#define vdouble(v,n) vector<double> v(n); REP(i,n) cin >> v[i];
#define string(x) string x; cin >> x;

int main()
{
	int(r);
	int(g);
	int(b);

	if ((r * 100 + g * 10 + b) % 4)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;

	return 0;
}