#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int h,w;
int fie[61][61];
int data[61][61][4];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int ok[4];
bool flag;

void dfs(int x,int y){
	int muki=1;
	int ug=0;
	while(1){
		int lv=0;
		if(x==0 && y==0){
			if(ok[0]==1 && ok[1]==1 && ok[2]==1){
				ok[3]=1;
				return;
			}
		}
		if(x==w-1 && y==0){
			ok[2]=1;
			ug=1;
		}
		if(x==w-1 && y==h-1){
			ok[1]=1;
			ug=2;
		}
		if(x==0 && y==h-1){
			ok[0]=1;
			ug=3;
		}
		for(int i=0;i<4;i++){
			if(data[y][x][i]!=ug && data[y][x][i]!=-1)return;
		}
		if(data[y][x][muki]!=-1)return;
		data[y][x][muki]=ug;
		for(int i=0;i<4;i++){
			int dl=(muki+1-i+4)%4;
			int nx=x+dx[dl],ny=y+dy[dl];
			if(nx<0 || nx>=w || ny<0 || ny>=h)continue;
			if(fie[ny][nx]==0){
				muki=dl;
				y=ny;
				x=nx;
				break;
			}
		}
	}
}

int main(void){
	while(1){
		scanf("%d%d",&h,&w);
		if(h==0 && w==0)break;
		memset(fie,-1,sizeof(fie));
		for(int i=0;i<h;i++){
			string str;
			cin >> str;
			for(int j=0;j<w;j++){
				if(str[j]=='.')fie[i][j]=0;
				else fie[i][j]=-1;
			}
		}
		memset(data,-1,sizeof(data));
		flag=true;
		memset(ok,0,sizeof(ok));
		dfs(0,0);
		for(int i=0;i<4;i++){
			if(ok[i]==0)flag=false;
		}
		printf("%s\n",flag?"YES":"NO");
	}
	return 0;
}