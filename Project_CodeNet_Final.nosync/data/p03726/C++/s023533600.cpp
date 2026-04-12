#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <bitset>

using namespace std;
typedef pair<int, int> Pi;
typedef long long ll;
#define pii Pi
#define pll PL
#define Fi first
#define Se second
#define pb(x) push_back(x)
//#define sz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<ll, ll> pll;
typedef long double ldouble;
typedef pair<double, double> pdd;

const double PI = acos(-1);
const double EPS = 1e-9;

const int MX = 100005;
const int MM = 1000000007;

vector<int> G[MX];
int N;

int dfs(int x, int p = -1){
	int cnt = 0;
	for(int c : G[x]){
		if( c == p ) continue;
		cnt += dfs(c, x);
	}
	if( p == -1 && cnt == 0 ) return 2;
	if( cnt == 0 ) return 1;
	else if( cnt == 1 ) return 0;
	else return 2;
}

int main()
{
	scanf("%d", &N);
	for(int i = 1; i < N; i++){
		int a, b;
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	if( dfs(1) >= 2 ) printf("First\n");
	else printf("Second\n");
}
