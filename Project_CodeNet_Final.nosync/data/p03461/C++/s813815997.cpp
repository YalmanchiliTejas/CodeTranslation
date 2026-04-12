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
int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

int mn[105][105];
int in[105][105];
int main() {
	int A, B, i, j, k, l;
	scanf("%d %d", &A, &B);
	for (i = 1; i <= A; i++) for (j = 1; j <= B; j++) scanf("%d", &in[i][j]);

	for (i = 1; i <= A; i++) {
		for (j = 1; j <= B; j++) {
			for (k = 0; k <= 100; k++) {
				for (l = 0; l <= 100; l++) {
					int t = i*k + j*l;
					mn[k][l] = max(mn[k][l], in[i][j] - t);
				}
			}
		}
	}
	for (i = 1; i <= A; i++) {
		for (j = 1; j <= B; j++) {
			int v = INF;
			for (k = 0; k <= 100; k++) for (l = 0; l <= 100; l++) v = min(v, i*k + j*l + mn[k][l]);
			if (v != in[i][j]) return !printf("Impossible\n");
		}
	}

    printf("Possible\n");
	printf("202 %d\n", 101*101+200);
	for (i = 1; i <= 100; i++) printf("%d %d X\n", i, i + 1);
	for (i = 102; i <= 201; i++) printf("%d %d Y\n", i, i + 1);
	for (i = 1; i <= 101; i++) for (j = 1; j <= 101; j++) printf("%d %d %d\n", i, j + 101, mn[i - 1][101 - j]);
	return !printf("%d %d\n", 1, 202);
}