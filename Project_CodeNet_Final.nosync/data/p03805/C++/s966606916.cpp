#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
	int n, m; scanf("%d %d", &n, &m);
	int e[8][8] = {};
	for(int i = 0; i < m; i++){
		int a, b; scanf("%d %d", &a, &b); a--; b--;
		e[a][b] = e[b][a] = 1;
	}
	int v[8] = {0, 1, 2, 3, 4, 5, 6, 7};
	int res = 0;
	do{
		int f = 1;
		for(int i = 0; i < n - 1; i++) if(e[v[i]][v[i + 1]] == 0) f = 0;
		res += f;
	}while(next_permutation(v + 1, v + n));
	printf("%d\n", res);
	return 0;
}