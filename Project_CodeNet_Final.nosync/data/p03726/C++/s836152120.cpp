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

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x1f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

vector <int> conn[100050];
vector <int> son[100050];
int tus;
bool dchk[100050];
int lr[100050][2];
void DFS(int n) {
	dchk[n] = true;
	lr[n][0] = ++tus;
	for (auto it : conn[n]) {
		if (dchk[it]) continue;
		son[n].push_back(it);
		DFS(it);
	}
	lr[n][1] = tus;
}
int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 1; i < N; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		conn[t1].push_back(t2);
		conn[t2].push_back(t1);
	}
	if (N % 2 == 1) return !printf("First\n");

	DFS(1);
	for (i = 1; i <= N; i++) {
		int c = 0;
		for (auto it : son[i]) if (lr[it][1] % 2 == lr[it][0] % 2) c++;
		if (c >= 2) return !printf("First\n");
	}
	return !printf("Second\n");
}