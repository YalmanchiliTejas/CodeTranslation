#include<bits/stdc++.h>
using namespace std;
#define maxn 108
int h,w;
char map1[maxn][maxn];
int vis[maxn][maxn];
int if_ok[maxn];
int main(){
	scanf("%d%d",&h,&w);
	for(int i=1;i<=h;i++)
		for(int j=1;j<=w;j++)
			cin>>map1[i][j];
	for(int i=1;i<=h;i++){
		bool flag1=true;
		for(int j=1;j<=w;j++){
			if(map1[i][j]=='#'){
				flag1=false;
				break;
			}
		}
		if(flag1){
			for(int j=1;j<=w;j++){
				vis[i][j]=1;
			}
			if_ok[i]=1;
		}
	}
	for(int i=1;i<=w;i++){
		bool flag1=true;
		for(int j=1;j<=h;j++){
			if(map1[j][i]=='#'){
				flag1=false;
				break;
			}
		}
		if(flag1){
			for(int j=1;j<=h;j++){
				vis[j][i]=1;
			}
		}
	}
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			if(!vis[i][j]){
				cout<<map1[i][j];
			}
		}
		if(!if_ok[i])
			cout<<endl;
	}
	return 0;
}