#include<bits/stdc++.h>
using namespace std;

int n, m, a, b, ans;
vector<int> v[10];

int dfs(int cnt, int nw, bitset<10> used){
	int res = 0;
	if(!cnt) return 1;
	used[nw] = true;
	for(int i : v[nw]){
		if(!used[i]) res += dfs(cnt-1, i, used);
	}
	used[nw] = false;
	return res;
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	bitset<10> used(0);
	ans = dfs(n-1, 1, used);
	printf("%d\n", ans);
}
