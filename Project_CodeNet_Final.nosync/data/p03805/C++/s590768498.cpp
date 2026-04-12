#include <cstdio>

constexpr int MAX_N = 8;

int dfs(int n, int sum = 0);

int N, M;
bool v[MAX_N] = {};
bool e[MAX_N][MAX_N] = {};

int main(){
	scanf("%d%d", &N, &M);

	for(int i = 0; i < M; ++i){
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;

		e[a][b] = true;
		e[b][a] = true;
	}

	printf("%d\n", dfs(0));
	return 0;
}

int dfs(int n, int sum){
	if(sum == N - 1){
		return 1;
	}

	int res = 0;
	v[n] = true;

	for(int i = 0; i < N; ++i){
		if(e[n][i] && !v[i]){
			res += dfs(i, sum + 1);
		}
	}

	v[n] = false;
	return res;
}
