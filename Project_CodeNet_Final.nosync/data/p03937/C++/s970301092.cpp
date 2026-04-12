#include <cstdio>
#include <algorithm>
using namespace std;
char str[10][10]={};
int main(){
  int h,w,x=1,y=1;
  scanf("%d %d",&h,&w);
  for(int i=1;i<=h;i++){
    scanf("%s",str[i]+1);
  }
  do{
    str[y][x]='.';
    if(str[y][x+1]=='#'){
      x++;
    }
    else if(str[y+1][x]=='#'){
      y++;
    }
    else{
      printf("Impossible");
      return 0;
    }
  }while(x!=w||y!=h);
  str[h][w]='.';
  for(int i=1;i<=h;i++){
    for(int j=1;j<=w;j++){
      if(str[i][j]=='#'){
        printf("Impossible");
        return 0;
      }
    }
  }
  printf("Possible");
  return 0;
}
