#include "bits/stdc++.h"
using namespace std;
#define Would
#define you
const long long INF = 1e18;
const long long MOD = 1e9 + 7;
const double pi = acos(-1);
const int SIZE = 1 << 17;
int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 }, alp[30];
long long fac[100005], finv[100005], inv[100005];

int main() {
	int n;
	char c;
	cin >> n >> c;
	for (int i = 0; i < n - 1; ++i) {
		char s;
		cin >> s;
		if (c == 'T'&&s == 'F') { c = 'F'; }
		else { c = 'T'; }
	}
	cout << c << endl;
}
