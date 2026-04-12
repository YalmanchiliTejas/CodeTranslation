#include<bits/stdc++.h>
using namespace std;
int m,n;
bool f;
char a[10][10],c[10];
int movex[5]={1,0};
int movey[5]={0,1};
bool pb(){
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			//cout<<a[i][j];
			if(a[i][j]=='#'){
				//cout<<i<<" "<<j;
				return false;
			}
		}
		//cout<<endl;
	}
    return true;
}
void dfs(int x,int y){
	if(x==m&&y==n){
		//cout<<1;
		if(pb()==true){
		    cout<<"Possible";
		    f=true;
			exit(0);	
		}
		else return ;
	}
	for(int i=0;i<=1;i++){
		int xx=x+movex[i];
		int yy=y+movey[i];
		
		if(a[xx][yy]=='#'&&xx<=m&&yy<=n){
			//cout<<xx<<yy<<endl;
			a[xx][yy]='.';
			dfs(xx,yy);
			a[xx][yy]='#';
		}
	}
}
int main()
{
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		scanf("%s",c+1);
		for(int j=1;j<=n;j++){
			a[i][j]=c[j];
		}
	}
	a[1][1]='.';
	dfs(1,1);
	if(f==true)return 0;
	cout<<"Impossible";
	return 0;
 } 