#include<iostream>
#include<string>
#include<cstring>
using namespace std;
char a[10][10];
int u;
int n,m;
void dfs(int x,int y){
	a[x][y]='.';
	if(x==n&&y==m) {
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=m;j++) {
				if(a[i][j]=='#')
					return;
			}
		}
		u=1;
		return;
	}
	int o=0;
	if(a[x][y+1]=='#') {
		dfs(x,y+1);
		a[x][y+1]='#';
		o=1;
	}
	if(a[x+1][y]=='#') {
		dfs(x+1,y);
		a[x][y+1]='#';
		o=1;
	}
	if(o==0)
	return;
}
int main() {
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	dfs(1,1);
	if(u==1) {
		cout<<"Possible"<<'\n';
		return 0;
	}
	else {
		cout<<"Impossible"<<'\n';
		return 0;
	}
	return 0;
}