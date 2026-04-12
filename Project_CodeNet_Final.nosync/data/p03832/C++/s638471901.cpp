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
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
#include <random>
#include <unordered_set>
#include <complex>
using namespace std;
 
#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };
// typedef complex<double> C;
 
ll MOD = 1000000007;
ll _MOD = 1000000009;
int INF = INT_MAX / 2;
double EPS = 1e-10;

template <int M>
struct ModInt {
	int x;
	ModInt() : x(0) {}
	ModInt(int _x) { if ((x = _x % M) < 0) x += M; }
	int operator () () const { return x; }
	ModInt operator - () const { ModInt a = *this; if (a.x) a.x = M - a.x; return a; }
	ModInt& operator += (const ModInt &a) { if ((x += a.x) >= M) x -= M; return *this; }
	ModInt& operator -= (const ModInt &a) { if ((x -= a.x) < M) x += M; return *this; }
	ModInt& operator *= (const ModInt &a) { x = (ll)x * a.x % M; return *this; }
	ModInt operator + (const ModInt &a) const { return ModInt(*this) += a; }
	ModInt operator - (const ModInt &a) const { return ModInt(*this) -= a; }
	ModInt operator * (const ModInt &a) const { return ModInt(*this) *= a; }
};
typedef ModInt<1000000007> mint;

int main() {
	int N, A, B, C, D;
	cin >> N >> A >> B >> C >> D;
	vector<vector<mint> > comb(N + 1, vector<mint>(N + 1));
	for (int x = 0; x <= N; x++) {
		comb[x][0] = 1;
		for (int y = 1; y <= x; y++)
			comb[x][y] = comb[x - 1][y - 1] + comb[x - 1][y];
	}
	vector<vector<mint> > dp(N + 1, vector<mint>(N + 2));
	dp[0][1] = 1;
	for (int x = 0; x <= N; x++) for (int y = 1; y <= N; y++) {
		dp[x][y + 1] += dp[x][y];
		mint a = 1;
		if (A <= y && y <= B)
			for (int z = 1; x + y * z <= N; z++) {
				a *= comb[y * z - 1][y - 1];
				if (C <= z && z <= D)
					dp[x + y * z][y + 1] += dp[x][y] * comb[N - x][y * z] * a;
			}
	}
	cout << dp[N][N + 1]() << endl;
}
