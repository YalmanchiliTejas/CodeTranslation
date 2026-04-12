#include "bits/stdc++.h"
#include <regex>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

#ifndef _DEBUG
#define main_ main
#endif
#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define INF (INT_MAX/2)
#define EPS (1.0e-8)
#define LINF (LONG_MAX/2)

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<bool> vb;
typedef vector<string> vs;

template <typename T>
using keyVal = pair<string, T>;
template<typename T>
bool val_greater(const keyVal<T>& left, const keyVal<T>& right) {
	return left.second > right.second;
}

bool P[8][8];
int N, M;

void init_global() {
	FOR(i, 0, 8) {
		FOR(j, 0, 8) {
			P[i][j] = false;
		}
	}
}

void dfs(int i, vb& v, ll& cnt) {
	v[i] = true;

	bool all_visited = true;
	FOR(j, 0, N) {
		if (!v[j]) all_visited = false;
	}

	if (all_visited) {
		cnt++;
		v[i] = false;
		return;
	}

	FOR(j, 0, N) {
		if (!P[i][j] || v[j]) continue;
		dfs(j, v, cnt);
	}
	v[i] = false;
}

int main_() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	int a, b;
	FOR(i, 0, M) {
		cin >> a >> b;
		a--; b--;
		P[a][b] = P[b][a] = true;
	}

	ll ans=0;
	vb v(N, false);
	dfs(0, v, ans);

	cout << ans << endl;
	return 0;
}
