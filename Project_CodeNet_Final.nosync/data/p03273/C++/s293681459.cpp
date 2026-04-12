#include <stdio.h>
#define N 101
int main(){
  char a[N][N]={};
  int h,w,i,j,hf[N]={},wf[N]={};
  scanf("%d%d",&h,&w);
  for(i=0;i<h;i++){
    scanf("%s",a[i]);
  }
  for(i=0;i<h;i++){
    for(j=0;j<w;j++){
      if(a[i][j]=='#'){
        hf[i]=1;
        wf[j]=1;
      }
    }
  }
  for(i=0;i<h;i++){
    for(j=0;j<w;j++){
      if(hf[i]==1 && wf[j]==1){
        printf("%c",a[i][j]);
      }
    }
    if(hf[i]==1){
      printf("\n");
    }
  }
  return 0;
}
