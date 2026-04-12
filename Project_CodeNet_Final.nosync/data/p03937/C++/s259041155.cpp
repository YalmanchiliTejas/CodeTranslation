#include<bits/stdc++.h>
using namespace std;
bool a[10][10],flg=0;
int h,w;
char c;
void dfs(int x,int y){
	if(flg==1)		return;
//	for(int i=1;i<=h;i++){
//		for(int j=1;j<=w;j++){
//			cout<<a[i][j]<<" ";
//		}
//		cout<<endl; 
//	}
//	cout<<endl;
	if(x==h&&y==w){
		for(int i=1;i<=h;i++){
			for(int j=1;j<=w;j++){
				if(a[i][j]==0)
					return;
			}
		}
		flg=1;
//		exit(0);
		return;
	}
	if(a[x+1][y]==0){
		a[x+1][y]=1;
		dfs(x+1,y);
		a[x+1][y]=0;
	}
	if(a[x][y+1]==0){
		a[x][y+1]=1;
		dfs(x,y+1);
		a[x][y+1]=0;
	}
	if(a[x+1][y]==1&&a[x][y+1]==1)	return;
}
int main(){
	scanf("%d%d%c",&h,&w,&c);
	for(int i=0;i<=9;i++){
		for(int j=0;j<=9;j++){
			a[i][j]=1;
		}
	}
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			scanf("%c",&c);
			if(c=='#'){
				a[i][j]=0;
			}
		}
		scanf("%c",&c);
	}
//	for(int i=1;i<=h;i++){
//		for(int j=1;j<=w;j++){
//			cout<<a[i][j]<<" ";
//		}
//		cout<<endl; 
//	}
	a[1][1]=1;
	dfs(1,1);
	if(flg==1)
		printf("Possible");
	else
		printf("Impossible");
	return 0;
}