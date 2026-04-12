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
#define Fi first  
#define Se second  
#define pb(x) push_back(x)  
#define szz(x) ((int)(x).size())  
#define rep(i, n) for(int i=0;i<n;i++)  
#define all(x) (x).begin(), (x).end()  
#define ldb ldouble  

typedef unsigned int uint;
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
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

const int MX = 3005;

ll D[MX][MX], C[MX][MX];
int N, M;

ll pw(ll a, ll b, ll M){
	ll r = 1;
	while(b){
		if(b&1) r = r*a % M;
		a = a*a % M; b /= 2;
	}
	return r;
}

int main()
{
	scanf("%d%d", &N, &M);
	C[0][0] = 1;
	for(int i = 1; i < MX; i++){
		C[i][0] = 1;
		for(int j = 1; j <= i; j++) C[i][j] = (C[i-1][j-1] + C[i-1][j]) % M;
	}
	D[0][0] = 1;
	for(int i = 1; i <= N; i++){
		D[i][0] = 1;
		for(int j = 1; j <= i; j++){
			D[i][j] = (D[i-1][j-1] + D[i-1][j] * (1+j)) % M;
		}
	}
	ll ans = 0;
	for(int i = 0; i <= N; i++){
		ll tot = 0;
		for(int j = 0; j <= i; j++){
			ll m = pw(pw(2, N-i, M), j, M) * D[i][j] % M;
			tot = (tot + m) % M;
		}
		tot = tot * C[N][i] % M * pw(2, pw(2, N-i, M-1), M) % M;
		if(i%2 == 1) ans = (ans - tot + M) % M;
		else ans = (ans + tot) % M;
	}
	printf("%lld\n", ans);
}
