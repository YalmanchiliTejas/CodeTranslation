#include<bits/stdc++.h>
using namespace std;
int h,w,tmp;
char b[10];
int a[10][10];
void dfs(int x,int y){
    if(x==h-1&&y==w-1){
        for(int i=0;i<h;i++)
			for(int j=0;j<w;j++){
            if(a[i][j])return;
        }
        tmp=1;
        return;
    }
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
}
int main(){
    scanf("%d%d",&h,&w);
    for(int i=0;i<=h;i++){
        gets(b);
        for(int j=0;j<w;j++)
        if(b[j]=='#')a[i-1][j]=1;
    }
    if(a[0][0]){
        a[0][0]=0;
        dfs(0,0);
    }
    if(tmp)cout<<"Possible"<<endl;
    else cout<<"Impossible"<<endl;
    return 0;
} 