
#include <queue>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <stdlib.h>
#include <map>
#include <stdio.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for(int i = (a); i < (int)(b); i++)
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vint;
typedef vector<string> vstr;
typedef pair<ll, ll> pint;
unsigned long long inf = (1LL << 62);
ll mod = 998244353;
pint dx[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

vector<ll> a[300];
ll N, M;
char c[8][8];

int main() {

	cin >> N >> M;
	ll sum = 0;
	rep(i, N) {
		rep(j, M) {

			cin >> c[i][j];
			if (c[i][j] == '#')
				sum += 1;
		}
	}

	if (sum == N + M - 1) {
		cout << "Possible" << endl;
	}
	else {
		cout << "Impossible" << endl;
	}
	return 0;
}