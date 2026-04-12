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
int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

const int MX = 200005;
const int MM = 1000000007;

int N, M;
ll D[MX];

int main()
{
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%lld", D+i);
	ll ans = 1e18;
	for(int t = 0; t <= N; t++){
		ll s = 0, e = 1e16, m;
		while(s <= e){
			m = (s+e) / 2;
			ll v = m * (N+1) + t;
			ll ans = 0;
			for(int i = 1; i <= N; i++){
				ans += (D[i] + v+1) / (N+1);
			}
			if( ans <= v ) e = m-1;
			else s = m+1;
		}swap(s, e);
		ans = min(ans, e * (N+1)+t);
	}
	printf("%lld\n", ans);
}

