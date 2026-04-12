#include<cstdio>
#include<iostream>
using namespace std;

const int N = 15;

int h,w,f=1;
char c[N][N];
int cnt[N],b[N][N];

void DFS(int x,int y){
	b[x][y]=1;
	if(x==h && y==w) return;
	if(c[x][y+1]=='#' && c[x+1][y]=='#'){ f=0;return; }
	if(c[x][y+1]=='#') { DFS(x,y+1);return; }
	if(c[x+1][y]=='#') { DFS(x+1,y);return; }
	f=0;return;
}
int main(){
	cin>>h>>w;
	for(int i=1;i<=h;i++) scanf("%s",c[i]+1);
	
	DFS(1,1);
	
	if(!b[h][w]) f=0;
	for(int i=1;i<=h;i++) for(int j=1;j<=w;j++) if((c[i][j]!='#' && b[i][j])|| (c[i][j]=='#' && !b[i][j])) f=0;
	
	if(f) puts("Possible");
	else puts("Impossible");
	return 0;
}