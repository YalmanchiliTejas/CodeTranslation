#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <cassert>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 17;
const int Maxm = 301;
const int Inf = 1000000000;

int GN, GM;
int A, B;
int D[Maxn][Maxn];
int mn[Maxm][Maxm];
int N;
vector <ii> neigh[Maxm];
int dist[Maxm];

int getFirst(int r, int c)
{
	return r * GM + c + 1;
}

bool Check(int val1)
{
	GN = val1; GM = 299 / GN;
	for (int i = 0; i < GN; i++)
		for (int j = 0; j < GM; j++)
			mn[i][j] = 0;
	for (int i = 0; i < A; i++)
		for (int j = 0; j < B; j++)
			for (int koefi = 0; koefi < GN; koefi++)
				for (int koefj = 0; koefj < GM; koefj++)
					mn[koefi][koefj] = max(mn[koefi][koefj], D[i][j] - koefi * (i + 1) - koefj * (j + 1));
	for (int i = 0; i < A; i++)
		for (int j = 0; j < B; j++) {
			bool ok = false;
			for (int koefi = 0; koefi < GN && !ok; koefi++)
				for (int koefj = 0; koefj < GM && !ok; koefj++)
					ok = koefi * (i + 1) + koefj * (j + 1) + mn[koefi][koefj] == D[i][j];
			if (!ok) return false;
		}
	return true;
}

int Get(int v, int t, int X, int Y)
{
	//printf("(%d, %d, %d, %d)\n", v, t, X, Y);
	fill(dist, dist + Maxm, Inf); dist[v] = 0;
	priority_queue <ii> Q; Q.push(ii(-dist[v], v));
	while (!Q.empty()) {
		int v = Q.top().second, d = -Q.top().first; Q.pop();
		if (dist[v] != d) continue;
	//	printf("v = %d, d = %d\n", v, d);
		if (t == v) return d;
		for (int i = 0; i < neigh[v].size(); i++) {
			ii u = neigh[v][i];
			if (u.second == -1) u.second = X;
			if (u.second == -2) u.second = Y;
			//printf("u = (%d, %d)  d = %d\n", u.first, u.second, dist[u.first]);
			if (d + u.second < dist[u.first]) {
				dist[u.first] = d + u.second;
				Q.push(ii(-dist[u.first], u.first));
			}
		}
	}
	return Inf;
}

int main()
{
	scanf("%d %d", &A, &B);
	for (int i = 0; i < A; i++)
		for (int j = 0; j < B; j++)
			scanf("%d", &D[i][j]);
	int siz;
	for (siz = 1; siz <= 299; siz++)
		if (Check(siz)) break;
	if (siz > 299) { printf("Impossible\n"); return 0; }
	N = GN * GM + 1;
	for (int i = 0; i < GN; i++)
		for (int j = 0; j < GM; j++) {
			neigh[getFirst(i, j)].push_back(ii(N, mn[i][j]));
			if (j + 1 < GM)
				neigh[getFirst(i, j)].push_back(ii(getFirst(i, j + 1), -2));
			if (i + 1 < GN)
				neigh[getFirst(i, j)].push_back(ii(getFirst(i + 1, j), -1));
		}
	int M = 0;
	for (int i = 1; i <= N; i++)
		M += neigh[i].size();
	for (int i = 0; i < A; i++)
		for (int j = 0; j < B; j++) {
			int g = Get(getFirst(0, 0), N, i + 1, j + 1);
			if (D[i][j] != g) assert(false);
		}
	printf("Possible\n");
	printf("%d %d\n", N, M);
	for (int i = 1; i <= N; i++)
		for (int j = 0; j < neigh[i].size(); j++) {
			printf("%d %d ", i, neigh[i][j].first);
			if (neigh[i][j].second == -1) printf("X\n");
			else if (neigh[i][j].second == -2) printf("Y\n");
			else printf("%d\n", neigh[i][j].second);
		}
	printf("%d %d\n", getFirst(0, 0), N);
	return 0;
}