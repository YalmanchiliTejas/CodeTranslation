#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
char c[10][10];
bool flag;
int h,w,chk[10][10];
int way_x[2] = {1,0};
int way_y[2] = {0,1};//下、右 
bool jud(int i)
{
	for(int i = 1;i <= h;i++)
	{
		for(int j = 1;j <= w;j++)
		{
	//		printf("%d ",chk[i][j]);
			if(c[i][j] == '#' && chk[i][j] == 0)
			return 0;
		}
	//	printf("\n");
	}
	return 1;
} 
void dfs(int x,int y)//下。右 
{
	if(flag == 1)	return;
	if(x == h && y == w)
	{
		if(jud(1) == 1)
		{
			flag = 1;
			printf("Possible");
			return;
		}
	}
	for(int i = 0;i <= 1;i++)
	{
		if(c[x+way_x[i]][y+way_y[i]] != '#')
			continue;
		x += way_x[i];
		y += way_y[i];
		chk[x][y] = 1;
		dfs(x,y);
		chk[x][y] = 0;
		x -= way_x[i];
		y -= way_y[i];
	}
	return;
}
int main(){
	scanf("%d%d",&h,&w);
	for(int i = 1;i <= h;i++)
	{
		getchar();
		for(int j = 1;j <= w;j++)
		{
			scanf("%c",&c[i][j]);
		}
	}
//	for(int i = 1;i <= h;i++)
//	{
//		for(int j = 1;j <= w;j++)
//		{
//			printf("%c ",c[i][j]);
//		}
//		cout<<endl;
//	}
	chk[1][1] = 1;
	dfs(1,1);
	if(flag == 0)
	{
		printf("Impossible");
	}
	return 0;
}
