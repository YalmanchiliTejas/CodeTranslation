#include<bits/stdc++.h>
using namespace std;
int a[10][10],m,n,flag;
char kk[10];
void dfs(int x,int y){
	if(x==m-1&&y==n-1){
		for(int i=0;i<m;++i)for(int j=0;j<n;++j)if(a[i][j])return;
		flag = 1;    
        return;
    }
	if(flag==1)return;
    if(a[x+1][y]){
        a[x+1][y]=0;
        dfs(x+1,y);
        a[x+1][y]=1;
    }
    if(a[x][y+1]){
        a[x][y+1]=0;
        dfs(x,y+1);
        a[x][y+1]=1;
    }
    if(!a[x][y+1]&&!a[x+1][y])return;
}
int main(){
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;++i){
        cin>>kk;
        for(int j=0;j<n;++j)if(kk[j]=='#')a[i-1][j]=1;
    }
    if(a[0][0]){
        a[0][0]=0;
        dfs(0,0);
    }
    if(flag)cout<<"Possible"<<endl;
    else cout<<"Impossible"<<endl;
    return 0; 
}