#include <cstdio>

char grid[10][10];

int main(){
  int H,W;
  int cnt=0;
  scanf("%d %d",&H,&W);
  for(int i=0;i<H;i++){
    scanf("%s",grid[i]);
    for(int j=0;j<W;j++){
      cnt+=(grid[i][j]=='#');
    }
  }
  if(cnt==H+W-1){
    printf("Possible\n");
  }else{
    printf("Impossible\n");
  }
  return 0;
}
