#include<iostream>
#include<algorithm>
using namespace std;
int h,w;
bool ans;
char z;
bool vis[10][10];
void DFS(int y,int x){
	vis[y][x]=true;
	if(y==h-1&&x==w-1){
		bool ok=true;
		for(int i=0;i<h;i++)for(int j=0;j<w;j++)if(vis[i][j]==false)ok=false;
		if(ok)ans=true;
		return;
	}
	if(x<w-1)if(vis[y][x+1]==false)DFS(y,x+1);
	if(y<h-1)if(vis[y+1][x]==false)DFS(y+1,x);
	vis[y][x]=false;
}
int main(){
	ans=false;
	cin>>h>>w;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			vis[i][j]=false;
			cin>>z;
			if(z=='.')vis[i][j]=true;
		}
	}
	DFS(0,0);
	if(ans)cout<<"Possible"<<endl;
	else cout<<"Impossible"<<endl;
	return 0;
}