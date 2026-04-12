#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
char map[110][110];
bool ins[110][110];
int ans[110];
int qwq[110];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++){
	  	while(map[i][j]!='#'&&map[i][j]!='.') scanf("%c",&map[i][j]);
		if(map[i][j]=='#') ins[i][j]=1;
		if(map[i][j]=='.') ins[i][j]=0;	  	
		ans[i]+=ins[i][j];
		qwq[j]+=ins[i][j];
	  }

//	for(int i=1;i<=n;i++) printf("%d ",ans[i]);puts("");
//	for(int i=1;i<=m;i++) printf("%d ",qwq[i]);puts("");
	
	for(int i=1;i<=n;i++){
		if(ans[i]==0) continue;
		for(int j=1;j<=m;j++)
		  if(qwq[j]!=0) printf("%c",map[i][j]); 
		puts("");
	}
	return 0;
}