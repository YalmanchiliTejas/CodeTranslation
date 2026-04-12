#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

char a[105][105];
int grid[105][105];
int iran_x[105];
int iran_y[105];

vector<int>vec;

int main() {

	int H,W;

	scanf("%d %d",&H,&W);

	int i,j;

	for(i=0;i<H;i++){
		scanf("%s",a[i]);
	}

	for(i=0;i<H;i++){
		for(j=0;j<W;j++){
			if(a[i][j]=='.'){grid[i][j]=0;}
			else{grid[i][j]=1;}
		}
	}

	while(1){
		int flag=0;

		for(i=0;i<H;i++){
			if(iran_y[i]==1){continue;}
			int cnt=0;
			for(j=0;j<W;j++){
				if(a[i][j]=='.' || a[i][j]=='_'){cnt++;}
			}
			if(cnt==W){
				flag=1;
				for(j=0;j<W;j++){
					a[i][j]='_';
				}
				iran_y[i]=1;
				break;
			}
		}
		for(j=0;j<W;j++){
			if(iran_x[j]==1){continue;}
			int cnt=0;
			for(i=0;i<H;i++){
				if(a[i][j]=='.' || a[i][j]=='_'){cnt++;}
			}
			if(cnt==H){
				flag=1;
				for(i=0;i<H;i++){
					a[i][j]='_';
				}
				iran_x[j]=1;
				break;
			}
		}
		if(flag==0){break;}
	}
	int cnt_y=H;
	for(i=0;i<H;i++){
		for(j=0;j<W;j++){
		if(iran_y[i]==1){grid[i][j]=-1;}
		}
		if(iran_y[i]==1){cnt_y--;}
	}
	int cnt_x=W;
	for(j=0;j<W;j++){
		for(i=0;i<H;i++){
		if(iran_x[j]==1){grid[i][j]=-1;}
		}
		if(iran_x[j]==1){cnt_x--;}
	}

	for(i=0;i<H;i++){
		for(j=0;j<W;j++){
			if(grid[i][j]!=-1){
			vec.push_back(grid[i][j]);
			}
		}
	}
	for(i=0;i<cnt_y;i++){
		for(j=0;j<cnt_x;j++){
			if(vec[i*cnt_x+j]==0){printf(".");}
			else if(vec[i*cnt_x+j]==1){printf("#");}
	}
		printf("\n");
	}

	return 0;
}