#include<bits/stdc++.h>
using namespace std;
const int MAXN=105;
char maze[MAXN][MAXN];
int r[MAXN],c[MAXN];
int h,w;
int main(){
	scanf("%d%d",&h,&w);
	getchar(); 
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			scanf("%c",&maze[i][j]);
			if(maze[i][j]=='.'){
				r[i]++;c[j]++;				
			}
		}
		getchar();
	} 
	for(int i=1;i<=h;i++){
		if(r[i]==w) continue;
		for(int j=1;j<=w;j++){
			if(c[j]==h) continue;
			printf("%c",maze[i][j]);
		}
		printf("\n");
	}
	return 0;
}