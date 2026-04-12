#include<stdio.h>

int main(){
  int N;
  scanf("%d",&N);
  int H[N];
  for(int i= 0; i<N;i++){
    scanf("%d",&H[i]);
  }
  int high = 0;
  int ryo = 0;
  for(int i = 0;i < N;i++){
    if(H[i] >= high){
      high = H[i];
      ryo++;
    }
  }
  printf("%d",ryo);
}
    