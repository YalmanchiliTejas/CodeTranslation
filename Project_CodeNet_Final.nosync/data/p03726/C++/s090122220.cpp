#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n;
vector<int> v[maxn];
int x, y;

int dfs(int i, int fa){
	int cnt = 0;
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa) continue;
		cnt += dfs(to, i);
	}
	if(cnt > 1) printf("First"), exit(0);
	return cnt ^ 1; 
}

int main(){
	scanf("%d", &n);
	for(int i = 1;i < n;i++){
		scanf("%d%d", &x, &y);
		v[x].push_back(y), v[y].push_back(x);
	}
	printf(dfs(1, 0) ? "First" : "Second");
}