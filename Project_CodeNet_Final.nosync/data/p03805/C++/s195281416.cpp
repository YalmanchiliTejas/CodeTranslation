// acdart
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <string>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <cstdlib>
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define X first
#define Y second
#define F first
#define S second
#define MOD9 1000000009ll
#define MOD7 1000000007ll
#define MOD
#define INF  1023456789ll
#define INF16 10000000000000000ll
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define SZ(x) ((int)(x).size())
#define MAXN 10010
#define MAXM
#define ALL(x) ((x).begin()),((x).end())
#define RESET(a,b) memset(a,b, sizeof a)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
#define LEN(X) strlen(X)
#define FI(a,b,c) for(int a=b; a<c; a++)
#define FD(a,b,c) for(int a=b; a>c; a--)
using namespace std;
typedef long long ll;
typedef long long LL;
typedef double db;
typedef double D;
typedef long double ld;
typedef long double LD;
/*********default*********/

int n, m, w[10][10] = {0}, ans = 0, vis[10] = {0};

void solve(int v, int s){
	if (s == n){
		ans++;
		return;
	}
	for (int i = 2; i <= n; i++){
		if (!vis[i] && w[v][i]){
			vis[i] = 1;
			solve(i, s + 1);
			vis[i] = 0;
		}
	}
}

int main()
{
	int x, y;
	
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++){
		scanf("%d%d", &x, &y);
		w[x][y] = w[y][x] = 1;
	}
	vis[1] = 1;
	solve(1, 1);
	printf("%d\n", ans);
}