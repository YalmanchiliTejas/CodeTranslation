#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)

using namespace std;
int H, W;
char G[100][100];

void row(int r){
	for(int i = 0; i < W; i++)
		if(G[r][i] == '#') return;
	for(int i = 0; i < W; i++) G[r][i] = 'x';
}

void col(int c){
	for(int i = 0; i < H; i++)
		if(G[i][c] == '#') return;
	for(int i = 0; i < H; i++) G[i][c] = 'x';
}

int main(void){
	//IO("test.in", "test.out");
	scanf("%d%d", &H, &W), cin.get();
	for(int i = 0; i < H; i++){
		for(int j = 0; j < W; j++) G[i][j] = cin.get();
		cin.get();
	}
	for(int i = 0; i < H; i++) row(i);
	for(int i = 0; i < W; i++) col(i);
	for(int i = 0; i < H; i++){
		bool s = false;
		for(int j = 0; j < W; j++)
			if(G[i][j] != 'x')
				printf("%c", G[i][j]), s = true;
		if(s) printf("\n");
	}
}