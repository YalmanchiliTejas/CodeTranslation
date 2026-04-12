#include<stdio.h>

int can_view(int N,int *H){
  int i,j,result=0,frag=1; 
  for(i=0;i<N;i++){
    frag = 1;
    if(i==0){
      result++;
    }else{
      for(j=i-1;j>=0;j--){
	if(H[j] > H[i]){
	  frag = 0;
	  break;
	}
      }
      if(frag){
	result ++;
      }
    }
  }
  return result;
}
  


int main(){
  int N,i;
  int H[20];
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&H[i]);
  }
  printf("%d\n",can_view(N,H));
  return 0;
}