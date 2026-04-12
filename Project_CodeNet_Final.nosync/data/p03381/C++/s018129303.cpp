#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include <iomanip>

#include <algorithm>

#include <vector>

#include <stack>

#include <queue>

#include <cmath>

#include <set>

#include <map>

#include <string>

#include <numeric>

#include <cstdio>

#include <cstdlib>

#include <ctime>

#include <iterator>

#include <cstring>

using namespace std;


const int INF = 10000000;

typedef pair<int, int> P;
typedef long long ll;
#define PB push_back
#define rep(i, a) for (int i = 0; i < a; i++)

//char maze[100][101];

int sx, sy;

int gx, gy;

int qqq;

//各座標までの最短距離

int d[100][100];


//移動方向のベクトル

int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };

int ans = 0;
pair<int, int> red[101], blue[101];
//ll a[200000], b[20000];

/*
//ユークリッドの互除法
ll gcd(ll x, ll y) {
if (x < y) swap(x, y);
if (y == 0) return x;
return gcd(y, x%y);
}

int isPrime(int x) {
int i;
if (x < 2) return 0;
else if (x == 2) return 1;
if (x % 2 == 0) return 0;
for (int i = 3; i*i <= x; i += 2)
if (x%i == 0) return 0;
return 1;
}

int v_find(std::vector<int> vec, int number) {
auto itr = std::find(vec.begin(), vec.end(), number);
if (itr != vec.end()) { // 発見できたとき
return 1;
}
else { // 発見できなかったとき
return 0;
}
}

int ok = 1000; //解が存在する値
int ng = -1;   //解が存在しない値

ll BIG = 10000000000;

ll POW(ll a, ll b) {
ll c = 1;
for (int i = 0; i < b; ++i) {
c *= a;
}
return c;
}

int Kaijou(int a) {
if (a < 2) return 1;
return a * Kaijou(a - 1);
}


ll aa[51];

pair<int, int> Sc[50];

int MOD = 1000000007;
int imos[200001];
int br[100000];
int grid[1001][1001];
ll bigdp[1099][1099];
int used[1000][1000];

//逆元の計算用(pは素数のときb=p-2で逆元)
ll calc(int a, int b, int p) {
if (b == 0) return 1;
if (b % 2 == 0) {
ll d = calc(a, b/2,p);
return (d*d) % p;
}
else {
return (a*calc(a, b - 1, p)) % p;
}
}

int h, w;
ll dp[1000][1000];

ll f(int a, int b) {
if (dp[a][b]) return dp[a][b];
ll m = 1;
if (a) if(grid[a-1][b]>grid[a][b]) m =(m+f(a-1,b))%MOD;
if (b) if (grid[a][b-1]>grid[a][b]) m =(m+ f(a, b - 1))%MOD;
if (a != h - 1) if (grid[a + 1][b]>grid[a][b]) m =(m+ f(a + 1, b))%MOD;
if (b != w - 1) if (grid[a][b+1]>grid[a][b])  m =(m+ f(a, b + 1))%MOD;
dp[a][b] = m;
return m;
}
*/

int main() {
	int n;
	cin >> n;
	int b[200002] = { 0 };
	int x[200002] = { 0 };
	rep(i, n) {
		cin >> b[i];
		x[i] = b[i];
	}
	sort(b, b + n);
	int a2;
	rep(i, n) {
		if (b[n / 2] == x[i]) {
			a2 = i;
		}
	}
	rep(i, n) {
		if (x[i] > b[n / 2 - 1]) cout << b[n / 2 - 1] << endl;
		else cout << b[n / 2] << endl;
	}
	return 0;
}