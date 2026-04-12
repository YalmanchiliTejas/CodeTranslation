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

int IT_MAX = 1 << 19;
int MOD = 10000000;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

const int MX = 105;
const int MM = 1000000007;

int v[MX][MX], D[MX][MX];
pii E[MX][MX];

int main()
{
	int A, B;
	scanf("%d%d", &A, &B);
	for(int i = 1; i <= A; i++){
		for(int j = 1; j <= B; j++){
			scanf("%d", D[i]+j);
			E[i][j] = pii(-1, -1);
		}
	}
	for(int kk = 100; kk >= 0; kk--){
		for(int l = kk; l >= 0; l--){
			int k = kk - l;
			int mx = 0;
			for(int x = 1; x <= A; x++){
				for(int y = 1; y <= B; y++){
					mx = max(mx, D[x][y] - x*k - y*l);
				}
			}
			v[k][l] = mx;
			for(int x = 1; x <= A; x++){
				for(int y = 1; y <= B; y++){
					if( mx == D[x][y] - x*k - y*l) E[x][y] = pii(k, l);
				}
			}
		}
	}
	vector<t3> L;
	map<pii, int> V;
	for(int i = 1; i <= A; i++){
		for(int j = 1; j <= B; j++){
			int a = E[i][j].first, b = E[i][j].second;
			if( a == -1 ) return !printf("Impossible\n");
			L.emplace_back(a, b, v[a][b]);
		}
	}
	sort(L.begin(), L.end());
	L.erase(unique(L.begin(), L.end()), L.end());

	int mx = 0, cur = 1;
	for(t3 c : L) mx = max(mx, get<0>(c));
	vector<t3> G;
	V[pii(0, 0)] = 1;
	for(int i = 1; i <= mx; i++){
		G.emplace_back(cur, cur+1, -1);
		cur += 1;
		V[pii(i, 0)] = cur;
	}
	for(int i = 0; i <= mx; i++){
		int mx2 = 0, prv = i+1;
		for(t3 c : L){
			if( get<0>(c) == i ) mx2 = max(mx2, get<1>(c));
		}
		for(int j = 1; j <= mx2; j++){
			G.emplace_back(prv, ++cur, -2);
			V[pii(i, j)] = cur;
			prv = cur;
		}
	}
	for(t3 e : L){
		int a, b, c;
		tie(a, b, c) = e;
		G.emplace_back(V[pii(a, b)], cur+1, c);
	}
	printf("Possible\n");
	printf("%d %d\n", cur+1, G.size());
	for(t3 e : G){
		int a, b, c;
		tie(a, b, c) = e;
		printf("%d %d ", a, b);
		if( c == -1 ) printf("X\n");
		else if( c == -2 ) printf("Y\n");
		else printf("%d\n", c);
	}
	printf("1 %d\n", cur+1);
}
