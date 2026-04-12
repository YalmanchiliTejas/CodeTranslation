#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cstring>
#include <climits>
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
 
int MOD = 1000000007;

vector<ll> calc2(vector<ll> v) {
	int n = v.size();
	vector<ll> res;
	if (v[1] == -1)
		res.push_back(v[0] + v[2]);
	else
		res.push_back(v[0] * v[2]);
	for (int i = 3; i < n; i++)
		res.push_back(v[i]);
	return res;
}

vector<ll> calc(vector<ll> v) {
	int n = v.size();
	for (int i = 0; i < n; i++)
		if (v[i] == -2) {
			vector<ll> res;
			for (int j = 0; j < i - 1; j++)
				res.push_back(v[j]);
			res.push_back(v[i - 1] * v[i + 1]);
			for (int j = i + 2; j < n; j++)
				res.push_back(v[j]);
			return res;
		}
	return calc2(v);
}

int main() {
	string s; cin >> s;
	int n = s.length();
	vector<ll> v;
	for (int i = 0; i < n; i++) {
		if (s[i] == '+') v.push_back(-1);
		else if (s[i] == '*') v.push_back(-2);
		else v.push_back(s[i] - '0');
	}
	vector<ll> w = v;
	for (int i = 0; i < n / 2; i++) {
		v = calc(v);
		w = calc2(w);
	}
	int x; cin >> x;
	if (v[0] == x && w[0] == x) cout << 'U' << endl;
	if (v[0] != x && w[0] == x) cout << 'L' << endl;
	if (v[0] == x && w[0] != x) cout << 'M' << endl;
	if (v[0] != x && w[0] != x) cout << 'I' << endl;
} 