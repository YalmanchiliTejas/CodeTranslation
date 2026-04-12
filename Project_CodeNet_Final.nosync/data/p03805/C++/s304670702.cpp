#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int G[10][10];

int main(void)
{
	cin >> N >> M;
	
	int a, b;
	for(int i = 0; i < M; i++){
		cin >> a >> b;
		G[a][b] = G[b][a] = 1;
	}
	
	int perm[10];
	for(int i = 1; i <= N; i++) perm[i] = i;
	
	int ans = 0, pos;
	do{
		pos = 1;
		for(int i = 2; i <= N; i++){
			if(!G[pos][perm[i]]) goto NG;
			pos = perm[i];
		}
		ans++;
		NG:;
	}while( next_permutation(perm+2, perm+N+1) );
	
	cout << ans << endl;
	return 0;
}