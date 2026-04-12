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

using namespace std;
typedef long long ll;
typedef pair<int,int> Pi;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) x.begin(), x.end()

int n, m;
char ch[10][10];

void solve(){
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++)scanf("%s", ch[i]+1);
	int d[10][10] = {};
	memset(d, -1, sizeof d);
	d[1][1] = (ch[1][1] == '#');
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(i!=1||j!=1){
		if(ch[i][j] == '#'){
			if(ch[i-1][j] == '#' && d[i-1][j] != -1)d[i][j] = d[i-1][j];
			if(ch[i][j-1] == '#' && d[i][j-1] != -1)d[i][j] = max(d[i][j], d[i][j-1]);
			if(d[i][j] != -1)d[i][j]++;
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(ch[i][j] == '#')d[n][m] --;
	printf("%s", d[n][m] == 0 ? "Possible" : "Impossible");
}

int main(){
	int Tc = 1; //scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}