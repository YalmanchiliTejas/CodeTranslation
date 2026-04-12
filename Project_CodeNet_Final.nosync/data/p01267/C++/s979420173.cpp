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
	for (;;) {
		int N, A, B, C, X;
		cin >> N >> A >> B >> C >> X;
		if (N == 0) break;
		vector<int> Y(N);
		for (int i = 0; i < N; i++) cin >> Y[i];
		int cnt = -1;
		for (int i = 0; i < N; i++) {
			for (;;) {
				cnt++;
				int _X = X;
				X = (A * X + B) % C;
				if (_X == Y[i]) break;
				if (cnt > 10000) break;
			}
			if (cnt > 10000) break;
		}
		cout << (cnt <= 10000 ? cnt : -1) << endl;
	}
}