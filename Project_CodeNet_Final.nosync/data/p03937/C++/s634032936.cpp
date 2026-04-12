#include<bits/stdc++.h>
using namespace std;
const int N=15;
int n,m,ans,f[N][N];
char s[N][N];
void dfs(int x,int y,int z){
	if (z==ans){
		puts("Possible");
		exit(0);
	}
	if (s[x+1][y]=='#')dfs(x+1,y,z+1);
	if (s[x][y+1]=='#')dfs(x,y+1,z+1);
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)scanf("%s",s[i]+1);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (s[i][j]=='#')ans++;
	if (s[1][1]!='#'){
		puts("Impossible");
		return 0;
	}
	dfs(1,1,1);
	puts("Impossible");
}