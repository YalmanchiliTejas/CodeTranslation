#include<bits/stdc++.h>

using namespace std;
#define nn 12

int n,m;char buf[nn][nn];
int vis[nn][nn];
#define err {puts("Impossible");exit(0);}
int main()
{
	int x=0,y=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf("%s",buf[i]);
	
	while(x!=n-1 or y!=m-1)
	{
		if(buf[x][y]!='#') err;
		vis[x][y]=1;
		if(buf[x+1][y]=='#') x++;
		else if(buf[x][y+1]=='#') y++;
		else err;
	}
	vis[x][y]=1;
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) 
		if(!vis[i][j] and buf[i][j]=='#') err;
	puts("Possible");
}