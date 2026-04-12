#include<bits/stdc++.h>
using namespace std;

int h,w,vis[105][105];
char mp[105][105];

void dfs(int x,int y){
	bool bj=0;
	for (int i=1;i<=h;i++) if (mp[i][y]!='.') {bj=1;break;}
	if (!bj)
	for (int i=1;i<=h;i++) vis[i][y]=1;
	bj=0;
	for (int i=1;i<=w;i++) if (mp[x][i]!='.') {bj=1;break;}
	if (!bj)
	for (int i=1;i<=w;i++) vis[x][i]=1;
	return;
}

int main(){
	cin>>h>>w;
	getchar();
	for (int i=1;i<=h;i++){
		for (int j=1;j<=w;j++) mp[i][j]=getchar();
		getchar();
	}
	for (int i=1;i<=h;i++)
	for (int j=1;j<=w;j++)
	if ((!vis[i][j])&&(mp[i][j]=='.')) dfs(i,j);
	for (int i=1;i<=h;i++){
		bool bj=0;
		for (int j=1;j<=w;j++)
		if (!vis[i][j]) printf("%c",mp[i][j]),bj=1;
		if (bj) printf("\n");
	}
	return 0;
}