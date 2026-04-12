#include "bits/stdc++.h"
#include <unordered_set>

#define _CRT_SECURE_NO_WARNINGS

#define FOR(i, x, n) for(decltype(x) i = (x); i < (n); i++)
#define REP(i, n) for(decltype(n) i = 0; i < (n); i++)
#define RREP(i, n) for (decltype(n) i = (n) - 1; i >= 0; i--)

#define ALL(a) (a).begin(),(a).end()
#define SORT(c) sort((c).begin(),(c).end())
#define DESCSORT(c) sort(c.begin(), c.end(), greater<int>())

using namespace std;

const int dy[] = { 0, 1, 0, -1 };
const int dx[] = { 1, 0, -1, 0 };

using LL = long long int;
using LD = long double;

const int INF = (1 << 30) - 1;
const LL INF64 = ((LL)1 << 62) - 1;
const double PI = 3.1415926535897932384626433832795;

using pii = pair<int, int>;
using pll = pair<LL, LL>;
using pdd = pair<double, double>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vl = vector<LL>;
using vvl = vector<vl>;
using vvvl = vector<vvl>;
using vd = vector<double>;
using vvd = vector<vd>;
using vs = vector<string>;
using vb = vector<bool>;
using vvb = vector<vb>;

vs M;

int HH, WW;
int N = 0, W = 0, S = 0, E = 0;

void bfs() {
	queue<pii> que;
	que.push(make_pair(0, 0));

	M[0][0] = '.';

	while (!que.empty()) {
		
		const pii now = que.front(); que.pop();
		REP(i, 4) {
			int ny = now.first + dy[i];
			int nx = now.second + dx[i];

			if (nx < 0 || WW <= nx || ny < 0 || HH <= ny) continue;
			if (M[ny][nx] == '.') continue;
			if (M[ny][nx] == 'G') return;

			if (i == 0) {
				E++;
			} else if (i == 1) {
				S++;
			} else if (i == 2) {
				W++;
			} else {
				N++;
			}

			M[ny][nx] = '.';
			que.push(make_pair(ny, nx));

			cout << "----================----" << endl;
			REP(i, HH) {
				cout << M[i] << endl;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> HH >> WW;
	M.resize(HH);

	REP(i, HH) {
		cin >> M[i];
	}

//	M[HH - 1][WW - 1] = 'G';
//	bfs();

	FOR(i, 1, HH) {
		FOR(j, 1, WW) {
			if (M[i - 1][j] == '#' && M[i][j - 1] == '#') {
				cout << "Impossible" << endl;
				return 0;
			}
		}
	}
	cout << "Possible" << endl;
	return 0;
}