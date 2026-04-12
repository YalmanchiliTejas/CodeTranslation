#include<bits/stdc++.h>
using namespace std;
int Map[11][11];
const int dx[]={0,1},dy[]={1,0};
signed main(){
	int n,m;scanf("%d%d",&n,&m); 
	for(register int i=1;i<=n;i++)
		for(register int j=1;j<=m;j++){
			char c;
			while((c=getchar())!='.'&&c!='#');
			Map[i][j]=(c=='#');
		}
	queue<pair<int,int> >Q;
	Q.push(make_pair(1,1));Map[1][1]=0;
	while(!Q.empty()){
		int x=Q.front().first,y=Q.front().second,tot=0;Q.pop();
		for(register int i=0;i<2;i++){
			int xx=x+dx[i],yy=y+dy[i];
			if(xx<1||xx>n||yy<1||yy>m||!Map[xx][yy])continue;
			Map[xx][yy]=0;
			tot++;
			Q.push(make_pair(xx,yy));
		}
		if(tot>=2){
			puts("Impossible");
			return 0;
		}
	}
	for(register int i=1;i<=n;i++)
		for(register int j=1;j<=m;j++)
			if(Map[i][j]){
				puts("Impossible");
				return 0;
			}
	puts("Possible");
	return 0;
}