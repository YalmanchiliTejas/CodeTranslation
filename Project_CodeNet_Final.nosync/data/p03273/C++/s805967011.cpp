#include <iostream>
#include <cstdio>
using namespace std;
int n,m;
char sh[105][105];
bool is_need(int x)
{
	for(int i=0;i<m;i++){
		if(sh[x][i]=='#')return false;
	}
	return true;
}
void change(int x)
{
	for(int i=0;i<m;i++)
		sh[x][i]='*';
}
bool is_need2(int x)
{
	for(int i=0;i<n;i++){
		if(sh[i][x]=='#')return false;
	}
	return true;
}
void change2(int x)
{
	for(int i=0;i<n;i++)
		sh[i][x]='*';
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%s",sh[i]);
	for(int i=0;i<n;i++)
		if(is_need(i))change(i);
	for(int i=0;i<m;i++)
		if(is_need2(i))change2(i);
	/*for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			printf("%c",sh[i][j]);
		printf("\n");
	}*/
	for(int i=0;i<n;i++){
		int f=0;
		for(int j=0;j<m;j++)
			if(sh[i][j]!='*'){
				f=1;printf("%c",sh[i][j]);
			}
		if(f)printf("\n");
	}
	return 0;
}