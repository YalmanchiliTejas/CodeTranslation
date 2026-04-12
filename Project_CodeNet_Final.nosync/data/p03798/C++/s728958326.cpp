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
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ll long long
#define INF 1000000001
#define MOD 1000000007
#define SORT(s) sort(s.begin(), s.end());
#define reverse(s) reverse(s.begin(), s.end());
#define P pair<int,int>
#define mp make_pair
#define valid(x,y,h,w) (0<=x&&x<h&&0<=y&&y<w)
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int ndx[8] = { 0,1,0,-1, 1,1,-1,-1 };
int ndy[8] = { 1,0,-1,0, 1,-1,-1,1 };
using namespace std;
int POW(int x, int y) { return int(pow(double(x), double(y))); }
double log(double a, double b) { return log(b) / log(a); }


int n;
string s;

char next(char a, char b, int i) {
	if (s[i] == 'o') {
		if (a == 'S' && b == 'W') return 'W';
		if (a == 'S' && b == 'S') return 'S';
		if (a == 'W' && b == 'S') return 'W';
		if (a == 'W' && b == 'W') return 'S';
	}
	else {
		if (a == 'S' && b == 'W') return 'S';
		if (a == 'S' && b == 'S') return 'W';
		if (a == 'W' && b == 'S') return 'S';
		if (a == 'W' && b == 'W') return 'W';
	}
}

int main() {
	cin >> n;
	cin >> s;
	rep(i, 4) {
		string ans;
		if (i == 0) {
			ans = "SW";
		}
		if (i == 1) {
			ans = "SS";
		}
		if (i == 2) {
			ans = "WS";
		}
		if (i == 3) {
			ans = "WW";
		}

		FOR(j, 1, n - 1) {
			ans.push_back(next(ans[j - 1], ans[j], j));
		}
		if (next(ans[n - 2], ans[n - 1], n - 1) == ans[0] &&
			next(ans[n - 1], ans[0], 0) == ans[1]) {
			cout << ans << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}