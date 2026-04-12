#include<bits/stdc++.h>
using namespace std;
int xd[2]={0,1};
int yd[2]={1,0};
int hy,wx,total;
int yes[9][9];
char data;
void mygame(int x,int y);

int main(){
	cin>>hy>>wx;
	for(int i=1;i<=hy;i++){
		for(int j=1;j<=wx;j++){
			cin>>data;
			if(data=='.')
				yes[j][i]=0;
			else 
				yes[j][i]=1;
		}
	}
	if(yes[1][1]&&yes[wx][hy]){
		yes[1][1]=0;
		mygame(1,1);
		yes[1][1]=1;
	}
	if(total>0)
		cout<<"Possible";
	else
		cout<<"Impossible";
	return 0;
}
void mygame(int x,int y){
	if(x==wx&&y==hy){
		for(int i=1;i<=wx;i++){
			for(int j=1;j<=hy;j++){
				if(yes[i][j]==0)
					continue;
				else
					return;
			}
		}
		total++;
		return;
	}
	int xx,yy;
	for(int i=0;i<2;i++){
		xx=x+xd[i];
		yy=y+yd[i];
		if(xx<=wx&&yy<=hy&&yes[xx][yy]){
			yes[xx][yy]=0;
			mygame(xx,yy);
			yes[xx][yy]=1;
		}
			
	}
}

