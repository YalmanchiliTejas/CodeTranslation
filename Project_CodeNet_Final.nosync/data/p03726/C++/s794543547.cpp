#include <stdio.h>
#include <vector>
using namespace std;

vector<int> G[100005];
int N,S[100005];

void dfs(int x, int l)
{
	S[x]++;
	for (int y : G[x]) if (y != l){
		dfs(y,x);
		S[x] += S[y];
	}
}

int main()
{
	scanf ("%d",&N);
	for (int i=1;i<N;i++){
		int x,y; scanf ("%d %d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(1,0);

	if (N % 2){puts("First"); return 0;}
	for (int i=1;i<=N;i++) if (G[i].size() == 1){
		int p = G[i][0];
		int u = 2;
		for (int y : G[p]) if (y != i){
			if (S[p] > S[y]){
				if (S[y] % 2){puts("First"); return 0;}
				u += S[y];
			}
		}
		if (u % 2){puts("First"); return 0;}
	}
	puts("Second");

	return 0;
}