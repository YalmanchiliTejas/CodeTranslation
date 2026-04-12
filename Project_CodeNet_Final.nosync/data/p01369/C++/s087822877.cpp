#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
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
struct edge { int u, v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
	string l = "qwertasdfgzxcvb";
	string r = "yuiophjklnm";
	vector<int> a(256);
	for (int i = 0; i < l.length(); i++)
		a[l[i]] = -1;
	for (int i = 0; i < r.length(); i++)
		a[r[i]] = 1;
	for (;;) {
		string s; cin >> s;
		if (s == "#") break;
		int x = 0, cnt = 0;
		for (int i = 0; i < s.length(); i++) {
			char c = s[i];
			if (a[c] != x) {
				x = a[c];
				cnt++;
			}
		}
		cout << cnt - 1 << endl;
	}
}