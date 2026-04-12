#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;

#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define ldb ldouble

typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 18;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-9;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

char in[55][55];
char u[55];
int G[55][55];
int tus[55][55];
int main() {
	while (1) {
		int N, M, i, j, k, l, m;
		scanf("%d %d", &N, &M);
		if (!N) break;
		for (i = 0; i <= N + 1; i++) for (j = 0; j <= M + 1; j++) in[i][j] = '.';
		for (i = 1; i <= N; i++) {
			scanf("%s", u);
			for (j = 1; j <= M; j++) in[i][j] = u[j - 1];
		}

		if (N == 2 || M == 2) {
			bool c = true;
			for (i = 1; i <= N; i++) for (j = 1; j <= M; j++) if (in[i][j] == '#') c = false;
			if (c) printf("YES\n");
			else printf("NO\n");
			continue;
		}

		for (i = 2; i <= M - 1; i++) in[0][i] = in[N + 1][i] = '#';
		for (i = 2; i <= N - 1; i++) in[i][0] = in[i][M + 1] = '#';

		for (i = 0; i <= N + 1; i++) for (j = 0; j <= M + 1; j++) G[i][j] = 0;
		int gc = 0;
		for (i = 0; i <= N + 1; i++) {
			for (j = 0; j <= M + 1; j++) {
				if (G[i][j] || in[i][j] == '.') continue;

				int k, l;
				G[i][j] = ++gc;
				vector <pii> Vu;
				Vu.emplace_back(i, j);
				for (k = 0; k < Vu.size(); k++) {
					for (l = 0; l < 8; l++) {
						int x = Vu[k].first  + "00011222"[l] - '1';
						int y = Vu[k].second + "01202012"[l] - '1';
						if (x < 0 || x > N + 1 || y < 0 || y > M + 1 || in[x][y] == '.' || G[x][y]) continue;
						G[x][y] = gc;
						Vu.emplace_back(x, y);
					}
				}
				Vu.clear();
			}
		}

		int tg[4] = { G[0][2], G[N + 1][2], G[2][0], G[2][M + 1] };
		if (tg[0] == tg[1] || tg[0] == tg[2] || tg[0] == tg[3] || tg[1] == tg[2] || tg[1] == tg[3] || tg[2] == tg[3]) {
			printf("NO\n");
			continue;
		}

		for (i = 0; i <= N + 1; i++) for (j = 0; j <= M + 1; j++) tus[i][j] = 0;
		for (i = 0; i < 4; i++) {
			for (j = 0; j <= N + 1; j++) {
				for (k = 0; k <= M + 1; k++) {
					if (G[j][k] != tg[i]) continue;
					for (l = j - 1; l <= j + 1; l++) {
						for (m = k - 1; m <= k + 1; m++) {
							if (l < 0 || l > N + 1 || m < 0 || m > M + 1) continue;
							tus[l][m] |= 1 << i;
						}
					}
				}
			}
		}
		for (i = 0; i <= N + 1; i++) {
			for (j = 0; j <= M + 1; j++) {
				if (i == 1 && j == 1) continue;
				if (i == 1 && j == M) continue;
				if (i == N && j == M) continue;
				if (i == N && j == 1) continue;
				if (tus[i][j] != 0 && tus[i][j] != 1 && tus[i][j] != 2 && tus[i][j] != 4 && tus[i][j] != 8) break;
			}
			if (j <= M + 1) break;
		}
		if (i > N + 1) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}