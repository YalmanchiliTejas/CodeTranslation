#include<bits/stdc++.h>
using namespace std;
char walk[10][10],point[100][2];
int sm;
bool jud=false;
int h,w;
void dfs(int x,int y,int all) {
//	cout<<all<<endl;
	if(x==h-1&&y==w-1) {
		if(all-1==0)jud=true;
		return ;
	}
	if(walk[x+1][y]=='.'&&walk[x][y+1]=='.')return; 
	if(walk[x+1][y]=='#')
		dfs(x+1,y,all-1);
	if(walk[x][y+1]=='#')
		dfs(x,y+1,all-1);
	return ;
}
int main() {
	scanf("%d%d",&h,&w);
	for(int i=0; i<h; i++)
		scanf("%s",walk[i]);
	int t=0;
	for(int i=0; i<h; i++)
		for(int j=0; j<w; j++) {
			if(walk[i][j]=='#') {
//				point[++t][1]=i;
//				point[t][2]=j;
				sm++;
			}
		}
	dfs(0,0,sm);
	if(jud) {
		printf("Possible");
		return 0;
	}
	printf("Impossible");
	return 0;
}
