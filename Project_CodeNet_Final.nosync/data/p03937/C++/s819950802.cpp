#include <iostream>
#include <cstdio>
using namespace std;
int h,w;
int m[10][10];
int main(void){
   scanf("%d%d",&h,&w);
   for(int i=0;i<h;i++){
       for(int j=0;j<w;j++){
           char c;
           scanf(" %c",&c);
           if(c=='#')m[i][j]=1;
       }
   }
   bool ok=true;
   int x=0,y=0;
    while(ok){
        m[y][x]=0;
        if(x==w-1&&y==h-1)break;
        if(y+1<h&&m[y+1][x]==1){
            if(x+1<w&&m[y][x+1]==1)ok=false;
            else y++;
        }else if(x+1<w&&m[y][x+1]==1){
            if(y+1<h&&m[y+1][x]==1)ok=false;
            else x++;
        }else ok=false;
    }
    for(int i=0;i<h&&ok;i++){
        for(int j=0;j<w&&ok;j++){
            if(m[i][j])ok=false;
        }
    }
    if(ok)printf("Possible\n");
    else printf("Impossible\n");
}
