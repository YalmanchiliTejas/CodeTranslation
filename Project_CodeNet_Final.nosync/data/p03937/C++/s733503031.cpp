#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=15;
int n,m,a[maxn][maxn],cnt;
bool flag=false;
char c;

// void dfs(int x,int y){
// 	if(x==n && y==m){
// 		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(a[i][j]) return;
// 		flag=true; return;
// 	}
// 	if(flag) return;
// 	if(a[x+1][y]){
// 		a[x+1][y]=0;
// 		dfs(x+1,y);
// 		a[x+1][y]=1;
// 	}
// 	else if(a[x][y+1]){
// 		a[x][y+1]=0;
// 		dfs(x,y+1);
// 		a[x][y+1]=1;
// 	}
// 	else return;
// }

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>c;
			if(c=='#') cnt++;
		}
	}
// 	a[1][1]=0,dfs(1,1);
	if(cnt==n+m-1) puts("Possible");
	else puts("Impossible");
	return 0;
}