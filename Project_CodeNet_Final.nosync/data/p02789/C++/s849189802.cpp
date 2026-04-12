#include <stdio.h>
int main(){
  int N,M;

  scanf("%d %d",&N, &M);

  if((N >= 1 && N <= 100) && (N == M)){
    printf("Yes\n");
  }else{
    printf("No\n");
  }
    
  return 0;
}
