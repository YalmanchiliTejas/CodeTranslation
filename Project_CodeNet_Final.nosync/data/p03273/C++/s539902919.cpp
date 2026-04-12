#include <stdio.h>

int main(void){
  int h , w;
  scanf("%d %d",&h,&w);
  
  char  a[h][w];
  int cuth[100] = {0}, cutw[100] = {0};
 
  for(int i = 0;i < h;i ++){
    scanf("%s",a[i]);
  }
  
  for(int i = 0;i < h;i ++){
    int j = 0;
    while(j < w){
      if(a[i][j]=='.'){
        cuth[i] ++;
      }
      j ++;
    }
    cuth[i+1] = 0;
  }
  for(int i = 0;i < w;i ++){
    int j = 0;
    while(j < h){
      if(a[j][i]=='.'){
        cutw[i]++;
      }
      j ++;
    }
   cutw[i+1] = 0;
  }
  
  for(int i = 0;i < h;i ++){
    for(int j = 0;j < w;j ++){
      if(cuth[i]!=w&&cutw[j]!=h){
        printf("%c",a[i][j]);
      }
    }
    if(cuth[i]!=w){
     putchar('\n');
    }
  }

  return 0;
}