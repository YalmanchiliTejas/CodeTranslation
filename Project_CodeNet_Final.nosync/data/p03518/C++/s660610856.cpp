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

const int MX = 205;
const int MM = 1000000007;

int D[MX];
int N;
vector<int> L;

void rot(int k){
	L.push_back(k);
	for(int i=k;i<N;i++)
		swap(D[i],D[i-k]);
}

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; i++) scanf("%d", D+i);
	for(int i = 1; i <= N; i++){
		rot(1);
		for(int j = 1; j < N; j++){
			if(D[0] < D[N-1]) rot(N-1);
			rot(1);
		}
	}
	printf("%d\n", L.size());
	for(int c : L) printf("%d\n", c);
}
