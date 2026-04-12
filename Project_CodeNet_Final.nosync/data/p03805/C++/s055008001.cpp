#include<algorithm>
#include<limits.h>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>

int N = 0, M = 0;
bool edge[10][10] = {false};

bool tf[10] = { false };

int ans = 0;

bool solve(int a) {
	//printf("%d ",a);
	bool t = true;
	tf[a] = true;
	for (int i = 0; i < N; i++) {
		if (tf[i] == false)
			t = false;
	}
	if (t) {
	//	printf("Yes");
		ans++;
		tf[a] = false;
	} else {
		for (int i = 0; i < N; i++) {
			if (!tf[i] && edge[a][i])
				solve(i);
		}
		tf[a] = false;
	}
	//printf("\n");
	return true;
}

int main(void) {
	
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++) {
		int a = 0, b = 0;
		scanf("%d%d", &a, &b);
		edge[a - 1][b - 1] = true;
		edge[b - 1][a - 1] = true;
	}
	for (int i = 0; i < N; i++) {
		memset(tf, false, sizeof(tf));
		tf[0] = true;
		if(edge[0][i])
			solve(i);
	}
	printf("%d\n", ans);
	return 0;
}