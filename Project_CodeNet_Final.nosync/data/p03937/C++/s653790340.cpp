#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
int ok=0;
char c[10][10];
int h,w;
int a=0;
void dfs(int x,int y,int step){
	if(step==a)
	ok=1;
	if(c[x+1][y]=='#')
	dfs(x+1,y,step+1);
	if(c[x][y+1])
	dfs(x,y+1,step+1);
}
int main(){
	scanf("%d %d\n",&h,&w);
	for(int i=0;i<h;i++)
	for(int j=0;j<w;j++){
	while(scanf("%c",&c[i][j])&&c[i][j]=='\n');
	if(c[i][j]=='#')
	a++;
	}
	dfs(0,0,1);
	if(c[0][0]=='.')
	ok=0;
	printf("%s",ok?"Possible":"Impossible");
}