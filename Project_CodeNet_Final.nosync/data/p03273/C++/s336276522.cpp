#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 102
char board[N][N];
int hang[N],lie[N];
int h,w;
/*
void cut(){
	int i,j,cnt;
	for( i=0;i<h;i++ )
	{
		cnt=0;
		for( j=0;j<w;j++ ){  //一行都是点 
			if( board[i][j]=='.' )
				cnt++;
			else
				break;
		}
		if( cnt==w )  //一行都是点就删除 
		{
			for( j=0;j<w;j++ )
				vis[i][j]=0;
		}
	}
	for( i=0;i<w;i++ ){
		cnt=0;
		for( j=0;j<h;j++ ){
			if( board[j][i]=='.' )
				cnt++;
			else
				break;
		}
		if( cnt==h )  //一列都是点
		{
			for( j=0;j<h;j++ )
				vis[j][i]=0;
		} 
	}
} */
int main() {
	int i,j;
	cin>>h>>w;
		int flag1;
		for( i=0;i<w;i++ )
			lie[i]=0;
		for( i=0;i<h;i++ ){
			flag1=0;
			for( j=0;j<w;j++ ){
				cin>>board[i][j];
				if( board[i][j]=='#' )  //这行这列有#,不要删除 
				{
					hang[i]=1;
					lie[j]=1;
					flag1=1;
				}
			}
			if( !flag1 )
				hang[i]=0;
		}
		int flag;
		for( i=0;i<h;i++ )
		{
			flag=0;
			for( j=0;j<w;j++ )
			{
				if( hang[i] && lie[j] )
				{
					cout<<board[i][j];
					flag=1;
				}
			}
			if( flag )
				cout<<endl;
		}
	return 0;
	}