#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <string>
using namespace std;

const int qq = 1e2 + 10;
int num[qq];
int gra[qq][qq];
int vis[qq];
int n, m, k, sum;

void dfs(int rt, int cnt){
	if(cnt == n){
		sum++;
		return;
	}
	for(int i = 1; i <= n; ++i)
		if(i != rt && gra[rt][i] && !vis[i]){
			vis[i] = 1;
			dfs(i, cnt + 1);
			vis[i] = 0;
		}
}

int main(){
	scanf("%d%d", &n, &m);
	memset(gra, 0, sizeof(gra));
	for(int i = 0; i < m; ++i){
		int a, b;scanf("%d%d", &a, &b);
		gra[a][b] = gra[b][a] = 1;
	}
	sum = 0;
	memset(vis, 0, sizeof(vis));
	vis[1] = 1;
	dfs(1, 1);
	printf("%d\n", sum);
	return 0;
}