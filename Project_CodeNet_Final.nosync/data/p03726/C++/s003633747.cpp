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
typedef long long ll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ldouble;
typedef pair<double, double> pdd;

int n;
vector <int> E[100010];
int d[100010];
int ok;

void dfs(int x, int fa) {
	int cnt = 0;
	for(int e : E[x]) if(e != fa){
		dfs(e, x);
		if(d[e] == 0) ++cnt;
	}
	if(cnt == 0) d[x] = 0;
	else if(cnt == 1) d[x] = 1;
	else ok = 1;
}

void solve(){
	scanf("%d", &n);
	rep(i, n-1){
		int x, y; scanf("%d%d", &x, &y);
		E[x].pb(y);
		E[y].pb(x);
	}
	if(n == 2) {
		puts("Second");
		return;
	}
	int f = 1;
	for(int i=1;i<=n;i++) if(sz(E[i]) > 1) f = i;
	dfs(f, -1);
	puts(ok ? "First" : "Second");
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		// printf("Case #%d\n", tc);
		solve();
	}
	return 0;
};