#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int n,m;
char s[100][100];
bool vis[100][100];
bool dfs(int x,int y){
	vis[x][y]=1;
	if(x==n-1&&y==m-1)
		return 1;
	if(x+1<n&&s[x+1][y]=='#')
		return dfs(x+1,y);
	if(y+1<m&&s[x][y+1]=='#')
		return dfs(x,y+1);
	return 0;
}
bool check(){
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(s[i][j]=='#'&&vis[i][j]==0)
				return 0;
	return 1;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%s",s[i]);
	if(s[0][0]!='#'||s[n-1][m-1]!='#'||!dfs(0,0))
		puts("Impossible");
	else if(!check()){
		puts("Impossible");
	}
	else{
		puts("Possible");
	}
	//system("pause");
	return 0;
}