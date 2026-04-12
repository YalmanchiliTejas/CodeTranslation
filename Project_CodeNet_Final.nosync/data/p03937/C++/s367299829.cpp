#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int h,w;
int ans;
char mp[8][8];
char mp2[8][8];
bool check(){
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(mp[i][j]!=mp2[i][j])return 0;
        }
    }
    return 1;
}
void dfs(int x,int y){
    if(x<0||x>=h)return ;
    if(y<0||y>w)return ;
    if(mp[x][y]=='.')return ;
    if(ans==1)return ;
    if(x==h-1&&y==w-1&&check()){
        ans=1;
        return ;
    }
    mp2[x+1][y]='#';
    dfs(x+1,y);
    mp2[x+1][y]='.';

    mp2[x][y+1]='#';
    dfs(x,y+1);
    mp2[x][y+1]='.';
}
int main(){
    while(scanf("%d%d",&h,&w)==2){
        ans=0;
        for(int i=0;i<h;i++){
            scanf("%s",mp[i]);
        }
        memset(mp2,'.',sizeof(mp2));
        mp2[0][0]='#';
        dfs(0,0);
        if(ans==1){
            puts("Possible");
        }else puts("Impossible");
    }
return 0;
}