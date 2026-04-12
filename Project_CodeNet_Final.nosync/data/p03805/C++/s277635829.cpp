#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<vector>
#include<string>
#include<string.h>
using namespace std;
int n,m;
bool v[9];
vector<int> e[9];
int dfs(int c,int num){
	if (num == n)return 1;
	int ans = 0;
	int s = e[c].size();
	v[c] = 1;
	for (int i = 0; i < s; i++){
		int cnt = e[c][i];
		if (v[cnt] == 0){
			ans += dfs(cnt, num + 1);
		}
	}
	v[c] = 0;
	return ans;
}

int main(){
	int a, b;
	while (~scanf("%d%d", &n, &m)){
		for (int i = 1; i <= 8; i++){ e[i].clear(); }
		for (int i = 0; i < m; i++){
			scanf("%d%d", &a, &b);
			e[a].push_back(b);
			e[b].push_back(a);
		}
		int ans = 0;
		ans = dfs(1,1);
		printf("%d\n", ans);
	}
	return 0;
}