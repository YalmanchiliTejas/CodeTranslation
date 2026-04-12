#include<iostream>
using namespace std;

int used[8];
int connect[8][8];

int N,M;

int dfs(int now, int depth){
	if(used[now]) return 0;
	if(depth == N) return 1;
	used[now] = 1;
	int ans = 0;

	for(int i=0;i<N;i++){
		if(connect[now][i]){
			ans += dfs(i, depth+1);
		}
	}

	used[now] = 0;
	return ans;
}

int main(){
	cin >> N >> M;
	int a[30], b[30];
	for(int i=0;i<M;i++){
		cin >> a[i] >> b[i];
		a[i]--; b[i]--;
	}

	for(int i=0;i<M;i++){
		connect[a[i]][b[i]] = connect[b[i]][a[i]] = 1;
	}

	cout << dfs(0,1) << endl;
	return 0;
}
