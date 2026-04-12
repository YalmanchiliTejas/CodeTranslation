#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;
char str[60][60];
int t[60][60];
int on[60][60];
int off[60][60];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int v[60][60];
int last[60][60];
int row[1100];
int col[1100];
int n,m;
int time;
long long ret;
int dfs(int a,int b,int c,int d){
	v[a][b]=d;
	if(a==row[c]&&b==col[c]){
		if(!~last[a][b])ret+=on[a][b];
		else ret+=min(off[a][b]+on[a][b],t[a][b]*(d+time-last[a][b]));
		last[a][b]=time+d;
		return 1;
	}
	for(int i=0;i<4;i++){
		if(a+dx[i]<0||b+dy[i]<0||a+dx[i]>=n||b+dy[i]>=m)continue;
		if(str[a+dx[i]][b+dy[i]]=='#')continue;
		if(~v[a+dx[i]][b+dy[i]])continue;
		int res=dfs(a+dx[i],b+dy[i],c,d+1);
		if(res){
			if(d){
				if(!~last[a][b])ret+=on[a][b];
				else ret+=min(off[a][b]+on[a][b],t[a][b]*(d+time-last[a][b]));
				last[a][b]=time+d;
			}
			return 1;
		}
	}
	return 0;
}
int main(){
	int a,b,c;scanf("%d%d%d",&a,&b,&c);
	n=a;
	m=b;
	for(int i=0;i<a;i++){
		scanf("%s",str[i]);
	}
	for(int i=0;i<a;i++)for(int j=0;j<b;j++)scanf("%d",&t[i][j]);
	for(int i=0;i<a;i++)for(int j=0;j<b;j++)scanf("%d",&on[i][j]);
	for(int i=0;i<a;i++)for(int j=0;j<b;j++)scanf("%d",&off[i][j]);
	ret=0;
	for(int i=0;i<c;i++){
		scanf("%d%d",row+i,col+i);
	}
	for(int i=0;i<a;i++)for(int j=0;j<b;j++)last[i][j]=-1;
	last[row[0]][col[0]]=0;
	time=0;
	ret+=on[row[0]][col[0]];
	for(int i=1;i<c;i++){
		for(int j=0;j<a;j++)for(int k=0;k<b;k++)v[j][k]=-1;
		dfs(row[i-1],col[i-1],i,0);
		time+=v[row[i]][col[i]];
	}
	for(int i=0;i<a;i++)for(int j=0;j<b;j++)if(~last[i][j])ret+=off[i][j];
	printf("%lld\n",ret);
}