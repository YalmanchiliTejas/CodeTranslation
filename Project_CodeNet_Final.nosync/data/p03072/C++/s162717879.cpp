#include<stdio.h>
int main(){
  int N,V=1,Vq;
  int H[20];
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&H[i]);
  }
  for(int i=1;i<N;i++){
    int j=0;
    Vq=1;
    while(j<i){
      if(H[i]<H[j]){
        Vq=0;
        break;
      }
      j++;
    }
    V+=Vq;
  }
  printf("%d\n",V);
  return 0;
}